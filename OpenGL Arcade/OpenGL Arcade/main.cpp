#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "SpaceShip.h"
#include "SpaceShipTwo.h"
#include "SpaceShipThree.h"


using namespace::std;


string selection;

int main() {
	while (true) {
		SpaceShip* spaceship = new SpaceShip();
		SpaceShipTwo* two = new SpaceShipTwo();
		SpaceShipThree* three = new SpaceShipThree();

		cout << "Welcome to OpenGL Arcade" << endl;
		cout << "Please Select a Game" << endl;
		cout << "Close OpenGL Arcade (0)" << endl;
		cout << "Space Defender 1 (1)" << endl;
		cout << "Space Defender 2 (2)" << endl;
		cout << "Space Defender 3 (3)" << endl;
		cin >> selection;
		if (selection == "1") {
			cout << "Welcome to Space Defender!" << endl;
			cout << "The objective of the game is to shoot down as many ships as possible." << endl;
			cout << "If your ship collides with an enemy ship or an enemy reaches the bottom of the screen, its Game Over." << endl;
			cout << "The game's difficulty increases slightly whenever you shoot an enemy ship." << endl;
			cout << "Controls are WASD to move and SPACEBAR to shoot." << endl;
			cout << "Press Enter to Begin" << endl;
			Sleep(1000);
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) {

			}
			spaceship->runSpaceDefender();

			cout << "Game Over" << endl;
			cout << "Score: ";
			cout << spaceship->score << endl;
		}
		if (selection == "2") {
			cout << "Welcome to Space Defender 2!" << endl;
			cout << "The objective of the game is to shoot down as many ships as possible." << endl;
			cout << "If your ship collides with an enemy ship or an enemy reaches the bottom of the screen, its Game Over." << endl;
			cout << "The game's difficulty increases slightly whenever you kill an enemy ship." << endl;
			cout << "Your ship has two waepon types: Machine Gun and Missiles." << endl;
			cout << "You can only change your weapon when you are not shooting." << endl;
			cout << "Each new game will have a different set of enemies that behave in a different way" << endl;
			cout << "Controls are WASD to move and SPACEBAR to shoot, and Z to change your weapon." << endl;
			cout << "Press Enter to Begin" << endl;
			Sleep(1000);
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) {

			}
			two->runSpaceDefender();
		}
		if (selection == "3") {
			cout << "Welcome to Space Defender 3!" << endl;
			cout << "The objective of the game is to shoot down as many ships as possible." << endl;
			cout << "If your ship collides with an enemy ship or an enemy reaches the bottom of the screen, its Game Over." << endl;
			cout << "The game's difficulty increases slightly whenever you kill an enemy ship." << endl;
			cout << "Your ship has two waepon types: Machine Gun and Missiles." << endl;
			cout << "You can only change your weapon when you are not shooting." << endl;
			cout << "Each new game will have a different set of enemies that behave in a different way" << endl;
			cout << "Controls are WASD to move and SPACEBAR to shoot, and Z to change your weapon." << endl;
			cout << "Press Enter to Begin" << endl;
			Sleep(1000);
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) {

			}
			three->runSpaceDefender();
		}
		if (selection == "0") {
			break;
		}


	}
	glfwTerminate;
	exit(EXIT_SUCCESS);
	return 0;
}
