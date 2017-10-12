#include "ImageLoader.h"

void ImageLoader::setup() {

	
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);

		/*
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			string path = result.getPath();

			threadedImage.loadFromDisk(image, path);
		}*/
		
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
			if (result.bSuccess) {
			
				string path = result.getPath();
				//threadedImage.loadFromDisk(image, path);
				//image.load(path);
		}
		//threadedImage.


	images.push_back(image);

	//kick off thread
	startThread();

}

void ImageLoader::threadedFunction() {

	while (isThreadRunning()) {
		
		// Attempt to lock the mutex. If blocking is turned on
		if (lock())
		{

			//____>> function here

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


void ImageLoader::draw(int selection, int x, int y, int w, int h) {
	ofSetColor(255);
	images[selection].draw(x, y, w, h);
	}

void ImageLoader::clear() {
	/*
	threadedImage.stopThread();
	image.clear();
	*/
}
