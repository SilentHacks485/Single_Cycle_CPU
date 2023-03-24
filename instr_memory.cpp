#include <iostream>
#include "instr_memory.h"

 uint64_t instr_memory :: fetch(uint64_t reg[32], int address){

    pc_increase();
    return reg[address];

 }