#pragma once

#include "RunnyBoiAndBadDudes.h"
#ifndef runnyboi_hpp
#define runnyboi_hpp
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
# include <gsim/gs_vec.h>
# include <gsim/gs_image.h>
# include "ogl_tools.h"
#else
#include <GL/gl.h>
#endif


class runnyboi : public RunnyBoiAndBadDudes{
	public:
		
		bool midAir;
		float currentfloor;

	

	runnyboi(){
		xinitial = 0;
		xCoord = -0.70;
		yCoord = 0.0;
		midAir = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -8;
		triangle = false;
		currentfloor = 0.0;

		}

	void reset() {
		xCoord = -0.50;
		yCoord = 0.0;
		midAir = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -8;
		currentfloor = 0.0;
		}

		void draw() {
			float xlength = 0.15;
			float ylength = 0.15;
			glColor3f(0.2, .8, 0.3);
			
			glBegin(GL_POLYGON);
			glVertex2f(xCoord + xlength, yCoord + ylength);
			glVertex2f(xCoord, yCoord + ylength);
			glVertex2f(xCoord, yCoord);
			glVertex2f(xCoord + xlength, yCoord);
			glEnd();
		}

		~runnyboi() {}

	
};











#endif