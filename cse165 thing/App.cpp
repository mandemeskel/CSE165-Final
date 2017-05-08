#define _USE_MATH_DEFINES
#include "App.h"
#include <math.h>
#include<time.h>
#include <ctime>
#include <cstdio>
#include<iostream>
#include<Windows.h>
#include<deque>
#include<stdlib.h>
#include "Scoreboard.h"
#include <string>
#include <chrono>
#include <future>
using namespace std;

deque<BadDude> badBoiz;//double ended thingy to hold bad dudes
deque<runnyboi> boxs;


clock_t beginTime;

float noSpawnTime;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
	runnyBoi = new runnyboi();// make the dude
	currentFloor = 0.0;
	stopGame = false;
	beginTime = clock();
	noSpawnTime = rand() % 1 + 0.6;
	score = new Scoreboard();
	score->flipState();
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
	glVertex2f(-1, 0 );
	glVertex2f(1, 0 );
	glEnd();

	for (int i = 0; i < badBoiz.size(); i++) {//draw the bad guys
		badBoiz[i].draw();
	}
	for (int i = 0; i < boxs.size(); i++) {
		boxs[i].draw();
	}
	runnyBoi->draw();//draw the main guy
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew

	//Draws the score
	//drawScore("Score : " + to_string(score->getScore()), 80, 80);

    glFlush();
    glutSwapBuffers();
}

void App::keyPress(unsigned char key) {
    if (key == 27){//esc
        // Exit the app when Esc key is pressed
        delete this;
        exit(0);
    }
	else if (key == 32) {//spacebar
		if (runnyBoi->midAir == false) {
			runnyBoi->midAir = true;
			runnyBoi->setYvel(3);
		}
	}
	else if (key == 49) {//1
		BadDude badguy(1, 1);
		badguy.acceleration = 0;
		badguy.setXvel(-1.5);
		badguy.xCoord = 1.5;
		badBoiz.push_back(badguy);
	}
	else if (key == 52) {//4
		for (int i = 1; i < 3; i++) {
			BadDude badguy(i, 2);
			badguy.acceleration = 0;
			badguy.setXvel(-1.5);
			badguy.xCoord = 1.5;
			badBoiz.push_back(badguy);
		}
	}
	/*else if (key == 55) {//7
		for (int i = 1; i < 4; i++) {
			RunnyBoiAndBadDudes badguy(i, 3,1);
			badguy.acceleration = 0;
			badguy.setXvel(-1.5);
			badguy.xCoord = 1.5;
			badBoiz.push_back(badguy);
		}
	}
	else if (key == 50) {//2
			RunnyBoiAndBadDudes box(1,1,0);
			box.acceleration = 0;
			box.setXvel(-1.5);
			box.xCoord = 1.5;
			boxs.push_back(box);
	}
	else if (key == 53) {//5
		for (int i = 1; i < 3; i++) {
			RunnyBoiAndBadDudes box(i, 2, 0);
			box.acceleration = 0;
			box.setXvel(-1.5);
			box.xCoord = 1.5;
			boxs.push_back(box);
		}
	}
	else if (key == 56) {//2
		for (int i = 1; i < 4; i++) {
			RunnyBoiAndBadDudes box(i, 3, 0);
			box.acceleration = 0;
			box.setXvel(-1.5);
			box.xCoord = 1.5;
			boxs.push_back(box);
		}
	}
	*/
	else if (key == 57) {//9
		currentFloor += 0.01;
		runnyBoi->currentfloor = currentFloor;
		std::cout << currentFloor << std::endl;
	}
	else if (key == 54) {//6
		currentFloor -= 0.01;
		runnyBoi->currentfloor = currentFloor;
		std::cout << currentFloor << std::endl;
	}
	else if (key == 114) {// r, restarts game
		score->resetScore();
	//	App::~App();
	//	App::App("MyApp", 50, 50, 600, 600);
	}
	else if (key == 51) {//3
		stopGame = false;
	}
}


//Triangle spawner func
void timeToSpawn() {
	//cout << "Time to spawn is " << noSpawnTime;
	//cout << "Time difference is " << double(clock() - beginTime);
	if ((double(clock() - beginTime) / CLOCKS_PER_SEC) >= noSpawnTime) {
		cout << "Spawning triangle" << endl;
		int chain = rand() % 3 + 2;
		for (int i = 1; i < chain; i++) {
			BadDude badguy(i, chain);
			badguy.setXvel(-1);
			badguy.xCoord = 1;
			badBoiz.push_back(badguy);
		}
		beginTime = clock();
		noSpawnTime = rand() % 1 + 0.55;
	}
}

