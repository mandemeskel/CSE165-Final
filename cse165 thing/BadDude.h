#pragma once
#include "RunnyBoiAndBadDudes.h"
#ifndef BadDude_hpp
#define BadDude_hpp
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <cmath>

class BadDude : public RunnyBoiAndBadDudes {
public:
	int chain;
	

	void draw() {
		float length = 0.15;
		float height = (sqrt(3) / 2)*length;
		glColor3f(0, 0, 0);
		glBegin(GL_TRIANGLES);
		glVertex3f(xCoord, yCoord, 0);
		glVertex3f(xCoord + length, yCoord, 0);
		glVertex3f(xCoord + (length / 2), yCoord + height, 0);
		glEnd();
	}

	BadDude(int a, int b) {
		xinitial = 1.2 + ((a - 1)*0.151);
		yCoord = 0.0;
		collision = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = 0;
		//triangle = tri;
		chain = b;
	}

	~BadDude() {}


};


#endif