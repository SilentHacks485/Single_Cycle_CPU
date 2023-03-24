#include <iostream>
#include <stdbool.h>

class regist{
    
    public:
    
    
    //register array
    uint64_t reg[32];

    regist(){

        for(int i= 0 ; i<32 ; i++){

            reg[i] = 0;
        
        }

    }

    bool RegWrite(uint64_t input , int pc_count);

};