Scoreboard &App::getScoreBoard() {
	return *score;
}

// (Supposed to) draw the score
void App::drawScore(string s, int x, int y) {

	glRasterPos2i(x, y);
	for (int i = 0; i < s.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
	}
}

void App::idle(){
	if (stopGame == false) {

		//runnyBoi->currentfloor = currentFloor;
		if (runnyBoi->midAir == true ) //if main guy is off the "ground"
			runnyBoi -> time += 0.001;
		
		if (runnyBoi->yCoord < currentFloor) {//make sure he doesnt fall through the floor( I set floor at Y=0)
			runnyBoi->midAir = false;
			runnyBoi->time = 0;
			runnyBoi->yCoord = currentFloor;
		}
		runnyBoi->setYcoord();



		/**
		srand(clock());//randomize
		int chain = rand() % 4;//pick a number between 0 and 3 inclusive
		if ((badBoiz.size()>0&&( badBoiz.back().xCoord<(badBoiz.back().xinitial-((badBoiz.back().chain+1)*.15)))) ||badBoiz.size()==0) { //some crazy ass statement for making sure things dont overlap and to ensure there is a free space after a 3 chain
			for (int i = 1; i < chain+1; i++) {//make a chain of enemies
				RunnyBoiAndBadDudes badguy(i, chain);
				badguy.setXvel(-1);
				badguy.xCoord = 1;
				badBoiz.push_back(badguy);
			}
		}
		*/

		// Triangle spawner
		timeToSpawn();

		

		for (int i = 0; i < badBoiz.size(); i++) {//loop and set the coordinates for the next frame for each guy
			badBoiz[i].time += .001;
			badBoiz[i].setXcoord();
		}


		for (int i = 0; i < boxs.size(); i++) {//loop and set the coordinates for the next frame for each guy
			boxs[i].time += .001;
			boxs[i].setXcoord();
		}


		float deltaX;
		for (int i = 0; i < badBoiz.size(); i++) {//check for hitting a triangle
			if ( ((badBoiz[i].xCoord <= runnyBoi->xCoord + .15 && badBoiz[i].xCoord >= runnyBoi->xCoord) || (badBoiz[i].xCoord + 0.15 >= runnyBoi->xCoord && badBoiz[i].xCoord + 0.15 <= runnyBoi->xCoord + 0.15)) ) {//if x intersection
				float slope = sqrt(3);
				float b = badBoiz[i].yCoord;
				deltaX = -.35 - badBoiz[i].xCoord;
				if (deltaX <= 0.075) {
					slope = sqrt(3);
					b = badBoiz[i].yCoord;
				}
				else if (deltaX >= (.15 + 0.075) ){
					slope = -sqrt(3);
					b = badBoiz[i].yCoord;
				}
				else {
					slope = 0;
					b = badBoiz[i].yCoord + (sqrt(3)*0.075);
				}
				float line = (slope*(deltaX))+b;
				if ((line >= runnyBoi->yCoord) ) {//theres a hit
					redraw();
					stopGame = true;
					score->flipState();
				}
			}

		}
		
		for (int i = 0; i < boxs.size(); i++) {
			
			if ((boxs[i].xCoord <= runnyBoi->xCoord + .15 && boxs[i].xCoord > runnyBoi->xCoord + .149) && (runnyBoi->yCoord >= boxs[i].yCoord && runnyBoi->yCoord < boxs[i].yCoord + 0.15)) {
				redraw();//if it gets hit from the side
				stopGame = true;
				score->flipState();
			}
			else if (((boxs[i].xCoord <= runnyBoi->xCoord + .15 && boxs[i].xCoord >= runnyBoi->xCoord) || (boxs[i].xCoord + .15 >= runnyBoi->xCoord && boxs[i].xCoord + .15 <= runnyBoi->xCoord + .15))) {
				currentFloor = boxs[i].yCoord + .15;
				if (runnyBoi->yCoord < boxs[i].yCoord + .15) {
					runnyBoi->currentfloor = currentFloor;//raise the floor for jumping onto another box
					break;
				}
			}
				
		}
		
		
		if (badBoiz.size() > 0 && badBoiz[0].xCoord < -1.25)//if theyre off the screen remove them from the queue
			badBoiz.pop_front();

		if (boxs.size() > 0 && boxs[0].xCoord < -1.25)//if theyre off the screen remove them from the queue
			boxs.pop_front();
		
		

		redraw();// redraw
		//Sleep(10);// Windows specific Sleep timer, use this to control the render rate of the program
	}
}

App::~App(){
	delete runnyBoi;//kill him
}
