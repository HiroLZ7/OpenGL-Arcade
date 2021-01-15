
#include "SpaceShip.h"
float bulletX;
float bulletY;
float x = 0;
float y = -.89;
float enemy1X = 0;
float enemy1Y = 0;
bool drawEnemy1 = true;
float enemy2X = .5;
float enemy2Y = 0;
bool drawEnemy2 = true;
float enemy3X = -.5;
float enemy3Y = 0;
bool drawEnemy3 = true;
bool contBullet = false;
float increment = 0;
bool isKilled = false;
float incrementENemy = .001;
int score = 0;
//float x = 0;
//float y = 0;


SpaceShip::SpaceShip() {
	bulletX;
	bulletY;
	x = 0;
	y = -.89;
	enemy1X = 0;
	enemy1Y = 0;
	drawEnemy1 = true;
	enemy2X = .5;
	enemy2Y = 0;
	drawEnemy2 = true;
	enemy3X = -.5;
	enemy3Y = 0;
	drawEnemy3 = true;
	contBullet = false;
	increment = 0;
	isKilled = false;
	incrementENemy = .001;
	score = 0;
}

void SpaceShip::drawEnemyOne(bool drawEnem) {
	if (drawEnem) {
		glColor3f(0, 1, .3);
		glBegin(GL_POLYGON);
		glVertex3f(0 + enemy1X, 0 + enemy1Y, 0);
		glVertex3f(0 + enemy1X - .08, 0 + enemy1Y + .11, 0);
		glVertex3f(0 + enemy1X, 0 + enemy1Y - .05, 0);
		glVertex3f(0 + enemy1X + .08, 0 + enemy1Y + .11, 0);
		glEnd();
	}
}

void SpaceShip::drawEnemyTwo(bool drawEnem) {
	if (drawEnem) {
		glColor3f(0, 1, .3);
		glBegin(GL_POLYGON);
		glVertex3f(0 + enemy2X, 0 + enemy2Y, 0);
		glVertex3f(0 + enemy2X - .08, 0 + enemy2Y + .11, 0);
		glVertex3f(0 + enemy2X, 0 + enemy2Y - .05, 0);
		glVertex3f(0 + enemy2X + .08, 0 + enemy2Y + .11, 0);
		glEnd();
	}
}

void SpaceShip::drawEnemyThree(bool drawEnem) {
	if (drawEnem) {
		glColor3f(0, 1, .3);
		glBegin(GL_POLYGON);
		glVertex3f(0 + enemy3X, 0 + enemy3Y, 0);
		glVertex3f(0 + enemy3X - .08, 0 + enemy3Y + .11, 0);
		glVertex3f(0 + enemy3X, 0 + enemy3Y - .05, 0);
		glVertex3f(0 + enemy3X + .08, 0 + enemy3Y + .11, 0);
		glEnd();
	}
}

void SpaceShip::moveEnemy() {
	enemy1Y -= incrementENemy;
	enemy2Y -= incrementENemy;
	enemy3Y -= incrementENemy;
}

void SpaceShip::drawShip() {
	glColor3f(.7, .05, .03);
	glBegin(GL_POLYGON);
	glVertex3f(0 + x, 0 + y, 0);
	glVertex3f(0 + x - .08, 0 + y - .11, 0);
	glVertex3f(0 + x, 0 + y - .05, 0);
	glVertex3f(0 + x + .08, 0 + y - .11, 0);
	glEnd();
	if (((x + .04 <= enemy1X + .04) && (x + .04 >= enemy1X - .04) || (x - .04 <= enemy1X + .04) && (x - .04 >= enemy1X - .04)) && (y >= enemy1Y - .05) && (y <= enemy1Y)) {
		isKilled = true;
		//PlaySound("explosion.wav", NULL, SND_ASYNC);
	}
	if (((x + .04 <= enemy2X + .04) && (x + .04 >= enemy2X - .04) || (x - .04 <= enemy2X + .04) && (x - .04 >= enemy2X - .04)) && (y >= enemy2Y - .05) && (y <= enemy2Y)) {
		isKilled = true;
		//PlaySound("explosion.wav", NULL, SND_ASYNC);
	}
	if (((x + .04 <= enemy3X + .04) && (x + .04 >= enemy3X - .04) || (x - .04 <= enemy3X + .04) && (x - .04 >= enemy3X - .04)) && (y >= enemy3Y - .05) && (y <= enemy3Y)) {
		isKilled = true;
		//PlaySound("explosion.wav", NULL, SND_ASYNC);
	}
}

