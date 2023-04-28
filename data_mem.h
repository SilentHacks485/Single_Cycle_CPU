//
// Created by Dale Scicluna on 15/04/2023.
//
#include <string>
#include <bitset>
#include <iostream>

#ifndef TESTING_CPU_DATA_MEM_H
#define TESTING_CPU_DATA_MEM_H

using namespace std;

class data_mem {

public:

    int line_count;
    //data can be negative as well
    int64_t mem[1024];

    data_mem(string path){
        for (int i = 0; i < 1024; i++){
            mem[i] = 0;
        }
        readFile(path);
    }

    data_mem(){

        for (int i = 0; i < 1024; i++){
            mem[i] = 0;
        }
    }

    //if data can be negative , its also possible to return negative data
    int64_t read_memory(uint64_t address);

    void write_memory(uint64_t address , int64_t data);

    uint64_t line_handler(string line);

    //read . data files function
    void readFile(string path);

    void save_memory(string path);

    void display_memory_content();

    void clear_file(string path);

    void data_dump(string path);

};


#endif //TESTING_CPU_DATA_MEM_H
