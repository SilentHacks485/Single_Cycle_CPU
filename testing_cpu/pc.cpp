//
// Created by scicl on 13/04/2023.
//

#include "pc.h"


void pc::pc_increment(){
    pc_count += 1;
}

uint64_t pc::get_pc(){
    return pc_count;
}

void pc::set_pc(int64_t input){

    pc_count = input;
}


