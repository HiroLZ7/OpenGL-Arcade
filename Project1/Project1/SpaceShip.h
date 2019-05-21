#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"

class SpaceShip
{

	float bulletX;
	float bulletY;
	float x;
	float y;
	float enemy1X;
	float enemy1Y;
	bool drawEnemy1;
	float enemy2X;
	float enemy2Y;
	bool drawEnemy2;
	float enemy3X;
	float enemy3Y;
	bool drawEnemy3;
	bool contBullet;
	float increment;
	bool isKilled;
	float incrementENemy;

	public:
		int runSpaceDefender(void);
		SpaceShip();
		int score;

	private:
		void drawEnemyOne(bool drawEnem);
		void drawEnemyTwo(bool drawEnem);
		void drawEnemyThree(bool drawEnem);
		void moveEnemy();
		void drawShip();
		void MoveShip();
		void genBullet();
		void drawBullet(bool cont);


};








#endif