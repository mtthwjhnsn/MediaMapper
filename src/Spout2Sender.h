#pragma once

#include "ofMain.h";
#include "ofxSpout2Sender.h";

class Spout2Sender
{
public:

	void setup();
	void send(ofFbo fbo);
	void exit();

	ofFbo Spout2fbo;
	ofFbo *fbo;

	ofxSpout2::Sender spout;

private:
};

