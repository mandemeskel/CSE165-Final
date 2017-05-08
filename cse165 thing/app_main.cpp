#include "App.h"
#include<time.h>
#include <ctime>
#include <chrono>
#include <future>



int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("MyApp", 50, 50, 600, 600);

	Scoreboard score = myApp->getScoreBoard();
//	auto future = async(score.incrementScore);
	
	// Start the app
    myApp->run();
	




}
