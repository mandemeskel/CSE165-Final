#ifndef App_hpp
#define App_hpp
#include "GlutApp.h"
#include "RunnyBoiAndBadDudes.h"
#include "runnyboi.h"
#include "BadDude.h"
#include <string>
#include "Scoreboard.h"

class App: public GlutApp {
	// Maintain app state here
	runnyboi* runnyBoi;
	bool stopGame;
	Scoreboard* score;
   
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	float currentFloor;
    // These are the events we want to handle
    void draw();
	void drawScore(std::string s, int x, int y);
    void keyPress(unsigned char key);
	Scoreboard& getScoreBoard();
    void startGame();
    void idle();
    void mouseDown( float mx, float my );
    ~App();
    
};

#endif
