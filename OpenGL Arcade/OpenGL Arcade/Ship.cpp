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
#include "Ship.h"

Ship::Ship() {
	health = 1;
	shipX = 0;
	shipY = -.89;
	useBullet = true;
	weaponType = "Plasma Gun";
	contBullet = false;
	bulletCollision = false;
	damage = 1;
	KeynotPress = true;
	r = 0.83921;
	g = 0.6549;
	b = 0.05;
}

int Ship::getHealth() {
	return health;
}

std::string Ship::getWeaponType() {
	return weaponType;
}

float Ship::getBulletX() {
	return bulletX;
}

float Ship::getBulletY() {
	return bulletY;
}

void Ship::genBullet() {
	if (GetKeyState(VK_SPACE) & 0x8000) {
			contBullet = true;
			bulletX = shipX;
			bulletY = shipY;
			
	}
}


void Ship::drawBullet() {
	if (bulletIncrement >= 1.5 && useBullet) {
		bulletIncrement = 0;
		contBullet = false;
	}
	else if (missileIncrement >= 2 && !useBullet) {
		missileIncrement = 0;
		contBullet = false;
	}
	if (contBullet) {
		if (useBullet) {
			//bullet drawing here
			glColor3f(.5, .81, 1);
			glBegin(GL_LINE_STRIP);
			glVertex3f(bulletX, bulletY + bulletIncrement, 0);
			glVertex3f(bulletX, bulletY + .1 + bulletIncrement, 0);
			glEnd();
		}
		else {
			//missile drawing here
			glColor3f(.63921, .3686, .325);
			glBegin(GL_POLYGON);
			glVertex3f(bulletX, bulletY + missileIncrement, 0);
			glVertex3f(bulletX, bulletY + .1 + missileIncrement, 0);
			glVertex3f(bulletX + .01, bulletY + .02 + missileIncrement, 0);
			glVertex3f(bulletX - .01, bulletY + .02 + missileIncrement, 0);
			glVertex3f(bulletX + .01, bulletY + .08 + missileIncrement, 0);
			glVertex3f(bulletX - .01, bulletY + .08 + missileIncrement, 0);
			glEnd();
		}
		bulletIncrement += .08;
		missileIncrement += .03;
		if (bulletIncrement >= 1.5 && useBullet) {
			bulletIncrement = 0;
			contBullet = false;
			
		}
		else if (missileIncrement >= 2 && !useBullet) {
			missileIncrement = 0;
			contBullet = false;
		}
	}
}

void Ship::drawShip() {
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex3f(0 + shipX, 0 + shipY, 0);
	glVertex3f(0 + shipX - .08, 0 + shipY - .11, 0);
	glVertex3f(0 + shipX, 0 + shipY - .05, 0);
	glVertex3f(0 + shipX + .08, 0 + shipY - .11, 0);
	glEnd();
}

void Ship::moveShip() {
	if (GetKeyState('W') & 0x8000) {
		if (shipY + 0.01 < 1) {
			shipY += 0.01;
		}
	}
	if (GetKeyState('S') & 0x8000) {
		if (shipY - 0.01 > -1) {
			shipY -= 0.01;
		}
	}
	if (GetKeyState('D') & 0x8000) {
		if (shipX + 0.01 < 1) {
			shipX += 0.01;
		}
	}
	if (GetKeyState('A') & 0x8000) {
		if (shipX - 0.01 > -1) {
			shipX -= 0.01;
		}
	}
}


void Ship::switchWeapon() {
	if (GetKeyState('Z') & 0x8000) {
		
		if (!contBullet && KeynotPress) {
			if (useBullet) {
				useBullet = false;
				damage = 10;
				weaponType = "Plasma Missile";
			}
			else {
				useBullet = true;
				damage = 1;
				weaponType = "Plasma Gun";
			}
		}
		//std::cout << weaponType << std::endl;
		KeynotPress = false;
	}
	else {
		KeynotPress = true;
	}
	
}

void Ship::updateShip() {
	switchWeapon();
	moveShip();
	drawShip();
	genBullet();
	drawBullet();
	
	
}