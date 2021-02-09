/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/04- CLCD/CLCD_interface.h"

#define LCD_COLS 				16
#define ZERO					0

#define RIGHT_RUNNING_PLAYER	0
#define LEFT_RUNNING_PLAYER		1

#define SHOOT_PLAYER			2
#define BALL_DOWN				3
#define BALL_UP					4

/*	Function Prototype	*/

int main(void) {
	CLCD_voidInit();											//INITIALIZE LCD
	CLCD_voidSendExtraChar();	//STORING SPECIAL CHARACTER (ARABIC) TO CGRAM
	u8 LOC_u8Iterator = 0;
	while (1) {
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_2);	//INITIALIZE CURSOR POSTION

		CLCD_voidSendString((u8 *) "MO-SALAH STORY");

		for (LOC_u8Iterator = ZERO; LOC_u8Iterator < 8; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(BALL_DOWN);
			_delay_ms(300);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(BALL_UP);
			_delay_ms(300);

		}

		CLCD_voidClearDisplay();

		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);//INITIALIZE CURSOR POSTION
		CLCD_voidSendString((u8 *) "PLAYER HAS BALL");

		for (LOC_u8Iterator = 0; LOC_u8Iterator < 5; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_3 + LOC_u8Iterator);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_4 + LOC_u8Iterator);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(BALL_DOWN);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_13 - LOC_u8Iterator);	//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);
			_delay_ms(250);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_3 + LOC_u8Iterator);//INITIALIZE CURSOR POSTION
			CLCD_voidSendString((u8 *) " ");
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_4 + LOC_u8Iterator);//INITIALIZE CURSOR POSTION
			CLCD_voidSendString((u8 *) " ");
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_13 - LOC_u8Iterator);	//INITIALIZE CURSOR POSTION
			CLCD_voidSendString((u8 *) " ");
		}

		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);//INITIALIZE CURSOR POSTION
		CLCD_voidSendString((u8 *) "MoSalah GET BALL");
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(LEFT_RUNNING_PLAYER);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(BALL_UP);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);

		_delay_ms(1000);
		CLCD_voidClearDisplay();
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);//INITIALIZE CURSOR POSTION
		CLCD_voidSendString((u8 *) "SALAH IS RUNNING");
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(LEFT_RUNNING_PLAYER);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(BALL_DOWN);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);

		_delay_ms(1000);
		CLCD_voidClearDisplay();
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);//INITIALIZE CURSOR POSTION
		CLCD_voidSendString((u8 *) "SALAH SHOOT!");
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(SHOOT_PLAYER);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(BALL_DOWN);
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);//INITIALIZE CURSOR POSTION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);
		_delay_ms(200);

		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);//INITIALIZE CURSOR POSTION
		CLCD_voidSendString((u8 *) " ");

		for (LOC_u8Iterator = 1; LOC_u8Iterator <= 6; LOC_u8Iterator++) {

			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(BALL_UP);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6 - LOC_u8Iterator);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(BALL_UP);

			_delay_ms(200);
		}
		CLCD_voidClearDisplay();
		for (LOC_u8Iterator = 1; LOC_u8Iterator <= 6; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);//INITIALIZE CURSOR POSTION
			CLCD_voidSendString((u8 *) "GOALLLL!!!");
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);
			_delay_ms(500);
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);//INITIALIZE CURSOR POSTION
			CLCD_voidSendString((u8 *) "          ");
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);//INITIALIZE CURSOR POSTION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);
			_delay_ms(500);

		}

	}
}

/*	FUNCTION PROTOTYPE	*/

