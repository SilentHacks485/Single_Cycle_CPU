//
// Created by Dale Scicluna on 15/04/2023.
//
#include <iostream>
#include <bitset>
#include <string>
#include <fstream>


#ifndef TESTING_CPU_REG_H
#define TESTING_CPU_REG_H

#define REGISTER_SIZE 32
#define XRZ 0

using namespace std;

class reg {

public:

    int64_t regist[32];
    uint32_t register_structure[5];

    reg() {
        regist[ 31 ] = XRZ;
        for ( int i = 0; i < 31; i++ ) {
            regist[i] = 0;
        }
    }

    int64_t read_register(uint64_t address);

    void write_register(int64_t data, uint64_t address);

    string binary_split(string binary, int start, int end);

    string *r_placer(string binary);

    string *d_placer(string binary);

    string *cb_placer(string binary);

    string *i_placer(string binary);

    void print_register_content(ofstream &file);

    void r_display(string *array, ofstream &file);

    void d_display(string *array, ofstream &file);

    void cb_display(string *array, ofstream &file);

    void i_display(string *array, ofstream &file);

    void display_register_content();

};

#endif //TESTING_CPU_REG_H
