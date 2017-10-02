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

	void splash_draw(int test_pattern, int x, int y, int w, int h);
	//void video_draw(int x, int y, int w, int h);
	//void image_draw(int x, int y, int w, int h);
	//void camera_draw(int x, int y, int w, int h);
	//void gradient_draw(int x, int y, int w, int h);
	//void spout_draw(int x, int y, int w, int h);
	//void NDI_draw(int x, int y, int w, int h);

	//void draw(ofFbo fbo, int x, int y, int w, int h);
	void selection();

	/*
	vector<VideoLoader> vid;
	vector<ImageLoader> img;
	vector<CamLoader> cam;
	vector<ColourGradient> gradient;
	vector<Spout2Reciever> spout;
	*/
	VideoLoader *vid;
	ImageLoader *img;
	CamLoader *cam;
	ColourGradient *gradient;
	Spout2Reciever *spout;

	InputParams params;

	ofImage splash;
	vector<ofImage> splashes;
	vector<string> select;

	bool camera, video, image, colour, no_input, Spout2;

private:


	//GLuint getTextureID8();

//private:
	//ofFbo fbo8;
	//GLuint textureid8;

	
	
	
};