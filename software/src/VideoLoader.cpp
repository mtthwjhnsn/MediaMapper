#include "VideoLoader.h"

//--------------------------------------------------------------
void VideoLoader::setup() {

	bGenerateThumbs = true;


	//ofAddListener(ofEvents().mouseMoved, this, &SomeClass::mouseMoved);

}

//--------------------------------------------------------------
void VideoLoader::update() {

}

//--------------------------------------------------------------
void VideoLoader::draw(int selection, int x, int y, int w, int h) {

	if (videoThumbs.size() > 0) {
		videoThumbs[selection].draw(x, y, w, h);
	}
	//ofdraw

	//ofSetColor(255);

	/*
	float dx = dragPt.x;
	float dy = dragPt.y;
	for (unsigned int k = 0; k < draggedImages.size(); k++) {
	draggedImages[k].draw(dx, dy);
	dy += draggedImages[k].getHeight() + 10;
	}

	ofSetColor(0);
	ofDrawBitmapString("drag image files into this window", 10, 20);*/

}

void VideoLoader::dragEvent(ofDragInfo info) {

	if (info.files.size() > 0) {

		filesSize = info.files.size();

		for (int i = 0; i < info.files.size(); i++) {
			cout << "file = " << info.files.at(i) << endl;
			videoPaths.push_back(info.files.at(i));

			fileName = ofSplitString(videoPaths.back(), "\\"); //Find on the last name in the path
			fileName = ofSplitString(fileName.at(fileName.size() - 1), "."); //Remove the .mov extension from the fileName

			//vector<string> audioFileName = ofSplitString(videoPaths.back(), ".");
			//audioPaths.push_back(audioFileName[0] + ".mov");

			//avSource->addNewMediaPath(videoPaths.back(), audioPaths.back());

			ofVideoPlayer vid;
			vid.load(videoPaths.back());
			vid.play();

			if (vid.isLoaded()) {
				cout << "LOADED!" << endl;
			}
			else {
				cout << "FUCK!" << endl;
			}

			//Basically until the video is loaded then all these calls aren't going to work
			if (vid.isLoaded()) {

				vid.setPosition(0.5);
				vid.update();

				ofImage image;

				image.setFromPixels(vid.getPixels());
				image.crop(0, 0, vid.getWidth(), vid.getHeight());
				image.resize(100, 100);

				vid.stop();
				vid.close();

				//image.save("Thumbnails/loaded" + ofToString(i) + ".png");

				image.save("Thumbnails/" + fileName.at(fileName.size() - 2) + ".png");

				image.load("Thumbnails/" + fileName.at(fileName.size() - 2) + ".png");
				videoThumbs.push_back(image);
			}

		}
	}
}