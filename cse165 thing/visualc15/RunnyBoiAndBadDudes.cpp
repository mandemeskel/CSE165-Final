#include "RunnyBoiAndBadDudes.h"
#include<time.h>
#include<iostream>
#include<cmath>
#include"App.h"

void RunnyBoiAndBadDudes::setXvel() {
	yVelocity = 1.0;
}


void RunnyBoiAndBadDudes::setYvel() {
	yVelocity = 0.75;
}


void RunnyBoiAndBadDudes::setXvel(float x) {
	xVelocity = x;
}


void RunnyBoiAndBadDudes::setYvel(float y) {
	yVelocity = y;
}


void RunnyBoiAndBadDudes::setXcoord() {
	xCoord =xinitial+xVelocity*time + 0.5*acceleration*time*time;
}


void RunnyBoiAndBadDudes::setYcoord() {
	yCoord =currentfloor+(yVelocity*time + 0.5*acceleration*time*time)/1.3;
}


void RunnyBoiAndBadDudes::draw() {
	if (triangle) {//triangle
		float length = 0.15;
		float height = (sqrt(3) / 2)*length;
		glColor3f(0, 0, 0);
		glBegin(GL_TRIANGLES);
		glVertex3f(xCoord,0-length,0);
		glVertex3f(xCoord + length,0-length, 0);
		glVertex3f(xCoord + (length/2),height-length,0);
		glEnd();
	}
	else {//square
		float xlength = 0.15;
		float ylength = 0.15;
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(xCoord + xlength, yCoord - ylength);
		glVertex2f(xCoord, yCoord - ylength);
		glVertex2f(xCoord, yCoord);
		glVertex2f(xCoord + xlength, yCoord);
		glEnd();
	}
}


RunnyBoiAndBadDudes::~RunnyBoiAndBadDudes(){
}
