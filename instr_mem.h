//
// Created by Dale Scicluna on 15/04/2023.
//

#include <string>

#ifndef TESTING_CPU_INSTR_MEM_H
#define TESTING_CPU_INSTR_MEM_H

using namespace std;

class instr_memory{

public:

    uint32_t instruction[1024];
    int line_count = 0;
    uint32_t fetch_instruction(uint64_t address);
    void write_instruction(uint64_t address , uint64_t data);
    uint32_t line_handler(string line);
    void readFile(string path);

    instr_memory(string path){

        //initialize memory to 0
        for(int i =0 ; i<1024; i++){
            instruction[i] = 0;
        }
        readFile(path);
    }
};

#endif //TESTING_CPU_INSTR_MEM_H
