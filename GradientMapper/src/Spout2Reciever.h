#pragma once
#include "ofMain.h"
#include "ofxSpout2Receiver.h"

class Spout2Reciever
{
public:

	void setup();
	void draw();
	void exit();

	ofxSpout2::Receiver spoutReceiver;

};

