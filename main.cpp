#include <iostream>
#include <bitset>
#include "alu.h"

using namespace std;

void alu_test_bench(alu h ,int control , int32_t input1 , int32_t input2);


int main(void){

 alu h;

 int32_t input1 = 0b0100;   
  
 int32_t input2 = 0b0010;


 alu_test_bench(h, 1 , input1 , input2);


 alu_test_bench(h , 12 , input1 , input2);


}



void alu_test_bench(alu h ,int control , int32_t input1 , int32_t input2){


    //cout << (bitset<4>)input1 << endl;
    //cout << (bitset<4>)input2 << endl;
    
    cout << input1 << endl;
    cout <<  input2 << endl;
    cout << "result: " << (bitset<64>)h.cont(control , input1 , input2)<< endl;
    

}
