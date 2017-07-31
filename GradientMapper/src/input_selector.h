#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"

struct InputParams {

	int input_type;

};

class input_selector
{
public:

	void setup();
	void draw();
	void selection();

	VideoLoader vid;
	ImageLoader img;
	CamLoader cam;
	ColourGradient gradient;

	InputParams params;
	
	bool camera, video, image, colour;
};

