#ifndef SPACESHIPFOUR_H
#define SPACESHIPFOUR_H
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
#include "CustomShip.h"
#include "Enemy.h"
#include "SaveState.h"
#include <ctime>

class SpaceShipFour
{
	std::vector<Enemy> enemyProfiles;
	std::vector<Enemy> bossProfiles;
	std::vector<Enemy> activeEnemies;
	CustomShip* ship;
	bool bossRun;
public:
	SaveState *saveData;
	int runSpaceDefender(void);
	SpaceShipFour(int diff, SaveState *sd);
	int enemyTypes;
	int bossTypes;
	int score;
	int kills;
	float diffMult;

private:
	int dific;
	bool gameover;
	void drawExplosion(float x, float y);
	void generateEnemyProfiles();
	void generateBossProfiles();
	void loadEnemies(int difVar);
	void loadEnemy(int difVar);
	void loadBoss(int difVar);
	void processCollisions(bool &isBoss, int difVar);



};

#endif