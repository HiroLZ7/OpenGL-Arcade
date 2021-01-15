#include "SpaceShipFour.h"

#define LOOPTIME 2
typedef std::chrono::milliseconds ms;


SpaceShipFour::SpaceShipFour(int diff,SaveState *sd) {
	saveData = sd;
	ship = new CustomShip(saveData);
	dific = diff;
	score = 0;
	kills = 0;
	enemyTypes = 10;
	bossTypes = 5;
	diffMult = .1 * dific;
	gameover = false;
	bossRun = false;
}

void SpaceShipFour::generateEnemyProfiles() {
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
		enemyProfiles.at(enemyPos).setEnemyXY(enemyX, enemyY);
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
			y = ((rand() % 10) + 2) * .01;
			x = ((rand() % 9) + 2) * .01;
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

void SpaceShipFour::generateBossProfiles() {
	for (int bossPos = 0; bossPos < bossTypes; bossPos++) {
		//Adds an enemy object to the bank of enemy types
		Enemy enemy;
		srand((unsigned int)time(NULL) * (bossPos + 1));
		bossProfiles.push_back(enemy);
		int health = rand() % 100000 + 10000;
		float increm = ((1.0 / health)) * diffMult;
		float enemyX = 0;
		float enemyY = .8;
		int vertexCnt = ((rand() % 8) + 3);
		//creates a randomized color pallete
		float r = (rand() % 971 + 30) * .001;
		float g = (rand() % 971 + 30) * .001;
		float b = (rand() % 971 + 30) * .001;
		bossProfiles.at(bossPos).setHealth(health);
		bossProfiles.at(bossPos).setScore();
		bossProfiles.at(bossPos).setEnemyIncrement(increm);
		bossProfiles.at(bossPos).setEnemyXY(enemyX, enemyY);
		bossProfiles.at(bossPos).setVertexCount(vertexCnt);
		bossProfiles.at(bossPos).setRGB(r, g, b);
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
					y = ((rand() % 200) + 50) * .07;
					offY.push_back(y);
					++vtx;
				}
			}
			y = ((rand() % 220) + 50) * .07;
			x = ((rand() % 200) + 50) * .07;
			offX.push_back(x);
			offY.push_back(y);
			offX.push_back(-x);
			offY.push_back(y);
			++vtx;
		}

		bossProfiles.at(bossPos).setOffsets(offX, offY);
		bossProfiles.at(bossPos).sortVectors();
	}



}


void SpaceShipFour::drawExplosion(float x, float y) {
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
			glVertex3f(x + (multiplier * cos(deg2rad * angle)), y + (multiplier * sin(deg2rad * angle)), 0);
			glEnd();
		}
		eG = frame == 0 ? .56 : .011;
		eB = .0588;
		adjustor += .00125;

	}

}

void SpaceShipFour::loadEnemies(int difVar) {
	for (int e = 0; e < difVar + 2; e++) {
		loadEnemy(difVar);
	}
}

void SpaceShipFour::loadEnemy(int difVar) {
	int enemyNo = rand() % 10;
	activeEnemies.push_back(enemyProfiles.at(enemyNo));
	float enemyX = ((rand() % 200 - 100) / 100.0);
	float enemyY = ((rand() % 100) / 100.0);
	enemyProfiles.at(enemyNo).setEnemyXY(enemyX, enemyY);
	enemyProfiles.at(enemyNo).setEnemyIncrement(enemyProfiles.at(enemyNo).enemyIncrement + (difVar * .0000001 * kills));
}

void SpaceShipFour::loadBoss(int difVar) {
	int bossNo = rand() % 5;
	activeEnemies.clear();
	bossProfiles.at(bossNo).setEnemyIncrement(bossProfiles.at(bossNo).enemyIncrement + (difVar * .00001 * kills));
	activeEnemies.push_back(bossProfiles.at(bossNo));
}

void SpaceShipFour::processCollisions(bool &isBoss, int difVar) {
	for (int e = 0; e < activeEnemies.size(); e++) {
		//check for bullet collision
		float eYmin = activeEnemies.at(e).minYoffset() + activeEnemies.at(e).enemyY;
		float eYmax = activeEnemies.at(e).maxYoffset() + activeEnemies.at(e).enemyY;
		float eXmin = activeEnemies.at(e).minXoffset() + activeEnemies.at(e).enemyX;
		float eXmax = activeEnemies.at(e).maxXoffset() + activeEnemies.at(e).enemyX;
		for (size_t b = 0; b < ship->projectileBuffer.size(); b++) {
			float bulletY = (ship->projectileBuffer.at(b).getWeaponType() == "BULLET") ? ship->projectileBuffer.at(b).getBulletY() + .05 + ship->projectileBuffer.at(b).getIncrement() : ship->projectileBuffer.at(b).getBulletY() + .1 + ship->projectileBuffer.at(b).getIncrement();
			float bulletX = ship->projectileBuffer.at(b).getBulletX();
			if ((eYmin <= bulletY && bulletY <= eYmax) && (eXmin <= bulletX && bulletX <= eXmax)) {
				int eHealth = activeEnemies.at(e).getHealth();
				activeEnemies.at(e).setHealth(eHealth - ship->projectileBuffer.at(b).getDamage());
				ship->projectileBuffer.erase(ship->projectileBuffer.begin() + b);
				if (activeEnemies.at(e).getHealth() <= 0) {
					for (int anim = 0; anim < 10; anim++) {
						drawExplosion((eXmin + eXmax) / 2.0, (eYmin + eYmax) / 2.0);
					}
					int s = activeEnemies.at(e).scoreval;
					score += s;
					kills++;
					activeEnemies.erase(activeEnemies.begin() + e);
					//delte current ship from active enemy vector
					if (isBoss) {
						loadEnemies(difVar);
						isBoss = false;
					}
					else { loadEnemy(difVar); }



				}
			}
		}
		//check for ship collision
		if ((eYmin <= ship->getShipY() && ship->getShipY() <= eYmax) && (eXmin <= ship->getShipX() && ship->getShipX() <= eXmax)) {
			gameover = true;
		}
		//check for boundary collision
		if (activeEnemies.at(e).enemyY <= -1) {
			gameover = true;
		}
	}
}

int SpaceShipFour::runSpaceDefender(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Space Defender 4", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	ms looptime;
	generateEnemyProfiles();
	generateBossProfiles();
	loadEnemies(dific);
	bool is_Boss = false;
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
		int prevKills = kills;
		processCollisions(is_Boss, dific);
		if ((prevKills != kills) && (kills) % 100 == 0) {
			loadBoss(1);
			is_Boss = true;
		}
		ship->updateShip();
		for (int m = 0; m < activeEnemies.size(); m++) {
			activeEnemies.at(m).moveEnemy();
			activeEnemies.at(m).drawEnemy();
		}
		//bossProfiles.at(0).moveEnemy();
		//bossProfiles.at(0).drawEnemy();
		if (gameover || glfwWindowShouldClose(window)) {
			score *= dific;
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