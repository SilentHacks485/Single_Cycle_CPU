//
// Created by Dale Scicluna on 15/04/2023.
//

#include "data_mem.h"
#include <string>
#include <bitset>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

void data_mem::write_memory(uint64_t address, int64_t data){


    mem[address] = data;

}

int64_t data_mem :: read_memory(uint64_t address){
    return mem[address];
}

void data_mem :: save_memory(string path){

    clear_file(path);
    ofstream file;
    file.open(path , ios::out | ios::app);
    if(file.is_open()){

        for (int i =0 ; i < 1024 ; i++){
            file << "Data Memory address [" << i << "] , Data : " << mem[i] << endl;
        }

    }else{
        cout << "Save Dump Error" << endl;
    }

}

void data_mem :: clear_file(string path){

    ofstream file;
    file.open(path , ios :: out);

    if (file.is_open()){

        file << "" ;

    }
}

//line hsndler is used to combine hexadecimal values by removing the sapce and using string stream function to
//interpret read data as a hex decimal

uint64_t data_mem :: line_handler(string line){

    int size = line.length();
    uint64_t hex_interpreter;

    for(int i =0 ; i<size ; i++){
        if(line[i] == ' '){
            line.replace(i , 1 , "");
        }
    }
    std::stringstream ss;

    ss << hex << line;
    ss >> hex_interpreter;

    return hex_interpreter;
}




void data_mem:: readFile(string path){

    string line;
    ifstream myfile;

    int count = 0;

    myfile.open(path , ios::in);

    if(myfile.is_open()){
        while(getline(myfile , line)){

            write_memory(count , line_handler(line));
            count +=1;

        }
    }else{
        cout << "Data File Read Error" << endl;
    }

    line_count = count;
    myfile.close();
}

//this function can be used for debbuging purposes , call this class to display data mem content , but since
//it is saved in a txt fil , there was no need for it

void data_mem::display_memory_content(){

    for(int i = 0; i<31 ; i++){

        cout << "mem " << i <<  " : " << mem[i] << endl;
    }

}


void data_mem::data_dump(string path){

    clear_file(path);
    ofstream file;
    file.open(path , ios::out | ios::app);
    if(file.is_open()){

        for (int i =0 ; i < 1024 ; i++){
             file << setfill('0') << std::setw(8) << std::hex <<  mem[i] << std::endl;
        }

    }else{
        cout << "Save Dump Error" << endl;
    }



}