#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"
#include "Spout2Reciever.h"

struct InputParams {

	int input_type;
	bool setup;

};

class input_selector
{
public:

	void setup(VideoLoader *_vid, ImageLoader *_img, CamLoader *_cam, ColourGradient *_gradient, Spout2Reciever *_spout);
	//void update();
	void draw(ofFbo fbo, int x, int y, int w, int h);
	void selection();


	
	InputParams params;

	ofImage splash;
	string select;

	bool camera, video, image, colour, no_input, Spout2;

private:
	VideoLoader *vid;
	ImageLoader *img;
	CamLoader *cam;
	ColourGradient *gradient;
	Spout2Reciever *spout;

	//GLuint getTextureID8();

//private:
	//ofFbo fbo8;
	//GLuint textureid8;

	
	
	
};