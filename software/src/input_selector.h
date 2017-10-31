#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"
#include "Spout2Reciever.h"
#include "ofxSpout2Receiver.h"
#include "ShaderToy.h"
#include "NDIoutput.h"

struct InputParams {

	int input_type;
	bool setup;

};

/*
enum ImageTypes {
	IMAGE,
	VIDEO,
	GRABBER,
	SPOUT
};
*/

class input_selector
{
public:
	~input_selector() {};
	input_selector() {};

	void setup(ImageLoader *_img, CamLoader *_cam, VideoLoader *_vid, Spout2Reciever * SpoutIn, ShaderToy * _shaderToy, NDIoutput * _ndiOut);
	//void update();

	void selection();

	void splash_draw(int test_pattern, int x, int y, int w, int h);
	void video_draw(int x, int y, int w, int h);
	void video_drawThumbs(int selection, int x, int y, int w, int h);
	void video_swap(int selection);
	void image_drawThumbs(int selection, int x, int y, int w, int h);
	void image_draw(int x, int y, int w, int h);
	void image_swap(int selection);
	void shader_draw(int selection, int x, int y, int w, int h);
	void NDI_out(ofFbo fbo, int x, int y, int w, int h);

	void camera_draw(int selection, int x, int y, int w, int h);
	//void gradient_draw(int x, int y, int w, int h);
	void spout_list(int selection);
	//void spout_update();
	void spout_draw(int selection,  int x, int y, int w, int h);
	//void NDI_draw(int x, int y, int w, int h);

	//void draw(ofFbo fbo, int x, int y, int w, int h);

	//ImageTypes types;
	
	string path;
	vector<string> paths;

	VideoLoader *vid;
	ImageLoader *img;
	CamLoader *cam;
	Spout2Reciever *spoutIn;
	ShaderToy *shaderToy;
	NDIoutput *ndiOut;

	//ColourGradient gradient;
	//Spout2Reciever *spout;

	InputParams params;

	ofImage splash;
	vector<ofImage> splashes;

	bool camera, video, image, colour, no_input, Spout2;

private:
	
	
};