#include "alu.h"

uint64_t alu:: AND (int32_t input1 , int32_t input2){

    return input1 & input2;

}


uint64_t alu :: OR (int32_t input1 , int32_t input2){

    return input1 | input2 ;

}

uint64_t alu:: add (int32_t input1 , int32_t input2){

    return input1 + input2;

}

uint64_t alu::subtract (int32_t input1 , int32_t input2){

    return input1 - input2;

}


uint64_t alu :: pass_input_b (int32_t input2){

  return input2;

}

uint64_t alu :: NOR (int32_t input1 , int32_t input2){

  return !(input1 | input2);

}

//alu controller
uint64_t alu:: cont(int8_t control, int32_t input1 , int32_t input2){

  if (control == 0){

    return AND(input1 , input2);

  }else if(control == 1){

    return OR(input1 , input2);

  }else if (control == 2){

    return add(input1 , input2);

  }else if(control == 6){

    return subtract(input1 , input2);

  }else if(control == 7){

    return pass_input_b(input2);

  }else if(control == 12){

    return NOR(input1 , input2);

  }else{

    return 0;
  }

}


