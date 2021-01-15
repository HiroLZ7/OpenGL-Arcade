
#ifndef SHIP_H
#define SHIP_H
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
/*
	Made by Yazan Abughazaleh
*/

class Ship
{	//Basic enemy parameters for motion, collisions, and rendering
	int health;
	float bulletX;
	float bulletY;
	std::string weaponType;
	
	
	bool KeynotPress;
	//Ship Colors
	float r;
	float g;
	float b;
public:
	Ship();
	float shipX;
	float shipY;
	float bulletIncrement = 0;
	float missileIncrement = 0;
	bool useBullet;
	int damage;
	bool contBullet;
	bool bulletCollision;
	std::string getWeaponType();
	int getHealth();
	void genBullet();
	float getBulletX();
	float getBulletY();
	void drawBullet();
	void drawShip();
	void moveShip();
	void updateShip();
	void switchWeapon();
	
	

};


#endif