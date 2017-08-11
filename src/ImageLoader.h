#pragma once
#include "ofMain.h"
#include "ofxThreadedImageLoader.h"

class ImageLoader
{





public:

	void setup();
	void draw(int x, int y, int w, int h);
	void clear();

	ofxThreadedImageLoader threadedImage;
	ofImage image;
};

