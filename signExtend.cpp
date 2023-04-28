//
// Created by Dale Scicluna on 16/04/2023.
//

#include "signExtend.h"
#include <iostream>

using namespace std;

int64_t signExtend::sign_extender (int32_t input , int num_of_bits) {

    int64_t extended = 0;

    //we shift the n digits by n-1 to leave out the sign bit

    int32_t sign_bit = (input >> (num_of_bits - 1));

    if ( sign_bit == 1 ) {

        //fill 64 bits with 1 bit and shift left by num of bits to make space for input
        extended = ( 0xFFFFFFFFFFFFFFFF << num_of_bits ) | input;
        //result will be the input but with 1 extended to the left
        //two's complement
    } else {
        extended = extended | input;
    }


    return extended;
}