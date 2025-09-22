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
uint8_t m = 0;
uint8_t t = 0;//反弹次数变量

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

uint8_t randomdirection() {
	if (i == 0 && j == 0) direction = 4;
	else if(i==0&&j==11) direction=3;
	else if(i==7&&j==0) direction=2;
	else if(i==7&&j==11) direction=1;
	else if(i==0) direction=random(3,5);
	else if(i==7) direction=random(1,3);
	else if (j == 0) {
		m = random(1, 3);
		if(m==1) direction = 2;
		else if (m == 2) direction = 4;
	}
	else if(j==11) {
		m = random(1, 3);
		if (m == 1) direction = 1;
		else if (m == 2) direction = 3;
	}
	else direction = random(1, 5);
}

// the setup function runs once when you press reset or power the board
void setup() {
	matrix.begin();
	i = random(0, 8);
	j = random(0, 12);
	newGrid[i][j] = 1;
	direction = randomdirection();
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
	if (i == 0 || i == 7 || j == 0 || j == 11) {
		directionchange();
		if (t < 170) {
			t += 12;
		}
	}
	delay(200 - t);
}
