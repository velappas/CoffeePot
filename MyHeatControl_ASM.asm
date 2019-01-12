/*
 * MyHeatControl_ASM.asm
 *
 *  Created on: Oct 29, 2017
 *      Author: Victoria Lappas
 */
 

 #include <blackfin.h>
 
#define INPAR1_R0 R0
#define INPAR2_R1 R1
#define INPAR1_R4 R4
#define INPAR2_R5 R5
#define returnValue_R0 R0

#define heatControlOffset 6
#define baseAddress P0
#define waterTemperature_R1 R1
#define temp_R2 R2

 #define byte4 var
 	.section L1_data;
 
 .byte4 _staticVariable = 0;
 
 	.section program;
 
 
 .global _MyHeatControlCode_ASM;
_MyHeatControlCode_ASM:
    [--SP] = R4;
    INPAR1_R4 = INPAR1_R0;			// save arguments into R4 and R5
    [--SP] = R5;
    INPAR2_R5 = INPAR2_R1;
 	LINK 20;


	R0 = INPAR1_R4;
 	.extern __Z22CurrentTemperature_CPPP16COFFEEPOT_DEVICE;
 	CALL __Z22CurrentTemperature_CPPP16COFFEEPOT_DEVICE;     //waterTemperature_R1 = CurrentTemperature_CPP(COFFEEPOT_DEVICE *baseAddress);
	waterTemperature_R1 = returnValue_R0;
 	
 	
// heat	
IF_:	
	CC =  waterTemperature_R1 < INPAR2_R5;				// if waterTemperature < TemperatureRequired
	IF !CC JUMP ELSE;					                // go to ELSE if !CC
	
	P0 = INPAR1_R4;						    			//coffeePot_BaseAddress->heaterRegister = 150;
	temp_R2 = 150;										// (heat on)
	B[P0 + heatControlOffset] = temp_R2;			

 	
	JUMP ENDIF_;
 	
ELSE:

	P0 = INPAR1_R4;						    			//coffeePot_BaseAddress->heaterRegister = 0;
	temp_R2 = 0;										// (heat off)
	B[P0 + heatControlOffset] = temp_R2;		


ENDIF_:

 	UNLINK;
 	R5 = [SP++];
 	R4 = [SP++];
 _MyHeatControlCode_ASM.END:
 	RTS;
 	
 	
 	
 
 