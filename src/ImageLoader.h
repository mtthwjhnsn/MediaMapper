#pragma once
#include "ofMain.h"
#include "ofxThreadedImageLoader.h"

class ImageLoader
{
public:

	~ImageLoader() {};
	ImageLoader() {};

	void setup();
	void draw(int selection, int x, int y, int w, int h);
	void clear();

	ofxThreadedImageLoader threadedImage;
	vector<ofxThreadedImageLoader> threadedImages;

	ofImage image;
	vector<ofImage> images;
};

