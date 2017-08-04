#include "VideoLoader.h"

void VideoLoader::setup() {

	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();
		// load your file at `path`
		video.load(path);
		video.play();
	}
}

void VideoLoader::draw() {
	video.update();
	video.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void VideoLoader::close() {
	video.close();
}