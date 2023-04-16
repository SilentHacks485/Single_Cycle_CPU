//
// Created by Dale Scicluna on 16/04/2023.
//


#include "signExtend.h"
#include <iostream>
#include <bitset>
using namespace std;

int64_t signExtend::sign_extender(int32_t input) {

    int64_t extended = 0;

   // cout << input << endl;

    //we shift the 9 digits by 8 to leave out the sign bit
    int sign_bit = (input>>8);
   // std::cout << "sign " << (sign_bit) << std::endl;

    cout << bitset<9>(input) << endl;
    if(sign_bit == 1){
        //fill 64 bits with 1 bits and shift left by 9 to make space for input
        extended = (0xFFFFFFFFFFFFFFFF << 9) | input;
        //result will be the input but with 1 extended to the left
        //two's complement
    }else{

        extended = extended | input;

    }

   // std::cout << "sign " << std::bitset<64>(extended) << std::endl;

    return extended;
}