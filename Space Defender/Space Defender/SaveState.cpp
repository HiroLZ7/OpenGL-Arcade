#include "SaveState.h"

SaveState::SaveState() {
	SaveFileName = "SpaceDefenderSave1.sav";
	highScore = 0;
	ScoreSum = 0;
	difficulty = 1;
	r = 0;
	g = 0;
	b = 0;
	bulletDamage = 1;
	bulletFireInt = 75;
	missileDamage = 15;
	missileFireInt = 500;
	moveInc = .01f;
}


SaveState::SaveState(std::string filename) {
	SaveFileName = filename;
	highScore = 0;
	ScoreSum = 0;
	difficulty = 1;
	r = 0;
	g = 0;
	b = 0;
	bulletDamage = 1;
	bulletFireInt = 75;
	missileDamage = 15;
	missileFireInt = 500;
	moveInc = .01f;
}

void SaveState::Initialize() {
	std::ifstream saveFileRead;
	std::string fileLine;
	saveFileRead.open(SaveFileName);
	if (saveFileRead.is_open()) {
		if (!(saveFileRead.peek() == std::ifstream::traits_type::eof())) {
			int dtc = 0;
			while (std::getline(saveFileRead, fileLine)) {
				switch (dtc) {
				case 0: {
					highScore = std::stoll(fileLine);
					break;
				}
				case 1: {
					ScoreSum = std::stoll(fileLine);
					break;
				}
				case 2: {
					difficulty = std::stoi(fileLine);
					break;
				}
				case 3: {
					r = std::stoi(fileLine);
					break;
				}
				case 4: {
					g = std::stoi(fileLine);
					break;
				}
				case 5: {
					b = std::stoi(fileLine);
					break;
				}
				case 6: {
					bulletDamage = std::stoi(fileLine);
					break;
				}
				case 7: {
					bulletFireInt = std::stoi(fileLine);
					break;
				}
				case 8: {
					missileDamage = std::stoi(fileLine);
					break;
				}
				case 9: {
					missileFireInt = std::stoi(fileLine);
					break;
				}
				case 10: {
					moveInc = std::stof(fileLine);
					break;
				}
				}
				dtc++;
			}
		}
	}
	saveFileRead.close();
}

void SaveState::writeSave() {
	std::ofstream saveFileOutput;
	saveFileOutput.open(SaveFileName, std::ofstream::out | std::ofstream::trunc);
	if (saveFileOutput.is_open()) {
		saveFileOutput << highScore << '\n';
		saveFileOutput << ScoreSum << '\n';
		saveFileOutput << difficulty << '\n';
		saveFileOutput << r << '\n';
		saveFileOutput << g << '\n';
		saveFileOutput << b << '\n';
		saveFileOutput << bulletDamage << '\n';
		saveFileOutput << bulletFireInt << '\n';
		saveFileOutput << missileDamage << '\n';
		saveFileOutput << missileFireInt << '\n';
		saveFileOutput << moveInc;
	}
	saveFileOutput.close();
}

void SaveState::restoreToDefault() {
	highScore = 0;
	ScoreSum = 0;
	difficulty = 1;
	r = 0;
	g = 0;
	b = 0;
	bulletDamage = 1;
	bulletFireInt = 75;
	missileDamage = 15;
	missileFireInt = 500;
	moveInc = .01f;
	writeSave();
}