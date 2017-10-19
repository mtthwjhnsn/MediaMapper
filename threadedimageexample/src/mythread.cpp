#include "mythread.h"

mythread::mythread()
{
}


mythread::~mythread()
{
}

void mythread::setup() {


//	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetVerticalSync(true);

	/*
	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
	string path = result.getPath();

	threadedImage.loadFromDisk(image, path);
	}*/
	/*
	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {

		string path = result.getPath();
		//threadedImage.loadFromDisk(image, path);
		image.load(path);
	}
	*/

	//load = 0;

	//kick off thread
	
	
	//startThread();
	image.load("input0.png");//threadedImage.


}

void mythread::threadedFunction() {

	while (isThreadRunning()) {

		// Attempt to lock the mutex. If blocking is turned on
		if (lock())
		{
			//____>> function here
			//setup();
			//for (int i = 0; i <= 9; i++) {
			
			//images.push_back(image);
			//}
			image.getPixels();
			
			//keyPressed();
			//unlock the mutex
			unlock();
		}
		else
		{
			ofLogWarning("threadedFunction()") << "unable to lock mutex.";
		}
		//'framerate' of thread (ms)
		sleep(16);
	}
}


//void mythread::draw(int selection, int x, int y, int w, int h) {

	//_selection = selection;
	//_x = x;
	//_y = y;
	//_h = h;
	//_//w = w;

	//ofSetColor(255);
	//images[selection].draw(x, y, w, h);
//	image.draw(x, y, w, h);
//}

//--------------------------------------------------------------
void mythread::keyPressed(int key) {

}