#define _USE_MATH_DEFINES
#include "App.h"
#include <math.h>
#include<time.h>
#include<iostream>
#include<Windows.h>
#include<deque>
#include<stdlib.h>
using namespace std;

deque<RunnyBoiAndBadDudes> badBoiz;//double ended thingy to hold bad dudes

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
	runnyBoi = new RunnyBoiAndBadDudes();// make the dude
    // Initialize state variables
	currentFloor = 0.0;
	stopGame = false;
}

void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set background color to black
    glClearColor(1.0, 1.0, 1.0, 0.0);
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


	glBegin(GL_LINES);//temp line for the floor
	glVertex2f(-1, 0-.15);
	glVertex2f(1, 0-.15);
	glEnd();
	
	
	for (int i = 0; i < badBoiz.size(); i++) {//draw the bad guys
		badBoiz[i].draw();
	}

	runnyBoi->draw();//draw the main guy
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete this;
        exit(0);
    }
	else if (key == 32) {//spacebar
		if (runnyBoi->midAir == false) {
			runnyBoi->midAir = true;
			runnyBoi->setYvel(2);
		}
	}
	else if (key == 48) {
		currentFloor += 0.01;
		std::cout << currentFloor << std::endl;
	}
	else if (key == 49) {
		RunnyBoiAndBadDudes badguy(0, 1);
		badguy.acceleration = 0;
		badguy.setXvel(-1.5);
		badguy.xCoord = 1.5;
		badBoiz.push_back(badguy);
		std::cout << "made a dude" << std::endl;
	}
	else if (key == 50) {
		currentFloor -= 0.01;
		std::cout << currentFloor << std::endl;
	}
	else if (key == 51) {
		stopGame = false;
	}
}

void App::idle(){
	if (stopGame == false) {
		runnyBoi->currentfloor = currentFloor;
		if (runnyBoi->midAir == true)//if main guy is off the "ground" 
			if (currentFloor + ((((runnyBoi->yVelocity*(runnyBoi->time + .1)) + (0.5*runnyBoi->acceleration)*(runnyBoi->time + .1)*(runnyBoi->time + .1))) / 1.3) < currentFloor)//prevents him from clipping the floor set at Y=0;
				runnyBoi->time += .001;
			else
				runnyBoi->time += .001;

		runnyBoi->setYcoord();
		if (runnyBoi->yCoord < currentFloor) {//make sure he doesnt fall through the floor( I set floor at Y=0)
			runnyBoi->time = 0;
			runnyBoi->yCoord = currentFloor;
			runnyBoi->midAir = false;
		}




		/*
		srand(clock());//randomize
		int chain = rand() % 4;//pick a number between 0 and 3 inclusive
		if ((badBoiz.size()>0&&( badBoiz.back().xCoord<(badBoiz.back().xinitial-((badBoiz.back().chain+1)*.15)))) ||badBoiz.size()==0) { //some crazy ass statement for making sure things dont overlap and to ensure there is a free space after a 3 chain
			for (int i = 0; i < chain; i++) {//make a chain of enemies
				RunnyBoiAndBadDudes badguy(i, chain);
				badguy.acceleration = 0;
				badguy.setXvel(-0.1);
				badguy.xCoord = 1;
				badBoiz.push_back(badguy);
			}
		}

		*/
		for (int i = 0; i < badBoiz.size(); i++) {//loop and set the coordinates for the next frame for each guy
			badBoiz[i].time += .001;
			badBoiz[i].setXcoord();
		}

		float deltaX;
		for (int i = 0; i < badBoiz.size(); i++) {
			if ((badBoiz[i].xCoord <= runnyBoi->xCoord + .15 && badBoiz[i].xCoord >= runnyBoi->xCoord) || (badBoiz[i].xCoord + 0.15 >= runnyBoi->xCoord && badBoiz[i].xCoord + 0.15 <= runnyBoi->xCoord + 0.15)) {
				float slope = sqrt(3);
				float b = badBoiz[i].yCoord;
				deltaX = -.37 - badBoiz[i].xCoord;
				if (badBoiz[i].xCoord + .075 < runnyBoi->xCoord) {
					slope = -sqrt(3);
					b = .13 + badBoiz[i].yCoord;
					deltaX = (runnyBoi->xCoord - badBoiz[i].xCoord - .075);
				}
				float line = slope*(deltaX)+b;
				if (deltaX >= .075)
					line = .13 + badBoiz[i].yCoord;
				//std::cout << "we have X contact at" << badBoiz[i].xCoord << "\n" <<"deltax"<<-.37-badBoiz[i].xCoord<<"\n";
				//std::cout << " line equation is y=" << slope << "x+" << b << std::endl;
				//std::cout << "box y coord is " << runnyBoi->yCoord << std::endl;
				//std::cout << "triange y coord is " << line << std::endl;
				//std::cout << deltaX << std::endl;

				if (line <= runnyBoi->yCoord + .001 && line >= runnyBoi->yCoord - 0.001) {
					redraw();
					stopGame = true;
				}
			}

		}

		if (badBoiz.size() > 0 && badBoiz[0].xCoord < -2)//if theyre off the screen remove them from the queue
			badBoiz.pop_front();


		redraw();// redraw
		Sleep(.5);// Windows specific Sleep timer, use this to control the render rate of the program
	}
}

App::~App(){
	delete runnyBoi;//kill him
}
