#ifndef CUSTOMSHIP_H
#define CUSTOMSHIP_H
#include <iostream>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include<stdio.h>
#include <string>
#include <vector>
#include <chrono>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"
#include "linmath.h"
#include "Projectile.h"
#include "SaveState.h"

typedef std::chrono::milliseconds ms;

class CustomShip {
private:
	float pR;
	float pG;
	float pB;
	SaveState* saveData;
	float shipX;
	float shipY;
	int health;
	bool keyNotPressed;
	std::string activeWeapon;
	ms firingTimeStamp;
	bool firstFire;

public:
	CustomShip(SaveState* sd);
	std::vector<Projectile> projectileBuffer;
	float getShipX();
	float getShipY();
	int getHealth();
	std::string getActiveWeapon();
	void setHealth(int h);
	void genProjectile();
	void switchWeapons();
	void processProjectileBuffer();
	void moveShip();
	void drawShip();
	void updateShip();


};

#endif // !CUSTOMSHIP_H

