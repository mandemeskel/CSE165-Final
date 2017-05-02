#ifndef App_hpp
#define App_hpp
#include "GlutApp.h"
#include "RunnyBoiAndBadDudes.h"

class App: public GlutApp {
	RunnyBoiAndBadDudes* runnyBoi;
	bool stopGame;
    // Maintain app state here
	
   
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
	float currentFloor;
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    
    void idle();
    
    ~App();
};

#endif
