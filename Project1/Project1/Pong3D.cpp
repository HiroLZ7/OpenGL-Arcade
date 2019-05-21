#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"
#include "Pong3D.h"

using namespace std;

Pong3D::Pong3D() {
	 p1score = 0;
	 p2score = 0;
	 p1y = 0.2;
	 p2y = 0.2;
	 ballx = -0.02;
	 bally = 0.02;
	 ballw = 0.04;
	 ballh = 0.04;
	 ballspeedy = 0.00;
	 ballspeedx = -0.01;
	 paddlelength = 0.4;
	 speedmodifier = 1;
}



void Pong3D::DrawPaddle(GLfloat posx,GLfloat posy, GLfloat posz,GLfloat length,GLfloat width,GLfloat height)
{
	GLfloat vertices[] =
	{
		//top face-----------

		posx,posy,posz + height,//top left
		posx + width,posy,posz + height,//top right
		posx + width,posy - length,posz + height,//bottom right
		posx,posy-length,posz + height,	//bottom left

		//bottom face----------------

		posx,posy,posz,//top left
		posx + width,posy,posz,//top right
		posx+width,posy-length,posz,//bottom right
		posx,posy-length,posz,//bottom left

		//right face------------------
		
		posx+width,posy-length,posz+height,//top left
		posx+width,posy,posz+height,//top right
		posx+width,posy,posz,//bottom right
		posx+width,posy-length,posz,//bottom left

		//left face------------------
		posx,posy,posz+height,//top left
		posx,posy - length,posz+height,//top right
		posx,posy-length,posz,//bottom right
		posx,posy,posz,//bottom left

		//front face------------------
		posx+width,posy,posz+height,//top left
		posx,posy,posz+height,//top right
		posx,posy,posz,//bottom right
		posx + width,posy,posz,//bottom left

		//back face------------------
		posx,posy-length,posz+height,//top left
		posx+width,posy-length,posz+height,//top right
		posx + width,posy - length,posz,//bottom right
		posx,posy - length,posz,	//bottom left
	};
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Pong3D::makenoise(void)
{
	char random = '0' + ceil((rand() % 2) + 1);
	//cout << "test " << random << " end";
	char arraya[14] = { 'h','i','t','s','o','u','n','d',random,'.','w','a','v'/*(char)rand() % 1*/ };
	PlaySound(TEXT(arraya), NULL, SND_ASYNC);

}

bool Pong3D::detectballcollision(void) {
	if (bally<-0.99 || bally>0.99) {
		ballspeedy = ballspeedy * -1;
		bally = bally + ballspeedy * 3;
		makenoise();
	}
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

int Pong3D::runPong(void)
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
		
		if (ballx > 1 || ballx < -1) {
			if (ballx > 1) {
				p2score = p2score + 1;
			}
			else 
			{
				p1score = p1score + 1;
			}
			
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

		//Players
		DrawPaddle(0.96,p1y,0,paddlelength,0.03,0.03);
		DrawPaddle(-0.99, p2y, 0, paddlelength, 0.03, 0.03);
		//Ball
		DrawPaddle(ballx,bally,0,ballw,ballw,ballw);
		//Swap buffer and check for events
		glfwSwapBuffers(window);
		glfwPollEvents();
		if (p1score > 6 || p2score > 6) {
			break;
			//glfwTerminate;
			//exit(EXIT_SUCCESS);
		}

	};
	glfwDestroyWindow(window);
	//glfwTerminate;
	//exit(EXIT_SUCCESS);
}
