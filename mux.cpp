//
// Created by Dale Scicluna on 15/04/2023.
//

#include "mux.h"

uint64_t mux::multiplexer(uint8_t s , uint64_t input1 , uint64_t input2){

    if(s==0){
        return input1;
    }else{
        return input2;

    }

}
