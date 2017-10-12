#pragma once
#include "ofMain.h"
//#include "ofxThreadedImageLoader.h"
#include "ofThread.h"

class ImageLoader
{
public: ofThread {

//	~ImageLoader() {};
//	ImageLoader() {};

//vector<ofImage> select;

	void threadedFunction();

	void setup();
	void draw(int selection, int x, int y, int w, int h);
	void clear();

//ofxThreadedImageLoader threadedImage;
//vector<ofxThreadedImageLoader> threadedImages;

	ofImage image;
	vector<ofImage> images;


private:

};