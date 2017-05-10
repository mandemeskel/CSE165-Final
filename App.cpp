#define _USE_MATH_DEFINES
#include "App.h"
#include <math.h>
#include <cstdio>
#include<iostream>
#include<Windows.h>
#include<deque>
#include<stdlib.h>
#include "Scoreboard.h"
#include <string>
#include "BadCircle.h"
#include "menu.h"
using namespace std;

deque<BadDude> badBoiz;//double ended thingy to hold bad dudes
deque<runnyboi> boxs;
deque<BadCircle> circles;

Menu * menu;

float STime;
float cTime;
float cirSTime;

// Time for power speedup
float speedupTime;
bool speedup;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
	runnyBoi = new runnyboi();// make the dude
	currentFloor = 0.0;
	stopGame = true; //Set back to true later
	endGame = false;
	speedupTime = 0.5;
	speedup = false;
	STime = 0.0f;
	cirSTime = 10;//rand() % 1 + 0.9;
	if (cirSTime < 0.5) cirSTime = 1.6;
	noSpawnTime = rand() % 1 + 0.8;
	if (noSpawnTime < 0.5) noSpawnTime = 1.5;
	score = new Scoreboard();
	score->flipState();
	menu = new Menu();
}

void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set background color to black
    glClearColor(0.2, 0.3, 0.7, 0);
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

	// draw menu
	menu->draw();

	if (!stopGame && !endGame) {


		glBegin(GL_LINES);//temp line for the floor
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
		glEnd();



		for (int i = 0; i < badBoiz.size(); i++) {//draw the bad guys
			badBoiz[i].draw();
		}
		for (int i = 0; i < boxs.size(); i++) {
			boxs[i].draw();
		}
		for (int i = 0; i < circles.size(); i++) {
			circles[i].draw();
		}
		runnyBoi->draw();//draw the main guy
		// We have been drawing everything to the back buffer
		// Swap the buffers to see the result of what we drew

		//Draws the score
		drawScore("Score : " + to_string(score->getScore()), -0.15, 0.9);
	}
	if (endGame) {
		drawScore("Final Score : " + to_string(score->getScore()), -0.15, 0.0);
	}

    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float mx, float my) {
	switch (menu->contains(mx, my)) {
	case START_GAME:
		stopGame = false;
		menu->toggle(true);
		break;
	case SHOW_SCOREBOARD:

		break;
	default:
		break;
	}
}

void speedupPower() {
	for (int i = 0; i < badBoiz.size(); i++) {
		badBoiz[i].time += 0.1;
	}

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
	else if (key == 102) { //f, speedup
		speedupTime = 250;
		speedup = true;
	}
	else if (key == 114) {// r, restarts game
		resetGame();
	}
	else if (key == 51) {//3
		stopGame = false;
	}
}

void App::resetGame() {
	stopGame = false;
	score->resetScore();
	badBoiz.clear();
	runnyBoi->reset();
	circles.clear();
	cirSTime = 10;
	endGame = false;
	runnyBoi->xCoord = -0.7;
	if (!score->getStart())
	score->flipState();
}

void App::changeSpawnTime(float time) {
	noSpawnTime = time;
}

float App::getSpawnTime() {
	return noSpawnTime;
}


//Triangle spawner func
void App::timeToSpawnTri() {


	int chain = rand() % 2 + 2;
	for (int i = 1; i < chain; i++) {
		BadDude badguy(i, chain);
		badguy.setXvel(-1);
		badguy.xCoord = 1;
		badBoiz.push_back(badguy);
	}
	srand(clock());
	changeSpawnTime((rand() % 2 + 0.8));
	if (noSpawnTime < 0.8) { changeSpawnTime(0.8); }

}

// Circle spawner func
void timeToSpawnCir() {
	BadCircle badcircle;
	badcircle.setXvel(-1.8);
	badcircle.xCoord = 1.2;
	circles.push_back(badcircle);
	cirSTime = rand() % 1 + 2.4;
	if (cirSTime < 0.5) cirSTime = 2.6;
}

// (Supposed to) draw the score
void App::drawScore(string s, float x, float y) {

	glRasterPos2f(x, y);
	for (int i = 0; i < s.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
	}
}

void App::idle(){
	if (stopGame == false) {

		//runnyBoi->currentfloor = currentFloor;
		if (runnyBoi->midAir == true) //if main guy is off the "ground"
			runnyBoi->time += 0.001;

		if (runnyBoi->yCoord < currentFloor) {//make sure he doesnt fall through the floor( I set floor at Y=0)
			runnyBoi->midAir = false;
			runnyBoi->time = 0;
			runnyBoi->yCoord = currentFloor;
		}
		runnyBoi->setYcoord();


		// Triangle spawner
		STime += 0.1;
		if (STime >= noSpawnTime * 90) {
			timeToSpawnTri();
			STime = 0.0;
		}
		//Circle spawner
		cTime += 0.1;
		if (cTime >= cirSTime * 90) {
			timeToSpawnCir();
			cTime = 0.0;
		}


		//Speedup
		if (speedup == true) {
			//speedupTime -= 1;
			speedupPower();
			speedup = false;
		}


		for (int i = 0; i < badBoiz.size(); i++) {//loop and set the coordinates for the next frame for each guy
			badBoiz[i].time += .001;
			badBoiz[i].setXcoord();
		}


		for (int i = 0; i < boxs.size(); i++) {//loop and set the coordinates for the next frame for each guy
			boxs[i].time += .001;
			boxs[i].setXcoord();
		}

		for (int i = 0; i < circles.size(); i++) {
			circles[i].time += .001;
			circles[i].setXcoord();
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
					endGame = true;
					stopGame = true;
					
						score->flipState();
					cirSTime = 10.0;
				}
			}

		}


		// circle hitbox
		for (int i = 0; i < circles.size(); i++) {
			
			if ((circles[i].xCoord-0.10 <= runnyBoi->xCoord + .15) && (runnyBoi->yCoord+0.15 >= circles[i].yCoord ) && (circles[i].xCoord+.10>runnyBoi->xCoord)) {
				redraw();//if it gets hit from the side
				stopGame = true;
				score->flipState();
				cirSTime = 10;
				endGame = true;
			}
				
		}
		
		
		if (badBoiz.size() > 0 && badBoiz[0].xCoord < -1.25) {//if theyre off the screen remove them from the queue
			badBoiz.pop_front();
		}

		if (boxs.size() > 0 && boxs[0].xCoord < -1.25)//if theyre off the screen remove them from the queue
			boxs.pop_front();

		if (circles.size() > 0 && circles[0].xCoord < -1.25)
			circles.pop_front();
		
		score->incrementScore();
		redraw();// redraw
		//Sleep(10);// Windows specific Sleep timer, use this to control the render rate of the program
	}

}

App::~App(){
	delete runnyBoi;//kill him
}
