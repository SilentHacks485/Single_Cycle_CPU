#include "instr_mem.h"
#include <iostream>
#include <bitset>
#include <string>
#include <stdio.h>

//components
#include "mux.h"
#include "instr_mem.h"
#include "control.h"
#include "pc.h"
#include "reg.h"
#include "alu.h"
#include "data_mem.h"
#include "signExtend.h"

#define border "----------------------------"

using namespace std;

void clear_file(string path){


    //this function will be used to either clear the data from a file , or to make sure the file created is empty
    ofstream file;
    file.open(path , ios::out);
    file << "" << endl;
    file.close();
}

int main(void){

    pc *p = new pc();
    reg *r = new reg();
    control *c = new control();
    mux *m = new mux();
    alu *h = new alu();
    data_mem *d = new data_mem();
    instr_memory *mem = new instr_memory("C:/Users/scicl/OneDrive/Desktop/testing_cpu/sumtwo.text");
    signExtend *s = new signExtend();

    string path = "C:/Users/scicl/OneDrive/Desktop/testing_cpu/datapath.txt";

    string *hold = new string[5];

    int64_t data = 0;
    int64_t data2 = 0;
    uint64_t alu_result = 0;

    bitset<32> bit_instruction;
    string str_ins;


    clear_file(path);

    ofstream file;
    file.open(path , ios::out | ios::app);


    if(file.is_open()) {

        r->write_register(1 , 1);
        r->write_register(1, 2);

        while (p->get_pc() < mem->line_count){

            file << border << endl;
            file << "pc : " << p->get_pc() << endl;
            file.seekp(4, ios::beg);
            //cout << bitset<32>(mem->fetch_instruction(p->get_pc())) << endl;
            bit_instruction = (bitset<32>)(mem->fetch_instruction(p->get_pc() ));
            str_ins = bit_instruction.to_string();


            file << border << endl;
            file << "Instruction : " << bit_instruction << endl;

            // R-FORMAT
            //not all r-format instruction have the same datapath
            if (str_ins.find("10001010000") != string::npos ||
                str_ins.find("10001011000") != string::npos ||
                str_ins.find("10101010000") != string::npos ||
                str_ins.find("11001011000") != string::npos) {

                c->selector('r');
                file << border << endl;
                c->print_controls(file);

                //since the above opcodes are r registers

                hold = r->r_placer(str_ins);
                data = r->read_register(stoull(hold[1], 0, 2));
                data2 = r->read_register(stoull(hold[3], 0, 2));

                switch (stoull(hold[0], 0, 2)) {
                    case 1112:
                        alu_result = h->controller(2, data, data2);
                        break;
                    case 1624:
                        alu_result = h->controller(6, data, data2);
                        break;
                    case 1360:
                        alu_result = h->controller(0, data, data2);
                        break;
                    case 1104:
                        alu_result = h->controller(1, data, data2);
                        break;
                    default:
                        break;

                }

                r->r_display(hold, file);
                file << "Data 1 : " << data << endl;
                file << "Data 2 : " << data2 << endl;
                file << border << endl;

                //display alu result and input result into register Rd
                file << "ALU Result : " << alu_result << endl;
                file << border << endl;
                r->write_register(alu_result, stoull(hold[4], 0, 2));


            }else if(str_ins.find("11111000000") !=string::npos | str_ins.find("11111000010") != string::npos) {

                //place instruction of stur or ldur to the approprate register structure
                hold = r->d_placer(str_ins);

                switch (stoull(hold[0], 0, 2)){
                    case 1986:
                        c->selector('l');
                        break;

                    case 1984:
                        c->selector('s');
                        break;

                        default: break;
                }

                //displaying control bits and register structure

                int32_t address =  stoul(hold[1] , 0, 2);
                int64_t sign = s->sign_extender(address);
               // cout << sign << endl;


                data = r->read_register(stoull(hold[4] ,0 ,2));
                //this multiplexer will allow data2 to change depending on stur or ldur
                data2 = m->multiplexer(c->control_bits[1] , r->read_register(stoul(hold[3] , 0 ,2)) , sign);


                //displaying control bits
                file << border << endl;
                c->print_controls(file);
                r->d_display(hold , file);

                file << "Data 1 : " << data << endl;
                file << "Data 2 : " << data2 << endl;
                file << border << endl;

                //displaying alu result
                alu_result = h->controller(2, data, data2);
                file << "ALU Result : " << alu_result << endl;
                file << border << endl;

                cout << "con " << c->control_bits[5] << endl;
                //MemWrite
                if (c->control_bits[5]) {

                    d->write_memory(alu_result/8, data);
                }
                //MemToReg
                if (c->control_bits[2] !=0) {

                }


            }else if(str_ins.find("10110100") !=string::npos | str_ins.find("10110101") != string::npos) {

                c->selector('c');
                file << border << endl;
                c->print_controls(file);

                hold = r->cb_placer(str_ins);

                data = r->read_register(stoul(hold[1] ,0 , 2));


                r->cb_display(hold , file);
                //this is for cbz
                file << "Data : " << data << endl;
                file << border << endl;

                if(stoul(hold[0] ,0 , 2) == 180){

                    if (data == 0){
                        alu_result = h->controller(2 , p->get_pc() ,  s->sign_extender(stoull(hold[1] ,0 ,2)));
                        cout << alu_result << endl;
                    }
                }
            }
                p->pc_increment();
            r->print_register_content(file);
        }

    }
    file.close();
}