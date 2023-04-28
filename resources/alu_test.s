.text
	
	ADDI X0 , XZR , #1
	ADD X1 , X1 , X0
	ADD X3 , X1 , X1
	ADD X4 , X3 , X1
	
	SUB X0 , X0 , X1
	SUB X3 , X1 , X2
	
	ORR X1 , X2 , X3

	AND X2 , X3 , X0
