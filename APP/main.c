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
	CLCD_voidInit();														//INITIALIZE LCD
	CLCD_voidSendExtraChar();												//STORING SPECIAL CHARACTER (ARABIC) TO CGRAM
	u8 LOC_u8Iterator = 0;
	while (1) {
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_2);						//SET CURSOR POSITION

		CLCD_voidSendString((u8 *) "MO-SALAH STORY");						//PRINT WORD IN LCD

		for (LOC_u8Iterator = ZERO; LOC_u8Iterator < 8; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);					//SET CURSOR POSITION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);						//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);					//SET CURSOR POSITION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);					//SET CURSOR POSITION
			CLCD_voidSendData(BALL_DOWN);									//PRINT SPECIAL CHARACTER IN LCD
			_delay_ms(300);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);					//SET CURSOR POSITION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);					//SET CURSOR POSITION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);						//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);					//SET CURSOR POSITION
			CLCD_voidSendData(BALL_UP);
			_delay_ms(300);

		}

		CLCD_voidClearDisplay();

		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);						//SET CURSOR POSITION
		CLCD_voidSendString((u8 *) "PLAYER HAS BALL");						//PRINT WORD IN LCD

		for (LOC_u8Iterator = 0; LOC_u8Iterator < 5; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_3 + LOC_u8Iterator);  //SET CURSOR POSITION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);						//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_4 + LOC_u8Iterator);  //SET CURSOR POSITION
			CLCD_voidSendData(BALL_DOWN);									//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_13 - LOC_u8Iterator); //SET CURSOR POSITION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD
			_delay_ms(250);
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_3 + LOC_u8Iterator);  //SET CURSOR POSITION
			CLCD_voidSendString((u8 *) " ");								//DELETE PREVIOUS CHARACTER
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_4 + LOC_u8Iterator);  //SET CURSOR POSITION
			CLCD_voidSendString((u8 *) " ");								//DELETE PREVIOUS CHARACTER
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_13 - LOC_u8Iterator); //SET CURSOR POSITION
			CLCD_voidSendString((u8 *) " ");								//DELETE PREVIOUS CHARACTER
		}

		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);						//SET CURSOR POSITION
		CLCD_voidSendString((u8 *) "MoSalah GET BALL");						//PRINT WORD IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);						//SET CURSOR POSITION
		CLCD_voidSendData(LEFT_RUNNING_PLAYER);								//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);						//SET CURSOR POSITION
		CLCD_voidSendData(BALL_UP);											//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);						//SET CURSOR POSITION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD

		_delay_ms(1000);													//DELAY FOR ONE SECOND
		CLCD_voidClearDisplay();											//CLEAR LCD DISPLAY
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);						//SET CURSOR POSITION
		CLCD_voidSendString((u8 *) "SALAH IS RUNNING");						//PRINT WORD IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);						//SET CURSOR POSITION
		CLCD_voidSendData(LEFT_RUNNING_PLAYER);								//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);						//SET CURSOR POSITION
		CLCD_voidSendData(BALL_DOWN);										//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);						//SET CURSOR POSITION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD

		_delay_ms(1000);													//DELAY FOR ONE SECOND
		CLCD_voidClearDisplay();											//CLEAR LCD DISPLAY
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);						//SET CURSOR POSITION
		CLCD_voidSendString((u8 *) "SALAH SHOOT!");							//PRINT WORD IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_7);						//SET CURSOR POSITION
		CLCD_voidSendData(SHOOT_PLAYER);									//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);						//SET CURSOR POSITION
		CLCD_voidSendData(BALL_DOWN);										//PRINT SPECIAL CHARACTER IN LCD
		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_9);						//SET CURSOR POSITION
		CLCD_voidSendData(RIGHT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD
		_delay_ms(200);														//DELAY FOR 200 MILLISECONDS

		CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);						//SET CURSOR POSITION
		CLCD_voidSendString((u8 *) " ");									//PRINT FREE SPACE TO DELETE PREVIOUS CHARACTER

		for (LOC_u8Iterator = 1; LOC_u8Iterator <= 6; LOC_u8Iterator++) {

			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6);					//SET CURSOR POSITION
			CLCD_voidSendData(BALL_UP);										//PRINT SPECIAL CHARACTER IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_6 - LOC_u8Iterator);	//SET CURSOR POSITION
			CLCD_voidSendData(BALL_UP);										//PRINT SPECIAL CHARACTER IN LCD

			_delay_ms(200);
		}
		CLCD_voidClearDisplay();
		for (LOC_u8Iterator = 1; LOC_u8Iterator <= 6; LOC_u8Iterator++) {
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);					//SET CURSOR POSITION
			CLCD_voidSendString((u8 *) "GOALLLL!!!");						//PRINT WORD IN LCD
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);					//SET CURSOR POSITION
			CLCD_voidSendData(RIGHT_RUNNING_PLAYER);						//PRINT SPECIAL CHARACTER IN LCD
			_delay_ms(500);													//DELAY FOR HALF SECOND
			CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_3);					//SET CURSOR POSITION
			CLCD_voidSendString((u8 *) "          ");						//DELETE ALL OVER THE WORD IN FIRST ROW
			CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_8);					//SET CURSOR POSITION
			CLCD_voidSendData(LEFT_RUNNING_PLAYER);							//PRINT SPECIAL CHARACTER IN LCD
			_delay_ms(500);													//DELAY FOR HALF SECOND

		}

	}
}


