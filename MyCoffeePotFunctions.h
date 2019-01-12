/*
 * MyCoffeePotFunctions.h
 *
 *  Created on: Oct 28, 2017
 *      Author: Victoria Lappas
 *
 */

#ifndef MYCOFFEEPOTFUNCTIONS_H_
#define MYCOFFEEPOTFUNCTIONS_H_

#include <stdio.h>
#include "CoffeePot_SimulatorFunctions.h"
#include "sys/exception.h"


void My_SimulatedOneSecondPassing(bool showDetail);
void My_SimulatedOneSecondPassing_CPP(bool showDetail);

void My_DemonstrateCoffeePotAction(COFFEEPOT_DEVICE *coffeePot_BaseAddress1, char uniqueCoffeePotName1[],
unsigned short int waterLevelRequired1, unsigned short int waterTemperatureRequired1, COFFEEPOT_DEVICE *coffeePot_BaseAddress2,
char uniqueCoffeePotName2 [], unsigned short int waterLevelRequired2, unsigned short int waterTemperatureRequired2, COFFEEPOT_DEVICE *coffeePot_BaseAddress3,
char uniqueCoffeePotName3 [], unsigned short int waterLevelRequired3, unsigned short int waterTemperatureRequired3, COFFEEPOT_DEVICE *coffeePot_BaseAddress4,
char uniqueCoffeePotName4 [], unsigned short int waterLevelRequired4, unsigned short int waterTemperatureRequired4);

void My_MakeCoffeepot_ReadyForAction(COFFEEPOT_DEVICE *coffeePot_BaseAddress, char *uniqueCoffeePotName);
void MyWaterControlCode_CPP(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired);
void MyHeatControlCode_CPP(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterTemperatureRequired);
void MyWaterControlCode_CPP_SM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired);
void MyHeatControlCode_CPP_SM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterTemperatureRequired);
void Update(void);
void Simulate_Interrupt(void);
void my_ISR(void);

extern "C" void My_SimulatedOneSecondPassing_ASM(bool showDetail);

extern "C" void MyHeatControlCode_ASM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired);

extern "C" void MyWaterControlCode_ASM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired);

extern "C" void SetILATCH_ASM(void);

extern "C" void SetCORE_TIMER_ASM(void);

extern "C" void SetSIC_IMASK_ASM(void);

extern "C" void SetIMASK_ASM(void);

extern "C" void SetISR_VectorTable_ASM(void);


#endif /* MYCOFFEEPOTFUNCTIONS_H_ */
