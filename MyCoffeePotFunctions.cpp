/*
 * MyCoffeePotFunctions.cpp
 *
 *  Created on: Oct 28, 2017
 *      Author: Victoria Lappas
 *
 */
#include "MyCoffeePotFunctions.h"

void My_SimulatedOneSecondPassing_CPP(bool  showDetail) {
	if (showDetail){
		Update();
	}
	else{
		Update();
	}
}


// TODO: fix boiler plate code
void My_MakeCoffeepot_ReadyForAction(COFFEEPOT_DEVICE *coffeePot_BaseAddress1, char *uniqueCoffeePotName1,
	COFFEEPOT_DEVICE *coffeePot_BaseAddress2, char *uniqueCoffeePotName2,
	COFFEEPOT_DEVICE *coffeePot_BaseAddress3, char *uniqueCoffeePotName3,
	COFFEEPOT_DEVICE *coffeePot_BaseAddress4, char *uniqueCoffeePotName4){
	printf("I turn on the coffee pot and wait until ready");
	printf("\n");

	coffeePot_BaseAddress1->controlRegister = INITandSTAYPOWEREDON_BIT;
	coffeePot_BaseAddress2->controlRegister = INITandSTAYPOWEREDON_BIT;
	coffeePot_BaseAddress3->controlRegister = INITandSTAYPOWEREDON_BIT;
	coffeePot_BaseAddress4->controlRegister = INITandSTAYPOWEREDON_BIT;
	My_SimulatedOneSecondPassing_CPP(true);

	while(coffeePot_BaseAddress1->controlRegister != 0x11 && coffeePot_BaseAddress2->controlRegister != 0x11 && coffeePot_BaseAddress3->controlRegister != 0x11 && coffeePot_BaseAddress4->controlRegister != 0x11 ){
		My_SimulatedOneSecondPassing_CPP(false);
	}
	My_SimulatedOneSecondPassing_CPP(true);


	printf("\n");
	printf("Turning on the LED power without turning off the device");
	printf("\n");
	coffeePot_BaseAddress1->controlRegister |= (LED_DISPLAY_ENABLE_BIT | DEVICE_READY_BIT_RO);
	coffeePot_BaseAddress2->controlRegister |= (LED_DISPLAY_ENABLE_BIT | DEVICE_READY_BIT_RO);
	coffeePot_BaseAddress3->controlRegister |= (LED_DISPLAY_ENABLE_BIT | DEVICE_READY_BIT_RO);
	coffeePot_BaseAddress4->controlRegister |= (LED_DISPLAY_ENABLE_BIT | DEVICE_READY_BIT_RO);
	My_SimulatedOneSecondPassing_CPP(true);

	coffeePot_BaseAddress1->controlRegister |= (LED_DISPLAY_ENABLE_BIT | USE_LED1_TO_SHOW_SYSTEM_POWEREDUP);
	coffeePot_BaseAddress2->controlRegister |= (LED_DISPLAY_ENABLE_BIT | USE_LED1_TO_SHOW_SYSTEM_POWEREDUP);
	coffeePot_BaseAddress3->controlRegister |= (LED_DISPLAY_ENABLE_BIT | USE_LED1_TO_SHOW_SYSTEM_POWEREDUP);
	coffeePot_BaseAddress4->controlRegister |= (LED_DISPLAY_ENABLE_BIT | USE_LED1_TO_SHOW_SYSTEM_POWEREDUP);
	My_SimulatedOneSecondPassing_CPP(true);

	coffeePot_BaseAddress1->controlRegister |= (USE_LED1_TO_SHOW_SYSTEM_POWEREDUP | USE_LED4_TO_SHOW_LED_DISPLAY_ENABLED);
	coffeePot_BaseAddress2->controlRegister |= (USE_LED1_TO_SHOW_SYSTEM_POWEREDUP | USE_LED4_TO_SHOW_LED_DISPLAY_ENABLED);
	coffeePot_BaseAddress3->controlRegister |= (USE_LED1_TO_SHOW_SYSTEM_POWEREDUP | USE_LED4_TO_SHOW_LED_DISPLAY_ENABLED);
	coffeePot_BaseAddress4->controlRegister |= (USE_LED1_TO_SHOW_SYSTEM_POWEREDUP | USE_LED4_TO_SHOW_LED_DISPLAY_ENABLED);
	My_SimulatedOneSecondPassing_CPP( true);

	coffeePot_BaseAddress1->controlRegister |= WATER_ENABLE_BIT;
	coffeePot_BaseAddress2->controlRegister |= WATER_ENABLE_BIT;
	coffeePot_BaseAddress3->controlRegister |= WATER_ENABLE_BIT;
	coffeePot_BaseAddress4->controlRegister |= WATER_ENABLE_BIT;
	My_SimulatedOneSecondPassing_CPP( true);

}


