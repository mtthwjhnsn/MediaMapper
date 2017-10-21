#include "VideoLoader.h"
#include <string>
#include <iostream>

//--------------------------------------------------------------
void VideoLoader::setup() {

	bGenerateThumbs = true;

}

//--------------------------------------------------------------
void VideoLoader::update(int selection) {
}
//--------------------------------------------------------------
void VideoLoader::draw(int x, int y, int w, int h) {

	if (video.isLoaded())
	{
		video.update();
		video.draw(x, y, w, h);
	}

}

void VideoLoader::swap(int selection) {
	video.stop();
	//video.close();
	video.setPixelFormat(OF_PIXELS_RGBA);
	video.load(videoPaths[selection]);
	video.play();
	video.setVolume(0.0);

}

void VideoLoader::drawThumbs(int selection, int x, int y, int w, int h) {
	if (videoThumbs.size() > 0) {
		videoThumbs[selection].draw(x, y, w, h);
	}
}


void VideoLoader::dragEvent(ofDragInfo info) {

	if (info.files.size() > 0) {

		filesSize = info.files.size();

		for (int i = 0; i < info.files.size(); i++) {

			cout << "file = " << info.files.at(i) << endl;

			const std::string sentence = info.files.at(i);

			vector<std::string> search = { ".mov", ".mp4", ".avi", ".wmv", ".flv" };
			size_t pos;

			for (int j = 0; j < search.size(); j++) {

				pos = sentence.find(search[j]);
				if (pos != std::string::npos) {

					//print video type
					std::cout << "video type: " << search[j] << std::endl;

					//pushback
					videoPaths.push_back(info.files.at(i));

					fileName = ofSplitString(videoPaths.back(), "\\"); //Find on the last name in the path
					fileName = ofSplitString(fileName.at(fileName.size() - 1), "."); //Remove the .mov extension from the fileName

					//vector<string> audioFileName = ofSplitString(videoPaths.back(), ".");
					//audioPaths.push_back(audioFileName[0] + ".mov");
					//avSource->addNewMediaPath(videoPaths.back(), audioPaths.back());

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

						swap(i);
					}
				}
			}
		}
	}
}