#ifndef PONG3D_H
#define PONG3D_H
#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"

class Pong3D {
	float p1y;
	float p2y;
	float ballx;
	float bally;
	float ballw;
	float ballh;
	float ballspeedy;
	float ballspeedx;
	float paddlelength;
	float speedmodifier;

private:
	void DrawPaddle(GLfloat posx, GLfloat posy, GLfloat posz, GLfloat length, GLfloat width, GLfloat height);
	void makenoise(void);
	bool detectballcollision(void);

public:
	Pong3D();
	int runPong(void);
	int p1score;
	int p2score;



};

#endif // !PONG3D_H

