#ifndef SAVESTATE_H
#define SAVESTATE_H
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

class SaveState {
public:
	SaveState();
	SaveState(std::string filename);
	long long ScoreSum;
	long long highScore;
	int difficulty;
	std::string SaveFileName;
	int r;
	int g;
	int b;
	int bulletDamage;
	int bulletFireInt;
	int missileDamage;
	int missileFireInt;
	float moveInc;
	void Initialize();
	void writeSave();
	void restoreToDefault();
};

#endif 