.text

init:

ADDI X0 , XZR , #10
ADDI X1 , XZR , #1

loop:

     CBNZ X0 , subtractor
     ADDI X1 , X1 , #1
     CBZ X0, end
     

subtractor:

	SUBI X0 , X10, #1
	CBNZ X0 , loop
	CBZ X0 , end



end:
	ADDI X2 , X2 , #1


