#ifndef App_hpp
#define App_hpp
#include "GlutApp.h"
#include "RunnyBoiAndBadDudes.h"
#include "runnyboi.h"
#include "BadDude.h"
#include <string>
#include "Scoreboard.h"
#include <chrono>

class App: public GlutApp {
	// Maintain app state here
	runnyboi* runnyBoi;
	bool stopGame;
	bool endGame;
	Scoreboard* score;
	float noSpawnTime;
	
   
public:
	
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	float currentFloor;
    // These are the events we want to handle
    void draw();
	void changeSpawnTime(float t);
	void drawScore(std::string s, float x, float y);
    void keyPress(unsigned char key);
	void resetGame();
	void timeToSpawnTri();
	float getSpawnTime();

	void mouseDown(float mx, float my);
    
    void idle();
    
    ~App();
};

#endif
