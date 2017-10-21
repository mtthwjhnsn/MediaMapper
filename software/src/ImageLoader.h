#pragma once

#include "ofMain.h"
#include "ofThread.h"

class ImageLoader{

public:
	ImageLoader();
	~ImageLoader();

	void setup();
	void draw(int x, int y, int w, int h);
	void drawThumbs(int selection, int x, int y, int w, int h);
	void swap(int selection);
	void active(int selection);
	//void clear();

	void dragEvent(ofDragInfo info);

	ofImage img;
	ofImage image;
	vector<ofImage> images;

	vector<string> imagePaths;
	//vector<string> audioPaths;
	vector<ofImage> imageThumbs;

	vector<string> fileName;
	int filesSize;


private:


};