#pragma once
#include "ofMain.h"

class CamLoader
{





public:

	void setup();
	void draw(int x, int y, int w, int h);
	void close();

	ofVideoGrabber cam;
};

