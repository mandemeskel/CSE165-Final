#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <math.h>
#include <time.h>
#include <ctime>
#include <chrono>
#include <future>

using namespace std;

class Scoreboard {
	int score;
	double updateScoreTime;
	bool start;

public: 
	Scoreboard() {
		score = 0;
		updateScoreTime = 0.5;
		start = false;
	}

	Scoreboard(double d, bool s) {
		score = 0;
		updateScoreTime = d;
		start = s;
	}

	double getTimer() {
		return updateScoreTime;
	}

	void flipState() {
		start = !start;
	}
	
	// Threading not correctly implemented yet
	void incrementScore() {
		if (start) {/*
			double scTime = getTimer();
			for (double i = 0.0; i < scTime; i += 0.1) {
					score++;
					cout << "Score: " << getScore() << endl;
					this_thread::sleep_for(chrono::milliseconds(10));
				}
				*/
			score++;
			}
		}

	int getScore() {
		return score/80;
	}

	void resetScore() {
		score = 0;
	}



};

#endif