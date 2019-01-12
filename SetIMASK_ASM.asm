/*
 * setIMASK_ASM.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: Victoria Lappas
 */
 #include <blackfin.h>

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _SetIMASK_ASM;
_SetIMASK_ASM:
 	LINK 16;
 	
 #define _IMASK 0xFFE02104

	R0.H = hi(0x0000);
	R0.L = lo(0x1000);
	P0.L = lo(_IMASK);	
    P0.H = hi(_IMASK);  
    W[P0] = R0;    
   	SSYNC;
   	
   	


 	UNLINK;
_SetIMASK_ASM.END:
 	RTS;
