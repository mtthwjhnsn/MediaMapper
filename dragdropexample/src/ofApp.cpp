#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	bGenerateThumbs = true;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	if (videoThumbs.size() > 0) {
		for (int i = 0; i < videoThumbs.size(); i++) {
			videoThumbs[i].draw(i * 200, 0, 200, 200);
		}
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	//for (int i = 0; i <= fileName.size(); i++) {

	//	imgs.push_back(img.load(fileName[i]));
	//	imgs[i].load();
	//}
	//for (int i = 0; i <= videoThumbs.size(); i++) {
		
	//}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
/*void ofApp::dragEvent(ofDragInfo info) {

	if (info.files.size() > 0) {
		dragPt = info.position;

		draggedImages.assign(info.files.size(), ofImage());
		for (unsigned int k = 0; k < info.files.size(); k++) {
			draggedImages[k].load(info.files[k]);
		}
	}

}*/

void ofApp::dragEvent(ofDragInfo info) {

	if (info.files.size() > 0) {
		
		filesSize = info.files.size();

		for (int i = 0; i < info.files.size(); i++) {
			cout << "file = " << info.files.at(i) << endl;
			videoPaths.push_back(info.files.at(i));

			fileName = ofSplitString(videoPaths.back(), "\\" ); //Find on the last name in the path
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