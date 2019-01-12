/*
 * MY_ISR.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: velappas
 */
 #include <blackfin.h>

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _My_ISR;
_My_ISR:
	[--SP] = ASTAT;
	[--SP] = FP;
	[--SP] = R7;
	[--SP] = R6;
	[--SP] = R5;
	[--SP] = P5;
	[--SP] = P4;
	[--SP] = P3;
 	LINK 16;
 	
 	
 	
 	
 	
 	
 	
 	
 #define _IMASK 0xFFE02104

	R0.H = hi(0x0000);
	R0.L = lo(0x1000);
	P0.L = lo(_IMASK);	
    P0.H = hi(_IMASK);  
    W[P0] = R0;    
   	SSYNC;
   	
   	


 	UNLINK;
 	P3 = [SP++];
 	P4 = [SP++];
 	P5 = [SP++];
 	R5 = [SP++];
 	R6 = [SP++];
 	R7 = [SP++];
 	FP = [SP++];
 	ASTAT = [SP++];
_My_ISR.END:
 	RTI;
