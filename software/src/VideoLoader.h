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
	void update(int selection);
	void draw(int x, int y, int w, int h);
	void drawThumbs(int selection, int x, int y, int w, int h);
	void swap(int selection);

	void dragEvent(ofDragInfo info);
	ofVideoPlayer vid;
	ofxWMFVideoPlayer video;
	//vector<ofVideoPlayer> videos;
	
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

