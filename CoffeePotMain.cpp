/*
 * CoffeePotMain.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: Victoria Lappas
 *
 */
#include "MyCoffeePotFunctions.h"
#include <stdio.h>

int main(void) {

	printf("\n");
	printf("About to start my coffee pot simulator...\n");

	int numCoffeePots = 4;

	WHICHDISPLAY whichDisplay = USE_TEXT_GUI;
//	WHICHDISPLAY whichDisplay = USE_CCES_GUI;
//	WHICHDISPLAY whichDisplay = (USE_TEXT_GUI | USE_CCES_GUI);

	Init_CoffeePotSimulation(numCoffeePots, (WHICHDISPLAY) whichDisplay);

	char uniqueCoffeePotName1[] = "WDS";// Name characteristics sets coffee-pot size
	char uniqueCoffeePotName2[] = "Still WDS";
	char uniqueCoffeePotName3[] = "Still WDS";
	char uniqueCoffeePotName4[] = "Still WDS";

// Simulate plugging in new plug-and-play coffee pot control device into USB port
	COFFEEPOT_DEVICE *coffeePot1_BaseAddress = (COFFEEPOT_DEVICE *) NULL; // PSP Always initialize pointers to NULL
	coffeePot1_BaseAddress = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT1, uniqueCoffeePotName1);

	COFFEEPOT_DEVICE *coffeePot2_BaseAddress = (COFFEEPOT_DEVICE *) NULL; // PSP Always initialize pointers to NULL
	coffeePot2_BaseAddress = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT2, uniqueCoffeePotName2);

	COFFEEPOT_DEVICE *coffeePot3_BaseAddress = (COFFEEPOT_DEVICE *) NULL; // PSP Always initialize pointers to NULL
	coffeePot3_BaseAddress = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT3, uniqueCoffeePotName3);

	COFFEEPOT_DEVICE *coffeePot4_BaseAddress = (COFFEEPOT_DEVICE *) NULL; // PSP Always initialize pointers to NULL
	coffeePot4_BaseAddress = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT4, uniqueCoffeePotName4);

// NOTHING HAPPENS UNTIL YOU MAKE 1 SECOND OF MOCK TIME PASS;
	My_SimulatedOneSecondPassing_CPP( true);

    // Random target water levels and temperatures 
	unsigned short int waterLevelRequired1 = 410;
	unsigned short int waterTemperatureRequired1 = 70;

	unsigned short int waterLevelRequired2 = 425;
	unsigned short int waterTemperatureRequired2 = 80;

	unsigned short int waterLevelRequired3 = 430;
	unsigned short int waterTemperatureRequired3 = 90;

	unsigned short int waterLevelRequired4 = 395;
	unsigned short int waterTemperatureRequired4 = 95;


	My_DemonstrateCoffeePotAction(coffeePot1_BaseAddress, uniqueCoffeePotName1, waterLevelRequired1, waterTemperatureRequired1,
			coffeePot2_BaseAddress, uniqueCoffeePotName2, waterLevelRequired2, waterTemperatureRequired2,
			coffeePot3_BaseAddress, uniqueCoffeePotName3, waterLevelRequired3, waterTemperatureRequired3,
			coffeePot4_BaseAddress, uniqueCoffeePotName4, waterLevelRequired4, waterTemperatureRequired4);

}



