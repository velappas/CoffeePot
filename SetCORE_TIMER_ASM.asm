/*
 * SetCORE_TIMER_ASM.asm
 *
 *  Created on: Nov 22, 2017
 *      Author: velappas
 */
 #include <blackfin.h>

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _SetCORE_TIMER_ASM;
_SetCORE_TIMER_ASM:
 	LINK 16;
 	
 #define _TSCALE 0xFFE03008
 #define _TCOUNT 0xFFE0300C
 #define _TCNTL 0xFFE03000
 #define _TPERIOD 0xFFE03004
 
 	R0.H = hi(0x0000);
 	R0.L = lo(0x2000);
	P0.L = lo(_TPERIOD);	
    P0.H = hi(_TPERIOD);  
    W[P0] = R0; 	
   
 	R1.H = hi(0x0000);
 	R1.L = lo(0x4000);
	P1.L = lo(_TCOUNT);	
    P1.H = hi(_TCOUNT);  
    W[P1] = R1; 	
    
    R2.H = hi(0x0000);
 	R2.L = lo(0x0003);
	P2.L = lo(_TCNTL);	
    P2.H = hi(_TCNTL);  
    W[P2] = R2; 	
   
    R3.H = hi(0x0000);
 	R3.L = lo(0x0000);
	P3.L = lo(_TSCALE);	
    P3.H = hi(_TSCALE);  
    W[P3] = R3; 	
    
    SSYNC;



 	UNLINK;
_SetCORE_TIMER_ASM.END:
 	RTS;
