#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void gotMessage(ofMessage msg);
	void dragEvent(ofDragInfo dragInfo);

	vector <ofImage> draggedImages;
	ofPoint dragPt;

	vector<string> videoPaths;
	vector<string> audioPaths;
	vector<ofImage> videoThumbs;

	vector<string> fileName;

	ofImage img;
	vector<ofImage> imgs;

	//string videoPath;
	//string audioPath;
	//ofImage videoThumb;

	bool bGenerateThumbs;
	int filesSize;
};