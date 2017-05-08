#include "App.h"
#include <thread>
#include <chrono>

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("MyApp", 50, 50, 600, 600);

	// Start the app
    myApp->run();

	Scoreboard score = myApp->getScoreBoard();

	while (true) {
		this_thread::sleep_for(chrono::seconds(1) / 2);
		score.incrementScore();
		
	}

}
