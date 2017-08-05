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

	void setup();
	void draw();
	void close();

	//ofVideoPlayer video;
	ofxWMFVideoPlayer video;
};