// TODO: fix boiler plate code
void My_DemonstrateCoffeePotAction(COFFEEPOT_DEVICE *coffeePot_BaseAddress1, char uniqueCoffeePotName1[],
unsigned short int waterLevelRequired1, unsigned short int waterTemperatureRequired1, COFFEEPOT_DEVICE *coffeePot_BaseAddress2,
char uniqueCoffeePotName2 [], unsigned short int waterLevelRequired2, unsigned short int waterTemperatureRequired2, COFFEEPOT_DEVICE *coffeePot_BaseAddress3,
char uniqueCoffeePotName3 [], unsigned short int waterLevelRequired3, unsigned short int waterTemperatureRequired3, COFFEEPOT_DEVICE *coffeePot_BaseAddress4,
char uniqueCoffeePotName4 [], unsigned short int waterLevelRequired4, unsigned short int waterTemperatureRequired4){
	printf("\n");

	//get the coffee pots ready
	My_MakeCoffeepot_ReadyForAction(coffeePot_BaseAddress1, uniqueCoffeePotName1, coffeePot_BaseAddress2, uniqueCoffeePotName2,
			coffeePot_BaseAddress3, uniqueCoffeePotName3, coffeePot_BaseAddress4, uniqueCoffeePotName4);

		printf("\n");
		printf("Activate the water and heat");
		printf("\n");

		//Activate water
		coffeePot_BaseAddress1->controlRegister |= (USE_LED3_TO_SHOW_WATER_ENABLED);
		coffeePot_BaseAddress2->controlRegister |= (USE_LED3_TO_SHOW_WATER_ENABLED);
		coffeePot_BaseAddress3->controlRegister |= (USE_LED3_TO_SHOW_WATER_ENABLED);
		coffeePot_BaseAddress4->controlRegister |= (USE_LED3_TO_SHOW_WATER_ENABLED);
		My_SimulatedOneSecondPassing_CPP( true);

		//activate heat
		coffeePot_BaseAddress1->controlRegister |= HEATER_ENABLE_BIT;
		coffeePot_BaseAddress2->controlRegister |= HEATER_ENABLE_BIT;
		coffeePot_BaseAddress3->controlRegister |= HEATER_ENABLE_BIT;
		coffeePot_BaseAddress4->controlRegister |= HEATER_ENABLE_BIT;
		My_SimulatedOneSecondPassing_CPP(false);
		coffeePot_BaseAddress1->controlRegister |= USE_LED2_TO_SHOW_HEATER_ENABLED;
		coffeePot_BaseAddress2->controlRegister |= USE_LED2_TO_SHOW_HEATER_ENABLED;
		coffeePot_BaseAddress3->controlRegister |= USE_LED2_TO_SHOW_HEATER_ENABLED;
		coffeePot_BaseAddress4->controlRegister |= USE_LED2_TO_SHOW_HEATER_ENABLED;
		My_SimulatedOneSecondPassing_CPP(false);
		coffeePot_BaseAddress1->heaterBoostRegister = 5;
		coffeePot_BaseAddress2->heaterBoostRegister = 5;
		coffeePot_BaseAddress3->heaterBoostRegister = 5;
		coffeePot_BaseAddress4->heaterBoostRegister = 5;
		My_SimulatedOneSecondPassing_CPP(true);


		//begin interrupt updates
		register_handler(ik_ivg12, my_ISR);

		SetSIC_IMASK_ASM();
		SetIMASK_ASM();
		SetILATCH_ASM();
		SetISR_VectorTable_ASM();


		SetCORE_TIMER_ASM();

		bool continueControl = true;
		while(continueControl){
			//water
			MyWaterControlCode_CPP_SM(coffeePot_BaseAddress1, waterLevelRequired1);
            //coffeePot2 uses assembly language for water control code
			MyWaterControlCode_ASM(coffeePot_BaseAddress2, waterLevelRequired2);
			MyWaterControlCode_CPP_SM(coffeePot_BaseAddress3, waterLevelRequired3);
			MyWaterControlCode_CPP_SM(coffeePot_BaseAddress4, waterLevelRequired4);

			//heat
			MyHeatControlCode_CPP_SM(coffeePot_BaseAddress1, waterTemperatureRequired1);
			//assembly heat control code for pot 2
			MyHeatControlCode_ASM(coffeePot_BaseAddress2, waterTemperatureRequired2);
			MyHeatControlCode_CPP_SM(coffeePot_BaseAddress3, waterTemperatureRequired3);
			MyHeatControlCode_CPP_SM(coffeePot_BaseAddress4, waterTemperatureRequired4);

		//	My_SimulatedOneSecondPassing_CPP(true);
		}

}

