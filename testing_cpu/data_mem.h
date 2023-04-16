//
// Created by Dale Scicluna on 15/04/2023.
//
#include <string>
#include <bitset>
#include <string>
#include <iostream>
#include <string>


#ifndef TESTING_CPU_DATA_MEM_H
#define TESTING_CPU_DATA_MEM_H

using namespace std;

class data_mem {

public:

    //data can be negative as well
    int64_t mem[1024];

    data_mem(){
        for (int i = 0; i < 1024; i++){
            mem[i] = 0;
        }
    }

    //if data can be negative , its also possible to return negative data
    int64_t read_memory(uint64_t address);

    void write_memory(uint64_t address , int64_t data);

    void save_memory(uint64_t address , int64_t data , string path);
};


#endif //TESTING_CPU_DATA_MEM_H
