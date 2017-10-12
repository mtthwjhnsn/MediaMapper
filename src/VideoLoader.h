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
	void draw(int selection, int x, int y, int w, int h);
	void close(int selection);
	string path;
	vector<string> paths;
	//ofVideoPlayer video;
	ofxWMFVideoPlayer video;
	vector<ofxWMFVideoPlayer> videos;
};

