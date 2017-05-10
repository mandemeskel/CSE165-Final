#pragma once
#include "RunnyBoiAndBadDudes.h"
#ifndef BadCircle_hpp
#define BadCircle_hpp
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>


class BadCircle : public RunnyBoiAndBadDudes {
public:
	BadCircle() {
		xinitial = 1.2;
		yCoord = 0.58;
		collision = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = 0;
	}


	void draw() {
		int sides = 20;
		float radius = 0.05f;
		glColor3f(0, 0, 0);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 360; i += 360 / sides) {
			float heading = i * M_PI / 180;
			glVertex2f(xCoord + cos(heading) * radius, yCoord + sin(heading) * radius);
			}
		glEnd();
	}



	~BadCircle() {}


};


#endif