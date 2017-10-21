/*
Video player for openFrameworks using Windows Media Foundation API and hardware acceleration capabilities
ofxWMFVideoPlayer
by Philippe Laulheret 
forked by jackosx
https://github.com/jackosx/ofxWMFVideoPlayer
*/

#pragma once

#include "ofMain.h"
#include "ofxWMFVideoPlayer.h"

class VideoLoader
{

public:

	~VideoLoader() {};
	VideoLoader() {};

	void setup();
	void update();
	void draw(int selection, int x, int y, int w, int h);

	void dragEvent(ofDragInfo info);

	vector<ofImage> draggedImages;
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