void SpaceShip::MoveShip() {
	if (GetKeyState('W') & 0x8000) {
		if (y + 0.01 < 1) {
			y += 0.01;
		}
	}
	if (GetKeyState('S') & 0x8000) {
		if (y - 0.01 > -1) {
			y -= 0.01;
		}
	}
	if (GetKeyState('D') & 0x8000) {
		if (x + 0.01 < 1) {
			x += 0.01;
		}
	}
	if (GetKeyState('A') & 0x8000) {
		if (x - 0.01 > -1) {
			x -= 0.01;
		}
	}
}

void SpaceShip::genBullet() {
	if (GetKeyState(VK_SPACE) & 0x8000) {
		contBullet = true;
		//PlaySound("shoot.wav", NULL, SND_ASYNC);
		
	}
}

void SpaceShip::drawBullet(bool cont) {
	
	if (cont) {
		
		glColor3f(0, 1, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3f(x, y + increment, 0);
		glVertex3f(x, y + .1 + increment, 0);
		glEnd();
		increment += .1;
		if (increment >= 1.5) {
			increment = 0;
			contBullet = false;
		}
		if ((x <= enemy1X + .08) && (x >= enemy1X - .08) && (y + increment + .1 >= enemy1Y) && (y + increment + .1 <= enemy1Y + .11)) {
			drawEnemy1 = false;
			enemy1X = (float)(rand() % 200 - 100) / 100;
			enemy1Y = (float)(rand() % 100) / 100;
			incrementENemy += .0000001;
			//("invaderkilled.wav", NULL, SND_ASYNC);
			score++;
		}
		if ((x <= enemy2X + .08) && (x >= enemy2X - .08) && (y + increment + .1 >= enemy2Y) && (y + increment + .1 <= enemy2Y + .11)) {
			drawEnemy2 = false;
			enemy2X = (float)(rand() % 200 - 100) / 100;
			enemy2Y = (float)(rand() % 100) / 100;
			incrementENemy += .0000001;
			//PlaySound("invaderkilled.wav", NULL, SND_ASYNC);
			score++;
		}
		if ((x <= enemy3X + .08) && (x >= enemy3X - .08) && (y + increment + .1 >= enemy3Y) && (y + increment + .1 <= enemy3Y + .11)) {
			drawEnemy3 = false;
			enemy3X = (float) (rand() % 200 - 100)/100;
			enemy3Y = (float)(rand() % 100) / 100; 
			incrementENemy += .0000001;
			//PlaySound("invaderkilled.wav", NULL, SND_ASYNC);
			score++;
		}
	}
	
}


int SpaceShip::runSpaceDefender(void) {
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
	
	
	

	while (!glfwWindowShouldClose(window)) {
		
		//setup
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClearColor(.01, .01, .01, .5);
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw

		MoveShip();
		drawShip();
		genBullet();
		moveEnemy();
		drawEnemyOne(drawEnemy1);
		drawEnemyTwo(drawEnemy2);
		drawEnemyThree(drawEnemy3);
		drawBullet(contBullet);
		if ((enemy1Y <= -1) || (enemy2Y <= -1) || (enemy3Y <= -1) || isKilled) {
			break;
		}
		
		
		
		drawEnemy1 = true;
		drawEnemy2 = true;
		drawEnemy3 = true;
		//Check For Events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	/*glfwTerminate;
	exit(EXIT_SUCCESS);*/
	
}