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

	bool getStart() {
		return start;
	}

	void flipState() {
		start = !start;
	}
	
	void incrementScore() {
		if (start) {
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