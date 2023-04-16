//
// Created by Dale Scicluna on 15/04/2023.
//

#include "reg.h"

#include <string>
#include <sstream>
#include <bitset>

using namespace std;

int64_t reg :: read_register(uint64_t address){
    return regist[address];
}

void reg :: write_register(int64_t data , uint64_t address){
    if(address !=31) {
        regist[address] = data;
    }
}

//this function is essential to split the whole instruction into range of bits
string reg :: binary_split(string binary, int start , int end){
    string temp;
    uint32_t num;
    stringstream ss;
    for (int i = start ; i<=end ; i++){
        temp += binary[i];
    }
    return temp;
}


//this function is specifically build for R-format registers
string* reg :: r_placer(string binary){
    string* temp = new string[5];
    temp[0] = binary_split(binary , 0 ,10);
    temp[1] = binary_split(binary , 11 , 15);
    temp[2] = binary_split(binary , 16 , 21);
    temp[3] = binary_split(binary , 22 , 26);
    temp[4] = binary_split(binary , 27 , 31);
    return temp;
}


//this function is specifically build for D-format registers

string* reg :: d_placer(string binary){
    string *temp = new string[5];
    temp[0] = binary_split(binary, 0 , 10);
    temp[1] = binary_split(binary , 11 , 19);
    temp[2] = binary_split(binary , 20 , 21);
    temp[3] = binary_split(binary , 22 , 26);
    temp[4] = binary_split(binary , 27 , 31);
    return temp;
}


string *reg :: cb_placer(string binary){
    string *temp = new string[3];
    temp[0] = binary_split(binary , 0, 7);
    temp[1] = binary_split(binary , 8 , 26);
    temp[2] = binary_split(binary , 27 , 31);
    return temp;
}


//inputting register sturcture to file
void reg :: r_display(string *array , ofstream& file){

    file << "----------------------------" << endl;
    file << "R-FORMAT : " << endl;
    file << "opcode : " << array[0] << endl;
    file << "Rm : " << array[1] << endl;
    file << "Shamt :" << array[2] << endl;
    file << "Rn : " << array[3] << endl;
    file << "Rd :" << array[4] << endl;
    file << "----------------------------" << endl;

}

void reg :: d_display(string *array , ofstream& file){

    file << "----------------------------" << endl;
    file << "D-FORMAT :" << endl;
    file << "opcode : " << array[0] << endl;
    file << "address : " << array[1] << endl;
    file << "op :" << array[2] << endl;
    file << "Rn : " << array[3] << endl;
    file << "Rt :" << array[4] << endl;
    file << "----------------------------" << endl;

}

void reg :: cb_display(string *array , ofstream& file){

    file << "----------------------------" << endl;
    file << "CB-FORMAT :" << endl;
    file << "opcode : " << array[0] << endl;
    file << "address : " << array[1] << endl;
    file << "Rt : " << array[2] << endl;
    file << "----------------------------" << endl;
}

//save register content to file
void reg::print_register_content(ofstream& file){
    int i =0;
    while(i<32){
        file << "Register " << i << " : " << regist[i] << endl;
        i++;
    }
}

