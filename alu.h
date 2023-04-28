//
// Created by Dale Scicluna on 15/04/2023.
//
#include <iostream>
#include <string>

#ifndef TESTING_CPU_ALU_H
#define TESTING_CPU_ALU_H

using namespace std;

class alu{

public:

    int64_t AND(int64_t input1 , int64_t input2);
    int64_t OR(int64_t input1 , int64_t input2);
    int64_t add(int64_t input1 , int64_t input2);
    int64_t subtract(int64_t input1 , int64_t input2);
    int64_t pass_input_b(int64_t input2);
    int64_t NOR(int64_t input1 , int64_t input2);
    int64_t controller(int temp , int64_t input1 , int64_t input2);

    //debuging purposes
    void alu_test_bench(int temp , int64_t input1 , int64_t input2);

};


#endif //TESTING_CPU_ALU_H
