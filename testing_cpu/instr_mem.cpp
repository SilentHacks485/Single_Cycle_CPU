//
// Created by Dale Scicluna on 15/04/2023.
//

#include "instr_mem.h"
#include <sstream>
#include <iostream>
#include <fstream>


uint32_t instr_memory :: fetch_instruction(uint64_t address){
    return instruction[address];
}

void instr_memory :: write_instruction(uint64_t address , uint64_t data){
    instruction[address] = data;

}

uint64_t instr_memory :: line_handler(string line){

    int size = line.length();
    uint32_t hex_interpreter;

    for(int i =0 ; i<size ; i++){
        if(line[i] == ' '){
            line.replace(i , 1 , "");
        }
    }
    std::stringstream ss;

    ss << hex << line;
    ss >> hex_interpreter;

    return hex_interpreter;
}

void instr_memory :: readFile(string path){

    string line;
    ifstream myfile;

    int count = 0;

    myfile.open(path , ios::in);

    line_count = myfile.tellg();
    if(myfile.is_open()){
        while(getline(myfile , line)){
            line.resize(11);

            //word 4 is 8
            write_instruction(count , line_handler(line));
            count +=1;

        }
    }else{
        cout << "Instruction File Read Error" << endl;
    }

    line_count = count;
    myfile.close();
}