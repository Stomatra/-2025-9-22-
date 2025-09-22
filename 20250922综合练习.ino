/*
 Name:		freedanzhu.ino
 Created:	2025/9/19 20:18:56
 Author:	yjh12
*/
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
uint8_t i = 0, j = 0;
uint8_t newGrid[8][12] = {
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
uint8_t direction; //方向变量

uint8_t directionchange() {
	if (i == 0 && j == 0) direction = 4;
	else if (i == 0 && j == 11) direction = 3;
	else if (i == 7 && j == 0) direction = 2;
	else if (i == 7 && j == 11) direction = 1;
	else if (i == 0) {
		if (direction == 1) direction = 3;
		else if (direction == 2) direction = 4;
	}
	else if (i == 7) {
		if (direction == 3) direction = 1;
		else if (direction == 4) direction = 2;
	}
	else if (j == 0) {
		if (direction == 1) direction = 2;
		else if (direction == 3) direction = 4;
	}
	else if (j == 11) {
		if (direction == 2) direction = 1;
		else if (direction == 4) direction = 3;
	}
	return direction;
}

// the setup function runs once when you press reset or power the board
void setup() {
	matrix.begin();
	newGrid[0][0] = 1;
	direction = 4;
	//方向说明：1为左上，2为右上，3为左下，4为右下
}

// the loop function runs over and over again until power down or reset
void loop() {
	matrix.renderBitmap(newGrid, 8, 12);
	if (direction == 1) {
		newGrid[i][j] = 0;
		newGrid[i - 1][j - 1] = 1;
		i--;
		j--;
	}
	else if (direction == 2) {
		newGrid[i][j] = 0;
		newGrid[i - 1][j + 1] = 1;
		i--;
		j++;
	}
	else if(direction == 3){
		newGrid[i][j] = 0;
		newGrid[i + 1][j - 1] = 1;
		i++;
		j--;
	}
	else if(direction==4){
		newGrid[i][j] = 0;
		newGrid[i + 1][j + 1] = 1;
		i++;
		j++;
	}
	if (i == 0 || i == 7 || j == 0 || j == 11) directionchange();
	delay(100);
}
