#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <math.h>
#include "linmath.h"

class Projectile {
private:
	float bulletX;
	float bulletY;
	std::string weaponType;
	float increment;
	float incMod;
	int damage;
	float bulletLength;
public:
	Projectile(float x, float y, std::string weaponT, float incM, int dm);
	float getBulletX();
	float getBulletY();
	std::string getWeaponType();
	int getDamage();
	float getIncrement();
	float getBulletLength();
	float getIncrementModifier();
	void setBulletX(float x);
	void setBulletY(float y);
	void setWeaponType(std::string wT);
	void setDamage(int dam);
	void setIncrement(float inc);
	void setIncrementModifier(float incM);
	void setBulletLength(float bL);
	void drawBullet();
	void drawMissile();
};

#endif
