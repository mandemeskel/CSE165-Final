#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

class Scoreboard {
	int score;
	bool start;

public: 
	Scoreboard() {
		score = 0;
		start = false;
	}

	Scoreboard(bool s) {
		score = 0;
		start = s;
	}

	void flipState() {
		start = !start;
	}
	
	void incrementScore() {
		if (start)	score++;
	}

	int getScore() {
		return score;
	}

	void resetScore() {
		score = 0;
	}


};

#endif