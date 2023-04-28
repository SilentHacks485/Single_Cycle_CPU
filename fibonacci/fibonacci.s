.text

//index
ADDI X21 , XZR , #14

//first
ADDI X22 , XZR , #0

//second
ADDI X23 , XZR , #1

STUR X22 , [XZR , #0]
STUR X23 , [XZR , #8]

//initialize result
ADDI X24 , XZR, #0

//offset
ADDI X9 , XZR , #16

main:

	//result = first + second
	ADD X24 , X23  , X22
	
	//first = second
	ADD X22 , XZR , X23
	
	//second = result;
	ADD X23 , XZR  , X24
    
        //STUR RESULT IN REGISTER
	STUR X24 , [X9 , #0]
	
	//if not 0 , subtract index
	CBNZ X21 , subtractor
	
	//if 0 , end program
	CBZ X21 , end
	 

subtractor:

	//subtract index
	SUBI X21 , X21 , #1
	ADDI X9 , X9 , #8
	
	//go back to the main branch
	CBNZ X21 , main

end:

    ADDI X21 , XZR ,  #0
    ADDI X22 , XZR , #0
    ADDI X23  ,XZR , #0
    ADDI X24 , XZR , #0






//int main()
//{
  //int n, first = 0, second = 1, result, i;
  //printf("Please give an input upto you want to print series :");
  //scanf("%d", &n);
  //printf("Fibonacci Series is: \n");
  //for (i = 0; i < n; i++)
  //{
    //if (i <= 1)
      //result = i;
    //else
    //{
     // result = first + second;
      //first = second;
      //second = result;
    //}
    //printf("%d \n", result);
  //} 
  //return 0;
//} 
