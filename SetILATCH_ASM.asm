/*
 * SetILATCH_ASM.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: velappas
 */
 #include <blackfin.h>

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _SetILATCH_ASM;
_SetILATCH_ASM:
 	LINK 16;


 #define _ILAT 0xFFE0210C
 
	R0.H = hi(0x0000);
	R0.L = lo(0x1000);
	P0.L = lo(_ILAT);	
    P0.H = hi(_ILAT);  
    W[P0] = R0;    
   	SSYNC;


 	UNLINK;
_SetILATCH_ASM.END:
 	RTS;
