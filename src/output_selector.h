#pragma once

#include "ofMain.h"

#include "Spout2Sender.h"
#include "NDIoutput.h"

struct OutputParams {

	int output_type;

};

class output_selector
{
public:
	
	void setup(NDIoutput *_NDI, Spout2Sender *_spout);
	//void update();
	void draw();
	void selection();

	OutputParams params;
	
private:

	Spout2Sender *SpoutSender;
	NDIoutput *NDIsender;

	bool spout, NDI, no_output;
};

