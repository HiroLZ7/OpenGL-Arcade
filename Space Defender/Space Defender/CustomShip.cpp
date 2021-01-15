#include "CustomShip.h"

CustomShip::CustomShip(SaveState * sd)
{
	saveData = sd;
	pR = (float)(saveData->r / 255.0f);
	pG = (float)(saveData->g / 255.0f);
	pB = (float)(saveData->b / 255.0f);
	health = 1;
	shipX = 0.0f;
	shipY = -.89f;
	keyNotPressed = false;
	activeWeapon = "BULLET";
	firingTimeStamp = std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch());;
	firstFire = true;
}

float CustomShip::getShipX()
{
	return shipX;
}

float CustomShip::getShipY()
{
	return shipY;
}

int CustomShip::getHealth()
{
	return health;
}

std::string CustomShip::getActiveWeapon()
{
	return activeWeapon;
}

void CustomShip::setHealth(int h)
{
	health = h;
}

void CustomShip::genProjectile()
{
	if (GetKeyState(VK_SPACE) & 0x8000) {
		
		//Check which weapon type is active;
		if (activeWeapon == "BULLET") {
			//Check timelimit threshold between firing rate
			if (std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch() - firingTimeStamp).count() >= saveData->bulletFireInt || firstFire) {
				//Add a projectile of given type to buffer
				projectileBuffer.push_back(Projectile(shipX,shipY, "BULLET", .08,saveData->bulletDamage));
				firstFire = false;
				firingTimeStamp = std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch());
			}
		}
		if (activeWeapon == "MISSILE") {
			if (std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch() - firingTimeStamp).count() >= saveData->missileFireInt || firstFire) {
				projectileBuffer.push_back(Projectile(shipX, shipY, "MISSILE", .03, saveData->missileDamage));
				firstFire = false;
				firingTimeStamp = std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch());
			}
		}
		
	}
}

void CustomShip::switchWeapons()
{
	if (GetKeyState('Z') & 0x8000) {

		if (keyNotPressed) {
			if (activeWeapon == "BULLET") {
				activeWeapon = "MISSILE";
			}
			else {
				activeWeapon = "BULLET";
			}
		}
		//std::cout << weaponType << std::endl;
		keyNotPressed = false;
	}
	else {
		keyNotPressed = true;
	}
}

void CustomShip::processProjectileBuffer()
{
	for (size_t i = 0; i < projectileBuffer.size(); i++) {
		projectileBuffer.at(i).drawBullet();
		projectileBuffer.at(i).drawMissile();
		if (projectileBuffer.at(i).getIncrement() >= 2.5) {
			projectileBuffer.erase(projectileBuffer.begin() + i);
		}
	}
}

void CustomShip::moveShip()
{
	if (GetKeyState('W') & 0x8000) {
		if (shipY + saveData->moveInc < 1) {
			shipY += saveData->moveInc;
		}
	}
	if (GetKeyState('S') & 0x8000) {
		if (shipY - saveData->moveInc > -1) {
			shipY -= saveData->moveInc;
		}
	}
	if (GetKeyState('D') & 0x8000) {
		if (shipX + saveData->moveInc < 1) {
			shipX += saveData->moveInc;
		}
	}
	if (GetKeyState('A') & 0x8000) {
		if (shipX - saveData->moveInc > -1) {
			shipX -= saveData->moveInc;
		}
	}
}

void CustomShip::drawShip()
{
	glColor3f(pR, pG, pB);
	glBegin(GL_POLYGON);
	glVertex3f(0 + shipX, 0 + shipY, 0);
	glVertex3f(0 + shipX - .08, 0 + shipY - .11, 0);
	glVertex3f(0 + shipX, 0 + shipY - .05, 0);
	glVertex3f(0 + shipX + .08, 0 + shipY - .11, 0);
	glEnd();
	glColor3f(1 - pR, 1 - pG, 1 - pB);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0 + shipX, 0 + shipY, 0);
	glVertex3f(0 + shipX - .08, 0 + shipY - .11, 0);
	glVertex3f(0 + shipX, 0 + shipY - .05, 0);
	glVertex3f(0 + shipX + .08, 0 + shipY - .11, 0);
	glEnd();
	glLineWidth(1);
}

void CustomShip::updateShip()
{
	switchWeapons();
	moveShip();
	drawShip();
	genProjectile();
	processProjectileBuffer();
}
