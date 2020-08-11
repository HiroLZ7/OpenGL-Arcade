#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <vector>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"


class Enemy
{	//Basic enemy parameters for motion, collisions, and rendering
	int health;
	int verticies;

	std::vector<float> offsetsX;
	std::vector<float> offsetsY;
	//Enemy Colors
	float r;
	float g;
	float b;
	
public:
	float enemyIncrement;
	float enemyX;
	float enemyY;
	int scoreval;
	Enemy();
	void setHealth(int h);
	void setScore();
	int getHealth();
	void setVertexCount(int vTexCnt);
	void setEnemyX(float x);
	void setEnemyY(float y);
	void setEnemyIncrement(float increm);
	float getEnemyIncrement();
	void setEnemyXY(float x, float y);
	void setRGB(float r, float g, float b);
	void drawEnemy();
	void moveEnemy();
	void setOffsets(std::vector<float> offX, std::vector<float> offY);
	void sortVectors();
	float minXoffset();
	float maxXoffset();
	float minYoffset();
	float maxYoffset();

};


#endif

