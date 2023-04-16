//
// Created by Dale Scicluna on 15/04/2023.
//

#include <string>
#include <fstream>


#ifndef TESTING_CPU_CONTROL_H
#define TESTING_CPU_CONTROL_H

using namespace std;

class control {

public:

    //this array will only contain 1 and 0
    int control_bits[9];

    control(){
        for(int i =0 ; i< 9 ; i++){
            control_bits[i] = 0;
        }
    }

    void splitter(std::string binary);
    void print_controls(ofstream &file);
    void selector(char format);

};


#endif //TESTING_CPU_CONTROL_H
