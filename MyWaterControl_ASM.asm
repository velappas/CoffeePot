/*
 * My_CoffeePotFunctions_ASM.asm
 *
 *  Created on: Oct 29, 2017
 *      Author: velappas
 */
 #include <blackfin.h>
 
#define INPAR1_R0 R0
#define INPAR2_R1 R1
#define INPAR1_R4 R4
#define INPAR2_R5 R5
#define returnValue_R0 R0

#define waterControlOffset 7
#define baseAddress P0
#define waterLevel_R1 R1
#define temp_R2 R2


 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _MyWaterControlCode_ASM;
 _MyWaterControlCode_ASM:
    [--SP] = R4;						// Save arguments
    INPAR1_R4 = INPAR1_R0;
    [--SP] = R5;
    INPAR2_R5 = INPAR2_R1;
 	LINK 20;



	R0 = INPAR1_R4;
 	.extern __Z21CurrentWaterLevel_CPPP16COFFEEPOT_DEVICE;
 	CALL __Z21CurrentWaterLevel_CPPP16COFFEEPOT_DEVICE;     //waterLevel_R1 = CurrentWaterLevel_CPP(COFFEEPOT_DEVICE *baseAddress);
	waterLevel_R1 = returnValue_R0;
 	
 	
// fill water	
IF_:	
	CC =  waterLevel_R1 < INPAR2_R5; 					// if current waterLevel < waterLevelRequired
	IF !CC JUMP ELSE_;									// break if !C



	P0 = INPAR1_R4;									//coffeePot_BaseAddress->waterInFlowRegister = 20;
 	temp_R2 = 50;									// (water on)
	B[P0 + waterControlOffset] = temp_R2;	              
								

 	
	JUMP ENDIF_;											// go to the end
 	
ELSE_:								                  // current waterLevel >= waterLevelRequired

	P0 = INPAR1_R4;
 	temp_R2 = 0;									//coffeePot_BaseAddress->waterInFlowRegister = 0;
	B[P0 + waterControlOffset] = temp_R2;	        // (water off)
	
ENDIF_:
 	
 	UNLINK;
 	R5 = [SP++];
 	R4 = [SP++];
 _MyWaterControlCode_ASM.END:
 	RTS;

 