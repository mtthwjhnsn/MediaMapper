#pragma once

#include "ofMain.h"

#include "Spout2Sender.h"
#include "NDIoutput.h"
#include "input_selector.h"


struct OutputParams {

	int output_type;
	//bool switcher;

};

class output_selector
{
public:
	
	void setup();
	//void update();
	void draw(ofFbo fbo);
	void selection();

	OutputParams params;
	
	NDIoutput NDI;
	Spout2Sender Spout2;

	bool spout2Sender, NDIsender, noSender;

private:



};