static int counter = 0;
void Update(){
	if(counter < 9){
		CoffeePot_Sync();
		counter++;
	}
	else{
		printf("\n");
		UpdateSimulationDisplay();
		counter = 0;
	}
}

EX_INTERRUPT_HANDLER(my_ISR);

volatile int count = 0;
#pragma interrupt
void my_ISR(void){
	if(count < 9){
		CoffeePot_Sync();
		count++;
	}
	else{
		printf("\n");
		UpdateSimulationDisplay();
		count = 0;
	}
	My_SimulatedOneSecondPassing_CPP(true);

}

//heat control code for new state machine implementation
void MyHeatControlCode_CPP_SM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterTemperatureRequired){
	if(CurrentTemperature_CPP(coffeePot_BaseAddress) < waterTemperatureRequired){
		coffeePot_BaseAddress->heaterRegister = 150;
	}
	else if(CurrentTemperature_CPP(coffeePot_BaseAddress)>= waterTemperatureRequired){
		coffeePot_BaseAddress->heaterRegister = 0;
	}

}

//water control code for new state machine implementation
void MyWaterControlCode_CPP_SM(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired){
	unsigned short int waterLevelThresh = 0.75 * waterLevelRequired;

	//Fast fill
	if(CurrentWaterLevel_CPP(coffeePot_BaseAddress) < waterLevelThresh){
		coffeePot_BaseAddress->waterInFlowRegister = 200;
	}
	//slow fill
	else if(CurrentWaterLevel_CPP(coffeePot_BaseAddress) < waterLevelRequired){
		coffeePot_BaseAddress->waterInFlowRegister = 5;
	}
	else{
		coffeePot_BaseAddress->waterInFlowRegister = 0;
	}
}


//old water control code
void MyWaterControlCode_CPP(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterLevelRequired){
	//Fast fill
	coffeePot_BaseAddress->waterInFlowRegister = 200;
	My_SimulatedOneSecondPassing_CPP( true);
	unsigned short int waterLevelThresh = 0.75 * waterLevelRequired;

	for(int time = 0; time < 30; time++){
		My_SimulatedOneSecondPassing_CPP( true);
		if( CurrentWaterLevel_CPP(coffeePot_BaseAddress) >= waterLevelThresh) {
			break;
		}
	}

	//Slow fill
	coffeePot_BaseAddress->waterInFlowRegister = 5;
	for(int time = 0; time < 30; time++){
		My_SimulatedOneSecondPassing_CPP( true);
		if( CurrentWaterLevel_CPP(coffeePot_BaseAddress) >= waterLevelRequired) {
			break;
		}
	}
}

//old heat control code
void MyHeatControlCode_CPP(COFFEEPOT_DEVICE *coffeePot_BaseAddress, unsigned short int waterTemperatureRequired){
	for(int time = 0; time < 480; time++){
		coffeePot_BaseAddress->heaterRegister = 200;
		if(time%30 == 0){
			printf("\n");
			My_SimulatedOneSecondPassing_CPP(true);
		}
		else{
			My_SimulatedOneSecondPassing_CPP(false);
		}

		//check if desired temperature has been reached
		if(CurrentTemperature_CPP(coffeePot_BaseAddress) >= waterTemperatureRequired) {
			coffeePot_BaseAddress->heaterRegister = 0;
		}
	}


}

