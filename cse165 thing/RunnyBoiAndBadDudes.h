#pragma once/*
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
	void setXvel();
	void setYvel();
	void setXvel(float);
	void setYvel(float);
	void setXcoord();
	void setYcoord();


	RunnyBoiAndBadDudes() {
		xinitial = 0;
		xCoord = -0.50;
		yCoord = 0.0;
		midAir = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -.60;
		triangle = false;
		currentfloor = 0.0;
	}


	RunnyBoiAndBadDudes(int a, int b) {// a is the number in the chain and b is the chain length
		xinitial = 1.5 + ((a - 1)*0.15);
		yCoord = 0.0;
		collision = true;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -.60;
		triangle = true;
		chain = b;
	}


	~RunnyBoiAndBadDudes();

};

#endif*/
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
	void setXvel();
	void setYvel();
	void setXvel(float);
	void setYvel(float);
	void setXcoord();
	void setYcoord();


	RunnyBoiAndBadDudes() {
		xinitial = 0;
		xCoord = -0.50;
		yCoord = 0.0;
		midAir = false;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -9.8;
		triangle = false;
		currentfloor = 0.0;
	}


	RunnyBoiAndBadDudes(int a, int b) {// a is the number in the chain and b is the chain length
		xinitial = 1.5 + ((a - 1)*0.15);
		yCoord = 0.0;
		collision = true;
		xVelocity = 0.0;
		yVelocity = 0.0;
		time = 0.0;
		acceleration = -.60;
		triangle = true;
		chain = b;
	}


	~RunnyBoiAndBadDudes();

};

#endif