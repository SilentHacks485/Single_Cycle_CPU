//
// Created by Dale Scicluna on 15/04/2023.
//

#include "control.h"
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void control::splitter(string binary){

    for(int i =0 ; i<binary.length() ; i++){
        if(binary[i] == '1'){
            control_bits[i] = 1;
        }else{
            control_bits[i] = 0;
        }

    }

    cout << "" << endl;

}

void control::selector(char format){

    switch(format){
        case 'r':
            splitter("000100010");
            break;
        case 'l':
            splitter("011110000");
            break;
        case 's':
            splitter("110001000");
            break;

        case 'c':
            splitter("100000101");
            break;
        default: break;
    }
}

void control::print_controls(ofstream &file){
    file << "Control Bits : " << endl;
    file << "Reg2Loc : " << control_bits[0] << endl;
    file << "ALUSrc : " << control_bits[1] << endl;
    file << "MemtoReg : " << control_bits[2] << endl;
    file << "RegWrite : " << control_bits[3] << endl;
    file << "MemRead : " << control_bits[4] << endl;
    file << "MemWrite : " << control_bits[5] << endl;
    file << "Branch : " << control_bits[6] << endl;
    file << "ALUOp1 : " << control_bits[7] << endl;
    file << "ALUOp1 : " << control_bits[8] << endl;
}
