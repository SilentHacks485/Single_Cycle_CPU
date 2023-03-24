#include "register.h"

bool regist::RegWrite(uint64_t input){

    reg[pc_count] = input;
    return true;

}