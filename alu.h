#include <iostream>

#ifndef ALU_H
#define ALU_H

class alu{

    public:

    uint64_t AND(int32_t input1 , int32_t input2);
    uint64_t OR(int32_t input1 , int32_t input2);
    uint64_t add(int32_t input1 , int32_t input2);
    uint64_t subtract(int32_t input1 , int32_t input2);
    uint64_t pass_input_b(int32_t input2);
    uint64_t NOR(int32_t input1 , int32_t input2);
    uint64_t cont(int8_t control, int32_t input1 , int32_t input2);

};

#endif