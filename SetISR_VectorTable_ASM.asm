/*
 * SetISR_VectorTable_ASM.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: velappas
 */
 #include <blackfin.h>
 #include "MyCoffeePotFunctions.h"
 

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _SetISR_VectorTable_ASM;
_SetISR_VectorTable_ASM:
 	LINK 16;
 	
 #define EVT12_Table 0xFFE02030
 #define CORE_Table 0xFFE02018

	P0.L = lo(EVT12_Table);	
    P0.H = hi(EVT12_Table); 
    
    .extern _My_ISR; 
    
	R0.H = hi(_My_ISR);
	R0.L = lo(_My_ISR);
    W[P0] = R0;   
    
    
    P1.L = lo(CORE_Table);
    P1.H = hi(CORE_Table);
  	W[P0] = R0;
    
     
   	SSYNC;
   

 	UNLINK;
_SetISR_VectorTable_ASM.END:
 	RTS;
