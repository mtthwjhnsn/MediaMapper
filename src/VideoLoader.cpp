#include "VideoLoader.h"

void VideoLoader::setup() {

	/*
	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();

		video.loadMovie(path);
		video.play();
	}
	*/

	vector<string> select = { "input0.mov", "input1.mov", "input2.mov"};


	for (int i = 0; i <= 2; i++) {
		video.loadMovie(select[i]);
		videos.push_back(video);
		//videos[i].play
	}

	for (int i = 0; i <= 2; i++) {
		videos[i].play();
	}

}

void VideoLoader::draw(int selection, int x, int y, int w, int h) {
	videos[selection].update();
	videos[selection].draw(x, y, w, h);
}

void VideoLoader::close(int selection) {
	videos[selection].close();
}