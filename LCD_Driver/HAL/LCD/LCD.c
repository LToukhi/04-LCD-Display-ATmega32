/*
 * LCD.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Al-toukhi
 */
#include"../../MCAL/DIO/DIO.h"
#include<util/delay.h>
#include"LCD.h"

void HLCD_voidSendCommand(u8 A_u8Cmd)
{
	MDIO_voidPinValue(LCD_ControlPort , PIN0 , LOW) ;
	MDIO_voidPinValue(LCD_ControlPort , PIN1 , LOW) ;
	MDIO_voidPinValue(LCD_ControlPort , PIN2 , HIGH) ;
	MDIO_voidPortValue(LCD_DataPort , A_u8Cmd) ;
	_delay_ms(1);
	MDIO_voidPinValue(LCD_ControlPort , PIN2 , LOW) ;
}

void HLCD_voidSendData(u8 A_u8Data)
{
	MDIO_voidPinValue(LCD_ControlPort , PIN0 , HIGH) ;
	MDIO_voidPinValue(LCD_ControlPort , PIN1 , LOW) ;
	MDIO_voidPinValue(LCD_ControlPort , PIN2 , HIGH) ;
	MDIO_voidPortValue(LCD_DataPort , A_u8Data) ;
	_delay_ms(1);
	MDIO_voidPinValue(LCD_ControlPort , PIN2 , LOW) ;
}


void HLCD_voidLcdInit()
{
	MDIO_voidPortMode(PORTA , OUTPUT) ;
	MDIO_voidPortMode(PORTB , OUTPUT) ;
	_delay_ms(30) ;
	HLCD_voidSendCommand(LCD_FuncSet)  ;
	_delay_ms(1) ;
	HLCD_voidSendCommand(LCD_DisplayControl) ;
	_delay_ms(1) ;
	HLCD_voidSendCommand(LCD_DisplayClear) ;
	_delay_ms(2) ;
	HLCD_voidSendCommand(LCD_EntryMode) ;
}

void HLCD_voidLcdClear()
{
	HLCD_voidSendCommand(LCD_DisplayClear) ;
	_delay_ms(2) ;
}

void HLCD_voidSetCursor(u8 A_u8RowID , u8 A_u8ColIndex)
{
	switch(A_u8RowID)
	{
		case LCD_Line1 : HLCD_voidSendCommand(LCD_Row1_ID+A_u8ColIndex) ; break ;
		case LCD_Line2 : HLCD_voidSendCommand(LCD_Row2_ID+A_u8ColIndex) ; break ;
	}

}

void HLCD_voidSendStr(u8 *PtrStr)
{
	while(*PtrStr >0)
		{
			HLCD_voidSendData(*PtrStr ++) ;
			_delay_ms(10) ;
		}
}

