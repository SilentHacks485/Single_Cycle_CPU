#include <iostream>


class instr_memory{

   
    uint64_t pc_count = 0;

    uint64_t instruction_mem[64];
    uint64_t fetch(uint64_t reg[32] , int address);
    

   void pc_increase(void){

        pc_count++;

    }


};