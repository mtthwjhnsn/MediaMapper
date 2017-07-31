#include "ImageLoader.h"

void ImageLoader::setup() {

	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();
		// load your file at `path`
		image.load(path);

	}
}

void ImageLoader::draw() {
	image.draw(ofGetWidth() * 1 / 3, 0, ofGetWidth(), ofGetHeight());
}

void ImageLoader::clear() {
	image.clear();
}
