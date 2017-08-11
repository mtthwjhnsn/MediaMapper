#include "ImageLoader.h"

void ImageLoader::setup() {

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	//total = 24;
	//images.resize(total * 2);
	
	
	
//	for (int i = 0; i < total; ++i) {
	//	loader.loadFromDisk(images[i * 2], "of" + ofToString(i) + ".png");
	//	loader.loadFromURL(images[i * 2 + 1], "http://www.openframeworks.cc/of_inverted.png");
	//}
	
	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();
		// load your file at `path`
		//image.load(path);
		threadedImage.loadFromDisk(image, path);
	}
}

void ImageLoader::draw(int x, int y, int w, int h) {
	//image.draw(x, y, w, h);

	// draw the images.
	ofSetColor(255);
	image.draw(x, y, w, h);
	}
/*
	// draw the FPS
	ofDrawRectangle(0, ofGetHeight() - 20, 30, 20);

	ofSetColor(0);
	ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 5, ofGetHeight() - 5);
}
*/

void ImageLoader::clear() {

	threadedImage.stopThread();
	image.clear();
}
