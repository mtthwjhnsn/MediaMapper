#pragma once
#include "ofMain.h"
#include "ofxSpout2Receiver.h"

class Spout2Reciever
{
public:

	void setup();
	void draw(int x, int y, int w, int h);
	void exit();

	ofxSpout2::Receiver spoutReceiver;

};

