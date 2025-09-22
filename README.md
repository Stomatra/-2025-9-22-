# -2025-9-22-电子设计作业
## 综合练习
*一坨史山代码不想改了*
> 设定LED阵列为边界，[0, 0]位置上点亮一个LED，让LED如弹珠一样沿45度角运动，触碰边界后反弹继续运动
初始化位置i,j,矩阵，以及方向变量等
```C
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
```
方向1为左上，2为右上，3为左下，4为右下
其次定义directionchange()函数，用来判定当弹珠到达边界时的碰撞方向改变，分成了诸多情况
```C
uint8_t directionchange(){
  ...
}
```
setup与loop函数
```C
void setup() {
	matrix.begin();
	newGrid[0][0] = 1;
	direction = 4;
}

void loop() {
	matrix.renderBitmap(newGrid, 8, 12);
	if (direction == ...) {
    ...
  }//用来进行LED灯的改变
	if (i == 0 || i == 7 || j == 0 || j == 11) directionchange();//碰撞检测
	delay(100);
}
```
接下来便可以实现功能。

## 课后练习
> 将起始位置和方向设定为随机
在综合练习的基础上添加randomdirection函数，并修改setup中的初始位置
```C
  i = random(0, 8);
	j = random(0, 12);
	newGrid[i][j] = 1;
  direction = randomdirection();
```
```C
uint8_t randomdirection(){
  ...
};
```
> 让运动速度每反弹一次就递增
添加碰撞次数变量`t`并设置碰撞次数上限使速度达到上限
```C
if (i == 0 || i == 7 || j == 0 || j == 11) {
		directionchange();
		if (t < 170) {
			t += 12;
		}
	}
	delay(200 - t);
```
便可以实现要求的功能。
