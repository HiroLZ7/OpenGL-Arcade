#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"
float p1y = 0.2;
float p2y = 0.2;
float ballx = -0.02;
float bally = 0.02;
float ballw = 0.04;
float ballh = 0.04;
float ballspeedy = 0.00;
float ballspeedx = -0.01;
float paddlelength = 0.4;
float speedmodifier = 1;
using namespace std;
void makenoise(void)
{
	char random = '0' + ceil((rand() % 2) + 1);
	cout << "test " << random << " end";
	char arraya[14] = { 'h','i','t','s','o','u','n','d',random,'.','w','a','v'/*(char)rand() % 1*/ };
	PlaySound(TEXT(arraya), NULL, SND_ASYNC);

}
bool detectballcollision(void) {
	if ((ballx + ballspeedx > 0.96  && bally >= p1y - paddlelength && bally <= p1y + ballh / 2) ) {
		if (bally > p1y - paddlelength / 2) {
			ballspeedy =  1*(fabs((p1y - paddlelength/2) - bally))/10+0.005;
		}
		else {
			ballspeedy =  -1*(fabs((p1y - paddlelength/2) - bally))/10-0.005;
		}
		std::cout << fabs((p1y - paddlelength / 2) - bally) << "   ";

		ballx = 0.955;
		return true;
	}
	if ((ballx - ballspeedx < -0.96  && bally >= p2y - paddlelength && bally <= p2y + ballh / 2)) {
		if (bally > p2y - paddlelength / 2) {
			ballspeedy =  1*(fabs((p2y - paddlelength/2) - bally))/10+0.005;
		}
		else {
			ballspeedy =  -1*(fabs((p2y - paddlelength/2) - bally))/10-0.005;
		}
		std::cout << fabs((p2y - paddlelength / 2) - bally)<<"   ";
		ballx = -0.955;
		return true;
	}
	return false;
}

int main(void)
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
	GLFWwindow* window = glfwCreateWindow(480, 480, "PONG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {
		//p1y = bally + paddlelength / 2;
	//	p2y = bally + paddlelength / 2;

		//do math
		if (bally<-0.99 || bally>0.99) {
			ballspeedy = ballspeedy * -1;
			bally = bally + ballspeedy * 3;
			makenoise();
		}
		if (ballx > 1 || ballx < -1) {
			 ballx = -0.02;
			 bally = 0.02;
			 PlaySound(TEXT("scoresound.wav"), NULL, SND_ASYNC);
		}
		if (detectballcollision()==true) {
			makenoise();
			ballspeedx = ballspeedx * -1;
		}
		ballx = ballx + ballspeedx;
		bally = bally + ballspeedy;



		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window,&width,&height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		//Key Detection
		if (GetKeyState('W') & 0x8000) {
			if (p2y + 0.03 < 1) {
				p2y = p2y + 0.03;
			}
		}
		if (GetKeyState('S') & 0x8000) {
			if (p2y - 0.03 > -1+paddlelength) {
				p2y = p2y - 0.03;
			}
		}
		if (GetKeyState(VK_UP) & 0x8000) {
			if (p1y + 0.03 < 1) {
				p1y = p1y + 0.03;
			}
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			if (p1y - 0.03 > -1+paddlelength) {
				p1y = p1y - 0.03;
			}
		}
		//Drawing
		glBegin(GL_QUADS);
		glVertex2f(0.96,p1y);
		glVertex2f(0.99,p1y);
		glVertex2f(0.99,p1y-paddlelength);
		glVertex2f(0.96,p1y-paddlelength);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(-0.96, p2y);
		glVertex2f(-0.99, p2y);
		glVertex2f(-0.99, p2y-paddlelength);
		glVertex2f(-0.96, p2y-paddlelength);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(ballx, bally);
		glVertex2f(ballx+ballw,bally);
		glVertex2f(ballx+ballw,bally-ballh);
		glVertex2f(ballx, bally-ballh);
		glEnd();
		//Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
	};
	glfwDestroyWindow(window);
	glfwTerminate;
	exit(EXIT_SUCCESS);
}
