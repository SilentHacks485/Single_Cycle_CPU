//
// Created by Dale Scicluna on 15/04/2023.
//

#include "data_mem.h"
#include <fstream>


void data_mem::write_memory(uint64_t address, int64_t data){


    mem[address] = data;
    save_memory(address , data , "C:/Users/scicl/OneDrive/Desktop/testing_cpu/data_dump.txt");
}

int64_t data_mem :: read_memory(uint64_t address){
    return mem[address];
}

void data_mem :: save_memory(uint64_t address ,  int64_t data , string path){

    ofstream file;
    file.open(path , ios::out | ios::app);
    if(file.is_open()){
        file << "address : " << (bitset<64>)address  << ", data : " << data << endl;
        file.close();
    }else{
        cout << "error" << endl;
    }

}

