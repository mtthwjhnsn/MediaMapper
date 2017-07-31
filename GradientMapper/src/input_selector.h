#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"

struct InputParams {

	int input_type;

};

class input_selector
{
public:

	void setup();
	void draw();
	void selection();

	VideoLoader player;
	ImageLoader image;
	CamLoader cam;

	InputParams params;
	
	bool camera, video, img;
};

