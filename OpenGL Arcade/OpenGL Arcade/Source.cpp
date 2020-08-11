#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "SpaceShip.h"
#include "Pong3D.h"


using namespace::std;


string selection;
char cont = 'T';
string start;
int main() {
	while (cont == 'T') {
	SpaceShip* spaceship = new SpaceShip();
	Pong3D* pong3D = new Pong3D();
	cout << "Welcome to OpenGL Arcade" << endl;
	cout << "Please Select a Game" << endl;
	cout << "Space Defender (1)" << endl;
	cout << "Pong 3D (2)" << endl;
	cin >> selection;
	if (selection == "1") {
		cout << "Welcome to Space Defender!" << endl;
		cout << "The objective of the game is to shoot down as many ships as possible." << endl;
		cout << "If your ship collides with an enemy ship or an enemy reaches the bottom of the screen, its Game Over." << endl;
		cout << "The game's difficulty increases slightly whenever you shoot an enemy ship." << endl;
		cout << "Controls are WASD to move and SPACEBAR to shoot." << endl;
		cout << "Pres Enter to Begin" << endl;
		cin>>start;
		spaceship->runSpaceDefender();

		cout << "Game Over" << endl;
		cout << "Score: ";
		cout << spaceship->score << endl;
	}
	if (selection == "2") {
		cout << "Welcome to Pong 3D!" << endl;
		cout << "Controls ar WS for p1 and UP and DOWN arrows for p2." << endl;
		cout << "First to 7 wins" << endl;
		cout << "Pres Enter to Begin" << endl;
		cin >> start;
		pong3D->runPong();
		cout << "P1 Score: " << endl;
		cout << pong3D->p1score << endl;
		cout << "P2 Score: " << endl;
		cout << pong3D->p2score << endl;


	}
	
	cin >> cont;
}
	glfwTerminate;
	exit(EXIT_SUCCESS);
	return 0;
}
