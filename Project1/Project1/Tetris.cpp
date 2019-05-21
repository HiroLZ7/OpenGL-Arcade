#include <iostream>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include<stdio.h>
#include <Windows.h>
#include <math.h>
#include "mmSystem.h"

void genRandomColor(float *r, float *g, float *b) {
	*r = rand();
	*g = rand();
	*b = rand();
}

int oof(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window = glfwCreateWindow(480, 480, "Tetris", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	float r = 0;
	float g = 0;
	float b = 0;
	float x = 0.5;
	float y = -.2;
	bool ballLeft = true;
	bool ballDown = true;


	const float DEG2RAD = 3.14159 / 180;
	while (!glfwWindowShouldClose(window)) {
		//setup
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw
		if (ballLeft) {
			if (x > -1+.265) {
				x -= 0.01;
			}
			else {
				ballLeft = false;
			}
		}
		else {
			if (x < 1 - .265) {
				x += 0.01;
			}
			else {
				ballLeft = true;
			}
		}

		if (ballDown) {
			if (y > -1 + .265) {
				y -= 0.01;
			}
			else {
				ballDown = false;
			}
		}
		else {
			if (y < 1 - .265) {
				y += 0.01;
			}
			else {
				ballDown = true;
			}
		}

		//genRandomColor(&r, &g, &b);
		r = fmod(r + 0.01, 1);
		g = fmod(g + 0.02, 1);
		b = fmod(b + 0.03, 1);
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		
		for (int i = 0; i < 360; i++) {
			float deginRad = i * DEG2RAD;
			glVertex3f(cos(deginRad)*.25 + x, sin(deginRad)*.25+ y, 1);
		}
		glEnd();

		//Check For Events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate;
	exit(EXIT_SUCCESS);
}