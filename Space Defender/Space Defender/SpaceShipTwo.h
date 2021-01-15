#ifndef SPACESHIPTWO_H
#define SPACESHIPTWO_H
#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <vector>
#include <chrono>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"
#include "Ship.h"
#include "Enemy.h"
#include <ctime>

class SpaceShipTwo
{
	std::vector<Enemy> enemyProfiles;
	std::vector<Enemy> activeEnemies;
	Ship* ship;
public:
	int runSpaceDefender(void);
	SpaceShipTwo();
	int enemyTypes;
	int score;
	int kills;
	float diffMult;

private:
	bool gameover;
	void drawExplosion(float x, float y);
	void generateEnemyProfiles();
	void loadEnemies(int difVar);
	void loadEnemy();
	void processCollisions();
	


};








#endif