#pragma once

#include "ofMain.h"
#include "ofThread.h"

class mythread : public ofThread {

public:
	mythread();
	~mythread();

	void threadedFunction();

	void setup();
	// void draw(int selection, int x, int y, int w, int h);
	//void clear();
	void keyPressed(int key);



	//ofxThreadedImageLoader threadedImage;
	//vector<ofxThreadedImageLoader> threadedImages;


	ofImage image;
	vector<ofImage> images;

private:
	int _x, _y, _w, _h, _selection;
	int load;

};

