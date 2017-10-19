#pragma once

#include "ofMain.h"
#include "ofThread.h"

class ImageLoader : public ofThread {

public:
	ImageLoader();
	~ImageLoader();

	void threadedFunction();

	void setup();
	void draw(int selection, int x, int y, int w, int h);
	//void clear();
	void keyPressed(int key);

	ofImage image;
	vector<ofImage> images;

private:
	int _x, _y, _w, _h, _selection;
	int load;

};