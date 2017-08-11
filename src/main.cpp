//----main.cpp

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofGLWindowSettings settings;
	ofGLFWWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.width = 1280;
	settings.height = 720;


	settings.decorated = true;
	settings.resizable = true;
	settings.windowMode = OF_WINDOW;

	ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

/*
int main()
{
	ofGLFWWindowSettings settings;

	settings.width = 1024;
	settings.height = 768;
	settings.decorated = false;
	settings.windowMode = OF_WINDOW;

	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}
*/