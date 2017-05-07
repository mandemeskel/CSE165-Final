#include "RunnyBoiAndBadDudes.h"
#include<time.h>
#include<iostream>
#include<cmath>
#include"App.h"

RunnyBoiAndBadDudes::RunnyBoiAndBadDudes() {//for runny boi
	xinitial = 0;
	xCoord = -0.50;
	yCoord = 0.0;
	midAir = false;
	xVelocity = 0.0;
	yVelocity = 0.0;
	time = 0.0;
	acceleration = -8;
	triangle = false;
	currentfloor = 0.0;
}


RunnyBoiAndBadDudes::RunnyBoiAndBadDudes(int a, int b,bool tri) {// a is the number in the chain and b is the chain length
	xinitial = 1.2 + ((a - 1)*0.151);
	yCoord = 0.0;
	collision = false;
	xVelocity = 0.0;
	yVelocity = 0.0;
	time = 0.0;
	acceleration = 0;
	triangle = tri;
	chain = b;
}

void RunnyBoiAndBadDudes::setXvel(float x=1.0) {
	xVelocity = x;
}


void RunnyBoiAndBadDudes::setYvel(float y=0.75) {
	yVelocity = y;
}


void RunnyBoiAndBadDudes::setXcoord() {
	xCoord =xinitial+xVelocity*time + 0.5*acceleration*time*time;
}


void RunnyBoiAndBadDudes::setYcoord() {
	yCoord =currentfloor+(yVelocity*time + 0.5*acceleration*time*time);
}

void RunnyBoiAndBadDudes::setAcceleration(float a) {
	acceleration = a;
}

void RunnyBoiAndBadDudes::draw() {
	if (triangle) {//triangle
		float length = 0.15;
		float height = (sqrt(3) / 2)*length;
		glColor3f(0, 0, 0);
		glBegin(GL_TRIANGLES);
		glVertex3f(xCoord,yCoord,0);
		glVertex3f(xCoord + length,yCoord, 0);
		glVertex3f(xCoord + (length/2),yCoord+height,0);
		glEnd();
	}
	else {//square
		float xlength = 0.15;
		float ylength = 0.15;
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(xCoord + xlength, yCoord + ylength);
		glVertex2f(xCoord, yCoord + ylength);
		glVertex2f(xCoord, yCoord);
		glVertex2f(xCoord + xlength, yCoord);
		glEnd();
	}
}


RunnyBoiAndBadDudes::~RunnyBoiAndBadDudes(){
}
