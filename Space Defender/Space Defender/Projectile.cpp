#include "Projectile.h"

Projectile::Projectile(float x, float y, std::string weaponT, float incM, int dm)
{
	bulletX = x;
	bulletY = y;
	weaponType = weaponT;
	increment = 0;
	incMod = incM;
	damage = dm;
	bulletLength = .1f;
}

float Projectile::getBulletX()
{
	return bulletX;
}

float Projectile::getBulletY()
{
	return bulletY;
}

std::string Projectile::getWeaponType()
{
	return weaponType;
}

int Projectile::getDamage()
{
	return damage;
}

float Projectile::getIncrement()
{
	return increment;
}

float Projectile::getBulletLength()
{
	return bulletLength;
}

float Projectile::getIncrementModifier()
{
	return incMod;
}

void Projectile::setBulletX(float x)
{
	bulletX = x;
}

void Projectile::setBulletY(float y)
{
	bulletY = y;
}

void Projectile::setWeaponType(std::string wT)
{
	weaponType = wT;
}

void Projectile::setDamage(int dam)
{
	damage = dam;
}

void Projectile::setIncrement(float inc)
{
	increment = inc;
}

void Projectile::setIncrementModifier(float incM)
{
	incMod = incM;
}

void Projectile::setBulletLength(float bL)
{
	bulletLength = bL;
}

void Projectile::drawBullet()
{
	if (weaponType == "BULLET") {
		glColor3f(.5, .81, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3f(bulletX, bulletY + increment, 0);
		glVertex3f(bulletX, bulletY + .05 + increment, 0);
		glEnd();
		increment += incMod;
	}
}

void Projectile::drawMissile()
{
	if (weaponType == "MISSILE") {
		glColor3f(.63921, .3686, .325);
		glBegin(GL_POLYGON);
		glVertex3f(bulletX, bulletY + increment, 0);
		glVertex3f(bulletX, bulletY + .1 + increment, 0);
		glVertex3f(bulletX + .01, bulletY + .02 + increment, 0);
		glVertex3f(bulletX - .01, bulletY + .02 + increment, 0);
		glVertex3f(bulletX + .01, bulletY + .08 + increment, 0);
		glVertex3f(bulletX - .01, bulletY + .08 + increment, 0);
		glEnd();
		increment += incMod;
	}
}

