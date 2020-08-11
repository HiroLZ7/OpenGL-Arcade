#ifndef SPACESHIPTHREE_H
#define SPACESHIPTHREE_H
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

class SpaceShipThree
{
	std::vector<Enemy> enemyProfiles;
	std::vector<Enemy> bossProfiles;
	std::vector<Enemy> activeEnemies;
	Ship* ship;
	bool bossRun;
public:
	int runSpaceDefender(void);
	SpaceShipThree();
	int enemyTypes;
	int bossTypes;
	int score;
	int kills;
	float diffMult;

private:
	bool gameover;
	void drawExplosion(float x, float y);
	void generateEnemyProfiles();
	void generateBossProfiles();
	void loadEnemies(int difVar);
	void loadEnemy();
	void loadBoss();
	void processCollisions();



};








#endif
