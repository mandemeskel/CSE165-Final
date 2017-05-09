#include <iostream>
#include "RunnyBoiAndBadDudes.h"


	RunnyBoiAndBadDudes::RunnyBoiAndBadDudes(){
		currentfloor = 0.0f;
	}
	RunnyBoiAndBadDudes::RunnyBoiAndBadDudes(int a, int b, bool c) {

	}


	void RunnyBoiAndBadDudes::draw(){

	}
	void RunnyBoiAndBadDudes::setXvel(float x = 1.0) {
		xVelocity = x;
	}


	void RunnyBoiAndBadDudes::setYvel(float y = 0.75) {
		yVelocity = y;
	}


	void RunnyBoiAndBadDudes::setXcoord() {
		xCoord = xinitial + xVelocity*time + 0.5*acceleration*time*time;
	}


	void RunnyBoiAndBadDudes::setYcoord() {
		yCoord = currentfloor + (yVelocity*time + 0.5*acceleration*time*time);
	}

	void RunnyBoiAndBadDudes::setAcceleration(float a) {
		acceleration = a;
	}

	RunnyBoiAndBadDudes::~RunnyBoiAndBadDudes() {

	}



