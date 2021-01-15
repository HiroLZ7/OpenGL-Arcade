#include "SpaceShipTwo.h"
#define LOOPTIME 10
typedef std::chrono::milliseconds ms;


SpaceShipTwo::SpaceShipTwo() {
	ship = new Ship();
	score = 0;
	kills = 0;
	enemyTypes = 10;
	diffMult = .1;
	gameover = false;
}

void SpaceShipTwo::generateEnemyProfiles() {
	for (int enemyPos = 0; enemyPos < enemyTypes; enemyPos++) {
		//Adds an enemy object to the bank of enemy types
		Enemy enemy;
		srand((unsigned int)time(NULL) * (enemyPos + 1));
		enemyProfiles.push_back(enemy);
		int health = rand() % 100 + 1;
		float increm = ((1.0 / health) * .1) * diffMult;
		float enemyX = ((rand() % 200 - 100) / 100.0);
		float enemyY = ((rand() % 100) / 100.0);
		int vertexCnt = ((rand() % 8) + 3);
		//creates a randomized color pallete
		float r = (rand() % 971 + 30) * .001;
		float g = (rand() % 971 + 30) * .001;
		float b = (rand() % 971 + 30) * .001;
		enemyProfiles.at(enemyPos).setHealth(health);
		enemyProfiles.at(enemyPos).setScore();
		enemyProfiles.at(enemyPos).setEnemyIncrement(increm);
		enemyProfiles.at(enemyPos).setEnemyXY(enemyX,enemyY);
		enemyProfiles.at(enemyPos).setVertexCount(vertexCnt);
		enemyProfiles.at(enemyPos).setRGB(r, g, b);
		std::vector<float> offX;
		std::vector<float> offY;
		for (int vtx = 0; vtx < vertexCnt; vtx++) {
			float x;
			float y;
			if (vtx == 0) {
				offX.push_back(0);
				offY.push_back(0);
				++vtx;
				if (vertexCnt % 2 == 0) {
					offX.push_back(0);
					y = ((rand() % 10) + 1) * .01;
					offY.push_back(y);
					++vtx;
				}
			}
			y = ((rand() % 11) + 1) * .01;
			x = ((rand() % 10) + 1) * .01;
			offX.push_back(x);
			offY.push_back(y);
			offX.push_back(-x);
			offY.push_back(y);
			++vtx;
		}
		
		enemyProfiles.at(enemyPos).setOffsets(offX, offY);
		enemyProfiles.at(enemyPos).sortVectors();
	}
	
	
}


void SpaceShipTwo::drawExplosion(float x, float y) {
	const float deg2rad = 3.14159 / 180;
	float eR = 1;
	float eG = 1;
	float eB = 1;
	float adjustor = .007;
	for (int frame = 0; frame < 3; frame++) {
		glColor3f(eR, eG, eB);
		for (int angle = 0; angle <= 360; angle++) {
			glBegin(GL_LINE_STRIP);
			float multiplier = ((rand() % 20) + 1) * (adjustor);
			
			glVertex3f(x, y, 0);
			glVertex3f(x + (multiplier * cos(deg2rad * angle)), y +(multiplier * sin(deg2rad * angle)), 0);
			glEnd();
		}
		eG = frame == 0 ? .56 : .011;
		eB = .0588;
		adjustor += .00125;
		
	}
		
}

void SpaceShipTwo::loadEnemies(int difVar) {
	for (int e = 0; e < difVar; e++) {
		loadEnemy();
	}
}

void SpaceShipTwo::loadEnemy() {
	int enemyNo = rand() % 10;
	activeEnemies.push_back(enemyProfiles.at(enemyNo));
	float enemyX = ((rand() % 200 - 100) / 100.0);
	float enemyY = ((rand() % 100) / 100.0);
	enemyProfiles.at(enemyNo).setEnemyXY(enemyX, enemyY);
	enemyProfiles.at(enemyNo).setEnemyIncrement(enemyProfiles.at(enemyNo).enemyIncrement + (.00001 * kills));
}

void SpaceShipTwo::processCollisions() {
	for (int e = 0; e < activeEnemies.size(); e++) {
		//check for bullet collision
		float bY = ship->useBullet ? ship->getBulletY() + .1 + ship->bulletIncrement : ship->getBulletY() + .1 + ship->missileIncrement;
		float bX = ship->getBulletX();
		float eYmin = activeEnemies.at(e).minYoffset() + activeEnemies.at(e).enemyY;
		float eYmax = activeEnemies.at(e).maxYoffset() + activeEnemies.at(e).enemyY;
		float eXmin = activeEnemies.at(e).minXoffset() + activeEnemies.at(e).enemyX;
		float eXmax = activeEnemies.at(e).maxXoffset() + activeEnemies.at(e).enemyX;
		if ((eYmin <= bY && bY <= eYmax) && (eXmin <= bX && bX <= eXmax)) {
			int eHealth = activeEnemies.at(e).getHealth();
			activeEnemies.at(e).setHealth(eHealth - ship->damage);
			ship->contBullet = false;
			ship->bulletIncrement = 0;
			ship->missileIncrement = 0;
			if (activeEnemies.at(e).getHealth() <= 0) {
				for(int anim = 0; anim < 10; anim++){
					drawExplosion((eXmin + eXmax) / 2.0, (eYmin + eYmax) / 2.0); 
				}
				int s = activeEnemies.at(e).scoreval;
				score += s;
				kills++;
				activeEnemies.erase(activeEnemies.begin() + e);
				//delte current ship from active enemy vector
				loadEnemy();
				
				
			}
		}
		//check for ship collision
		if ((eYmin <= ship->shipY && ship->shipY <= eYmax) && (eXmin <= ship->shipX && ship->shipX <= eXmax)) {
			gameover = true;
		}
		//check for boundary collision
		if (activeEnemies.at(e).enemyY <= -1) {
			gameover = true;
		}
	}
}

int SpaceShipTwo::runSpaceDefender(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Space Defender", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	ms looptime;
	generateEnemyProfiles();
	loadEnemies(3);
	while (!glfwWindowShouldClose(window)) {
		looptime = std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch());
		//setup
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClearColor(.01, .01, .01, .5);
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw
		processCollisions();
		ship->updateShip();
		for (int m = 0; m < activeEnemies.size(); m++) {
			activeEnemies.at(m).moveEnemy();
			activeEnemies.at(m).drawEnemy();
		}
		if (gameover || glfwWindowShouldClose(window)) {
			std::cout << "Game Over" << std::endl;
			std::cout << "Score: " << score << std::endl;
			std::cout << "Kills: " << kills << std::endl;
			break;
		}
		
		

		//Check For Events
		glfwSwapBuffers(window);
		glfwPollEvents();

		while (std::chrono::duration_cast<ms>(std::chrono::system_clock::now().time_since_epoch() - looptime).count() < LOOPTIME);
	}
	glfwDestroyWindow(window);
	/*glfwTerminate;
	exit(EXIT_SUCCESS);*/

}