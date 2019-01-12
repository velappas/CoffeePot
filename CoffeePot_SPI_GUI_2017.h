/*
 * CoffeePot_SPI_GUI_2017.h
 *
 *  Created on: Oct 28, 2017
 *      Author: Victoria Lappas
 *
 */

#ifndef COFFEEPOT_SPI_GUI_2017_H_
#define COFFEEPOT_SPI_GUI_2017_H_



void InitSPIGUI_Fast(int whichPFline);
void SPI_UpdateString(char *upDateString);

void SaveOldSPISettings(void);
void RecoverOldSPISettings(void);
void SetNewSPISettings(void);



#endif /* COFFEEPOT_SPI_GUI_2017_H_ */
