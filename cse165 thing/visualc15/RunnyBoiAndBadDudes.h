#pragma once
#ifndef RunnyBoiAndBadDudes_hpp
#define RunnyBoiAndBadDudes_hpp
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
class RunnyBoiAndBadDudes {
	public:
		RunnyBoiAndBadDudes();
		//RunnyBoiAndBadDudes(){};
		float time;
		float acceleration;
		float xCoord;
		float yCoord;
		float xVelocity;
		float yVelocity;
		float xinitial;
		float currentfloor;

		bool midAir;
		bool collision;
		bool triangle;


		int chain;


		void draw();
		void setXvel(float);
		void setYvel(float);
		void setXcoord();
		void setYcoord();
		void setAcceleration(float);

		

		~RunnyBoiAndBadDudes();
		
	};

#endif