#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"
#include "Spout2Reciever.h"

struct InputParams {

	int input_type;

};

class input_selector
{
public:

	void setup();
	//void update();
	void draw();
	void selection();

	VideoLoader vid;
	ImageLoader img;
	CamLoader cam;
	ColourGradient gradient;
	InputParams params;
	Spout2Reciever spout;
	
	ofImage splash;
	string select;

	bool camera, video, image, colour, no_input, Spout2;

private:
	int x = 0;
	int y = 0;
	int w = ofGetWidth();
	int h = ofGetHeight();


	//GLuint getTextureID8();

//private:
	//ofFbo fbo8;
	//GLuint textureid8;

	
	
	
};

