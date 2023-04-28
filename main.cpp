//standard library
#include <iostream>
#include <string>


//components created
#include "mux.h"
#include "instr_mem.h"
#include "control.h"
#include "pc.h"
#include "reg.h"
#include "alu.h"
#include "data_mem.h"
#include "signExtend.h"


//border for file saving purposes
#define border "------------------------"

using namespace std;


//remove exitsting data on datapath output
void clear_file(string path) {
    ofstream file;
    file.open(path, ios::out);
    file << "";
    file.close();
}

//this function will output to datapath txt all result in a structural manner
void display_order(pc *p, control *c, reg *r, ofstream &file, string *hold, string str_ins, int64_t data, int64_t data2,
                   int64_t alu_result, int64_t sign_extended, string opcode, string b_opcode, string i_opcode);


int main() {

    //allocating heap size to the components
    pc *p = new pc();
    reg *r = new reg();
    control *c = new control();
    mux *m = new mux();
    alu *h = new alu();
    signExtend *s = new signExtend();


    //contain instruction bits that have ben split and structured in their respective registers
    string *hold = new string[5];
    string str_ins, file_path1, file_path2, path, opcode, b_opcode, i_opcode;
    int64_t data = 0, data2 = 0, sign_extended = 0, alu_result = 0;

    cout << "Enter file path for text file" << endl;
    cin >> file_path1;
    cout << "Enter file path for data file , if no data file is required enter 0" << endl;
    cin >> file_path2;
    path = "./output/datapath.txt"; //path for output

    //create or clear file
    clear_file(path);

    instr_memory *mem = new instr_memory(file_path1);  //call constructor with string argument to specify file to read
    data_mem *d;

    //in case no .data file is needed
    //the user won't be forced to enter a valid url
    if ( file_path2 == "0" ) {
        d = new data_mem();
    } else {
        d = new data_mem(file_path2);
    }

    ofstream file;
    file.open(path, ios::out | ios::app);

    if ( file.is_open()) {

        while ( p->get_pc() < mem->line_count ) {

            file << border << endl;
            file << "pc word address : " << p->get_pc() << endl;
            // file << "pc byte address : " << p->get_pc() * 4<< endl;
            file << border << endl;

            str_ins = ((bitset<32>) (mem->fetch_instruction(p->get_pc()))).to_string();
            //this will be use to deocde opocode
            //i am grapping different size of the same opcode to be used to determine opcode
            opcode = str_ins.substr(0, 11);
            b_opcode = str_ins.substr(0, 8);
            i_opcode = str_ins.substr(0, 10);

            //decode

            if ( opcode == "10001010000" || opcode == "10001011000" || opcode == "10101010000" ||
                 opcode == "11001011000" ) {

                c->selector('r');
                hold = r->r_placer(str_ins);
                data = r->read_register(stoull(hold[ 1 ], 0, 2));
                data2 = r->read_register(stoull(hold[ 3 ], 0, 2));

                //D-FORMAT OPCODE STUR , LDUR
            } else if ( opcode == "11111000000" || opcode == "11111000010" ) {

                hold = r->d_placer(str_ins);
                //decode opcode and determine control bit
                switch ( stoull(hold[ 0 ], 0, 2)) {
                    case 1986:
                        //select ldur control bits
                        c->selector('l');
                        break;
                    case 1984:
                        //select stur control bits
                        c->selector('s');
                        break;
                    default:
                        break;
                }
                //variales that contain sign extended equivalent of DT address
                sign_extended = s->sign_extender(stoul(hold[ 1 ], 0, 2), 10);
                //read data from registers
                data = r->read_register(stoull(hold[ 3 ], 0, 2));

                //ALU Src
                //determine if sign extend value is needed for stur and ldur
                data2 = m->multiplexer(c->control_bits[ 1 ], r->read_register(stoull(hold[ 4 ], 0, 2)), sign_extended);

            } else if ( b_opcode == "10110100" || b_opcode == "10110101" ) {

                c->selector('c');
                hold = r->cb_placer(str_ins);
                data = r->read_register(stoul(hold[ 2 ], 0, 2));
                sign_extended = s->sign_extender(stoul(hold[ 1 ], 0, 2), 19);

            } else if ( i_opcode == "1001000100" || i_opcode == "1101000100" ) {

                c->selector('r');
                hold = r->i_placer(str_ins);
                data = r->read_register(stoull(hold[ 2 ], 0, 2));
                data2 = 0;
                sign_extended = s->sign_extender(stoul(hold[ 1 ], 0, 2), 12);
            }

            //alu operation
            //determing alu operation required for different opcodes
            switch ( stoull(hold[ 0 ], 0, 2)) {
                //ADD
                case 1112:
                    alu_result = h->controller(2, data, data2);
                    r->write_register(alu_result, stoull(hold[ 4 ], 0, 2));
                    break;

                    //SUB
                case 1624:
                    alu_result = h->controller(6, data, data2);
                    r->write_register(alu_result, stoull(hold[ 4 ], 0, 2));
                    break;

                    //AND
                case 1360:
                    alu_result = h->controller(0, data, data2);
                    r->write_register(alu_result, stoull(hold[ 4 ], 0, 2));
                    break;

                    //ORR
                case 1104:
                    alu_result = h->controller(1, data, data2);
                    r->write_register(alu_result, stoull(hold[ 4 ], 0, 2));
                    break;

                    //LDUR
                case 1986:
                    //select ldur control bits
                    alu_result = h->controller(2, data, data2);
                    break;

                    //STUR
                case 1984:
                    //select stur control bits
                    alu_result = h->controller(2, data, data2);
                    break;

                    //CBZ
                case 180:

                    //if data in register is 0 , jump to address indicated
                    if ( data == 0 ) {
                        alu_result = h->controller(2, sign_extended, p->get_pc());
                        //the -1 is there because each iteration has a pc incrementor so in order to obtain the result i want with out being effected by the incrementor , the -1 was essential in this case
                        p->set_pc(alu_result - 1);

                    }

                    break;

                    //CBNZ
                case 181:

                    if ( data != 0 ) {
                        alu_result = h->controller(2, sign_extended, p->get_pc());
                        //the -1 is there because each iteration has a pc incrementor so in order to obtain the result i want with out being effected by the incrementor , the -1 was essential in this case
                        p->set_pc(alu_result-1);

                    }
                    break;

                    //ADDI
                case 580:
                    alu_result = h->controller(2, data, sign_extended);
                    r->write_register(alu_result, stoul(hold[ 3 ], 0, 2));
                    break;

                    //SUBI
                case 836:
                    alu_result = h->controller(6, data, sign_extended);
                    r->write_register(alu_result, stoul(hold[ 3 ], 0, 2));
                    break;

                default:
                    break;
            }


            //MemWrite
            if ( c->control_bits[ 5 ] != 0 ) {
                d->write_memory(alu_result / 8, r->read_register(stoull(hold[4], 0, 2)));
            }

            //MemToReg

            if ( c->control_bits[ 2 ] != 0 ) {
                r->write_register(d->read_memory(alu_result / 8), stoull(hold[ 4 ], 0, 2));
            }

            display_order(p, c, r, file, hold, str_ins, data, data2, alu_result, sign_extended, opcode, b_opcode,
                          i_opcode);


           p->pc_increment();

        }


    } else {
        cout << "Error opening / creating text file" << endl;
    }
    //dump data from memory to textfile
    d->save_memory("./output/dataMemContent.text");
    d->data_dump("./output/dataDump.DTDUMP");

    file.close();
}


void display_order(pc *p, control *c, reg *r, ofstream &file, string *hold, string str_ins, int64_t data, int64_t data2,
                   int64_t alu_result, int64_t sign_extended, string opcode, string b_opcode, string i_opcode) {


    file << "Instruction : " << str_ins << endl;

    file << border << endl;

    c->print_controls(file);
    //decoding required
    if ( opcode == "10001010000" || opcode == "10001011000" || opcode == "10101010000" || opcode == "11001011000" ) {
        r->r_display(hold, file);
    } else if ( opcode == "11111000000" || opcode == "11111000010" ) {
        r->d_display(hold, file);
    } else if ( b_opcode == "10110100" || b_opcode == "10110101" ) {
        r->cb_display(hold, file);
    } else if ( i_opcode == "1001000100" || i_opcode == "1101000100" ) {
        r->i_display(hold, file);
    }

    file << "Data in register 1: " << data << endl;
    file << "Data in register 2: " << data2 << endl;
    file << border << endl;

    //sign-extended value
    file << "Sign_extended Value : " << sign_extended << endl;
    file << border << endl;

    file << "Alu result : " << alu_result << endl;
    file << border << endl;

    r->print_register_content(file);

}