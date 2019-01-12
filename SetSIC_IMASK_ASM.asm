/*
 * SetSicImask_ASM.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: velappas
 */
 #include <blackfin.h>

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _SetSIC_IMASK_ASM;
_SetSIC_IMASK_ASM:
 	LINK 16;


 #define SIC_IMASK 0xFFC0010C
 
	R0.H = hi(0x0008);
	R0.L = lo(0x0000);
	P0.L = lo(SIC_IMASK);	
    P0.H = hi(SIC_IMASK);  
    W[P0] = R0;    
   	SSYNC;


 	UNLINK;
_SetSIC_IMASK_ASM.END:
 	RTS;
