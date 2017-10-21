#pragma once
#include "ofMain.h"

class CamLoader
{

public:

	~CamLoader() {};
	CamLoader() {};

	void setup();
	void draw(int selection, int x, int y, int w, int h);
	void close(int selection);
	//void finder();

	ofVideoGrabber cam;
	vector<ofVideoGrabber> cams;
};

