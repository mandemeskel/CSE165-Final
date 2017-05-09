# include <iostream>
# include "ogl_tools.h"
# include "App.h"
//# include "app_window.h"

//==========================================================================
// Main routine
//==========================================================================
int main ( int argc, char** argv )
 {
   // Init freeglut library:
   glutInit ( &argc, argv );
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
   glutInitContextProfile ( GLUT_CORE_PROFILE );

   
 
   // Instantiate a new App
   App* myApp = new App("MyApp", 50, 50, 600, 600);

   //glutTimerFunc(App::getSpawnTime() * 1000, (App::timeToSpawn), 0);

   // Start the app
   myApp->run();
}
