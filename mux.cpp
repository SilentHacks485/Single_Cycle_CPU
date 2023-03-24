#include "mux.h"
#include <iostream>

uint64_t mux::multiplexer(uint8_t s , uint64_t input1 , uint64_t input2){

    if(s==0){

        return input2;

    }else{

        return input1;

    }


}