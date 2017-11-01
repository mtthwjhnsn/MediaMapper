#pragma once

#include "ofMain.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "Spout2Reciever.h"
#include "ofxSpout2Receiver.h"
#include "ShaderToy.h"
#include "NDIoutput.h"

class input_selector
{
public:
	~input_selector() {};
	input_selector() {};

	void setup(ImageLoader *_img, CamLoader *_cam, VideoLoader *_vid, Spout2Reciever * SpoutIn, ShaderToy * _shaderToy, NDIoutput * _ndiOut);

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
	void spout_list(int selection);
	void spout_draw(int selection,  int x, int y, int w, int h);

	string path;
	vector<string> paths;

	VideoLoader *vid;
	ImageLoader *img;
	CamLoader *cam;
	Spout2Reciever *spoutIn;
	ShaderToy *shaderToy;
	NDIoutput *ndiOut;

	ofImage splash;
	vector<ofImage> splashes;

private:
	
	
};