//
// Created by Dale Scicluna on 15/04/2023.
//


#include "alu.h"
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int64_t alu:: AND (int64_t input1 , int64_t input2){

    return input1 & input2;

}


int64_t alu :: OR (int64_t input1 , int64_t input2){

    return input1 | input2 ;

}

int64_t alu:: add (int64_t input1 , int64_t input2){

    return input1 + input2;

}

int64_t alu::subtract (int64_t input1 , int64_t input2){

    return input1 - input2;

}


int64_t alu :: pass_input_b (int64_t input2){

    return input2;

}

int64_t alu :: NOR (int64_t input1 , int64_t input2){

    return ~(input1 | input2);

}

//alu controller
int64_t alu:: controller(int temp , int64_t input1 , int64_t input2){

    switch(temp){

        case 0:

            return AND(input1 , input2);

            break;

        case 1 :

            return OR(input1 , input2);

            break;

        case 2:

            return add(input1 , input2);

            break;

        case 6 :

            return subtract(input1 , input2);

            break;

        case 7:

            return pass_input_b(input2);

            break;

        case 12:

            return NOR(input1 , input2);

            break;

        default:

            return 0;
            break;
    }
}




void alu::alu_test_bench(int temp , int64_t input1 , int64_t input2){

    cout << (bitset<4>)input1 << endl;
    cout << (bitset<4>)input2 << endl;
    cout << "ALU Result: " << (bitset<4>)controller(temp , input1 , input2)<< endl;

}
