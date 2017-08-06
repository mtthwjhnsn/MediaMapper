#pragma once

#include "ofMain.h";
#include "ofxSpout2Sender.h";
#include "input_selector.h";

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"
#include "Spout2Reciever.h"

class Spout2Sender
{
public:

	void setup();
	void send();
	void exit();

	ofFbo fbo;

	input_selector input;
	ofxSpout2::Sender spout;

private:
	VideoLoader vid;
	ImageLoader img;
	CamLoader cam;
	ColourGradient col;
	Spout2Reciever spout1;
};

