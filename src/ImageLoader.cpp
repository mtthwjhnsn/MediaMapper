#include "ImageLoader.h"

void ImageLoader::setup() {

	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	
	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();

		threadedImage.loadFromDisk(image, path);
	}
}

void ImageLoader::draw(int x, int y, int w, int h) {
	ofSetColor(255);
	image.draw(x, y, w, h);
	}

void ImageLoader::clear() {

	threadedImage.stopThread();
	image.clear();
}
