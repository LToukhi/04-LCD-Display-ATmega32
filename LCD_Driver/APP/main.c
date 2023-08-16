/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Al-toukhi
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include <util/delay.h>

void main()
{
	HLCD_voidLcdInit() ;
	while(1)
	{
	HLCD_voidSendStr("Good morning,") ;
	_delay_ms(500) ;
	HLCD_voidLcdClear() ;
	HLCD_voidSendStr("everyone!") ;
	_delay_ms(1500) ;
	HLCD_voidLcdClear() ;
	HLCD_voidSendStr("I hope you are") ;
	_delay_ms(500) ;
	HLCD_voidLcdClear() ;
    HLCD_voidSendStr("all doing well.") ;
    _delay_ms(1500) ;
    HLCD_voidLcdClear() ;
    HLCD_voidSendStr("Follow me on");
    _delay_ms(500) ;
    HLCD_voidLcdClear() ;
    HLCD_voidSendStr("Github.") ;
    _delay_ms(1500) ;
    HLCD_voidLcdClear() ;
    HLCD_voidSendStr("I'll be very") ;
    _delay_ms(500) ;
    HLCD_voidLcdClear() ;
    HLCD_voidSendStr("Grateful ^_^") ;
    _delay_ms(5000) ;
    HLCD_voidLcdClear() ;
	}
}


