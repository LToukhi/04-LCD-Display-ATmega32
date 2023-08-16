/*
 * LCD.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Al-toukhi
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO.h"

#define LCD_Col            16
#define LCD_RowNum         2

#define LCD_Line1           1
#define LCD_Line2           2

#define LCD_Row1_ID        127
#define LCD_Row2_ID        191


#define LCD_DataPort       PORTA
#define LCD_ControlPort    PORTB

#define LCD_FuncSet        0b00111000
#define LCD_DisplayControl 0b00001101
#define LCD_DisplayClear   0b00000001
#define LCD_EntryMode      0b00000110

void HLCD_voidLcdInit() ;
void HLCD_voidSendCommand(u8 A_u8Cmd) ;
void HLCD_voidSendData(u8 A_u8Data) ;
void HLCD_voidLcdClear() ;
void HLCD_voidSendStr(u8 *ptrstr) ;
void HLCD_voidSetCursor(u8 A_u8RowID , u8 A_u8ColIndex) ;



#endif /* HAL_LCD_LCD_H_ */
