#pragma once
#include "ofMain.h"
#include "ofxSpout2Receiver.h"

class Spout2Reciever
{
public:

	~Spout2Reciever() {};
	Spout2Reciever() {};


	void setup();
	void draw(int selection, int x, int y, int w, int h);
	void spout_list(int selection);
	void add_reciever(int selection);
	void exit();


	//vector<ofxSpout2::Receiver> adds;
	vector<ofxSpout2::Receiver> spoutRecievers;
	//ofxSpout2::Receiver spoutReciever;
	vector<ofTexture> texs;


};

