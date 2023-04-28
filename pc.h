//
// Created by Dale Scicluna on 15/04/2023.
//

#include <iostream>
#include <bitset>

#ifndef TESTING_CPU_PC_H
#define TESTING_CPU_PC_H

using namespace std;

class pc {

public :

    uint64_t pc_count;

    //constructor pc
    pc () {
        pc_count = 0;
    }

    void pc_increment ();

    uint64_t get_pc ();

    void set_pc(uint64_t input);

};


#endif //TESTING_CPU_PC_H
