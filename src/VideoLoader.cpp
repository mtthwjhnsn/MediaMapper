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

void VideoLoader::draw(int x, int y, int w, int h) {
	video.update();
	video.draw(x, y, w, h);
}

void VideoLoader::close() {
	video.close();
}