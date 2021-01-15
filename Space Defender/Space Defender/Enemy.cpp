#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include <array>
#include <vector>
#include "mmSystem.h"
#include "Enemy.h"

//Constructor for the Enemy class
Enemy::Enemy() {
	health = 0;
	verticies = 0;
	enemyX = 0;
	enemyY = 0;
	enemyIncrement = .01;
	
	//Enemy Colors
	r = 0;
	g = 0;
	b = 0;
}

//Mutators for enemy parameters
void Enemy::setHealth(int h){
	health = h;
}

void Enemy::setScore() {
	scoreval = health;
}

int Enemy::getHealth() {
	return health;
}

void Enemy::setVertexCount(int vTexCnt) {
	verticies = vTexCnt;
}
void Enemy::setEnemyX(float x) {
	enemyX = x;
}

void Enemy::setEnemyY(float y) {
	enemyY = y;
}

void Enemy::setEnemyIncrement(float increm) {
	enemyIncrement = increm;
}

float Enemy::getEnemyIncrement() {
	return enemyIncrement;
}

void Enemy::setEnemyXY(float x, float y) {
	setEnemyX(x);
	setEnemyY(y);
}

void Enemy::setRGB(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

// Return the minimum and maximum values from the offsets vectors for both x and y
float Enemy::maxXoffset() {
	return *max_element(offsetsX.begin(), offsetsX.end());
}

float Enemy::minXoffset() {
	return *min_element(offsetsX.begin(), offsetsX.end());
}

float Enemy::maxYoffset() {
	return *max_element(offsetsY.begin(), offsetsY.end());
}

float Enemy::minYoffset() {
	return *min_element(offsetsY.begin(), offsetsY.end());
}

//sets the offsets of verticies from the starting x,y point
void Enemy::setOffsets(std::vector<float> offX, std::vector<float> offY) {
	for (int i = 0; i < verticies; i++) {
		offsetsX.push_back(offX.at(i));
		offsetsY.push_back(offY.at(i));
	}
}
//This function orders all the points of enemy shape strating at the origin of the shape and endling at the highest x value
void Enemy::sortVectors() {
	std::vector<float> newX;
	std::vector<float> newY;
	newX.push_back(offsetsX.at(0));
	newY.push_back(offsetsY.at(0));
	offsetsX.erase(offsetsX.begin());
	offsetsY.erase(offsetsY.begin());
	//perform sort on remianing elements in offX and make sure that their elements in offY match
	for (int i = 0; i < offsetsX.size() - 1; i++) {
		for (int j = 0; j < offsetsX.size() - i - 1; j++) {
			if (offsetsX.at(j) > offsetsX.at(j + 1)) {
				std::swap(offsetsX.at(j), offsetsX.at(j + 1));
				std::swap(offsetsY.at(j), offsetsY.at(j + 1));
			}
		}
	}
	for (int v = 0; v < offsetsX.size(); v++) {
		newX.push_back(offsetsX.at(v));
		newY.push_back(offsetsY.at(v));
	}
	offsetsX = newX;
	offsetsY = newY;
}

//draws enemy object
void Enemy::drawEnemy() {
	if (health > 0) {
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		
		for (int i = 0; i < verticies; i++) {
			glVertex3f(0+enemyX + offsetsX.at(i), 0+enemyY + offsetsY.at(i),0);
		}
		glEnd();
		glColor3f(1-r,1- g,1- b);
		glBegin(GL_LINE_LOOP);

		for (int i = 0; i < verticies; i++) {
			glVertex3f(0 + enemyX + offsetsX.at(i), 0 + enemyY + offsetsY.at(i), 0);
		}
		glEnd();
	}
}

//increments enemy y coordinates to move the enemy
void Enemy::moveEnemy() {
	if (health > 0) {
		enemyY -= enemyIncrement;
	}
}

