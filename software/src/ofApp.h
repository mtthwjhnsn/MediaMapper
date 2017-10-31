//---------------
//----ofApp.h---
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#pragma once

#include "ofMain.h"
#include "GuiColourGradient.h"
#include "ColourGradient.h"
//#include "Sound.h"
#include "ofxMaxim.h"
#include "input_selector.h"
#include "output_selector.h"

//#include "ofxNDI.h"

//#include "Spout2Sender.h"
//#include "NDIoutput.h"

#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
#include "ColourGradient.h"
#include "Spout2Reciever.h"
#include "ShaderToy.h"
#include "NDIoutput.h"



// BGRA definition should be in glew.h
// but define it here just in case it is not
#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80E1
#endif


class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void backgrounddraw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//sound 
//	void audioOut(float * output, int bufferSize, int nChannels);

//	unsigned bufferSize, sampleRate;
//	double currentSample;
//	float frequency_red, modulationIndex_red, modulationFrequency_red,   frequency_green, modulationIndex_green, modulationFrequency_green, frequency_blue, modulationIndex_blue, modulationFrequency_blue;
	//double outputs[2];

//	maxiOsc osc_red, mod_red, osc_green, mod_green, osc_blue, mod_blue, phaser;
//	maxiMix mix;
//	maxiEnv env_red, env_green, env_blue;
	
	ofFbo fbo;

	ofImage background;

//	void coloursetup();
	void colourfbo();

	ofFbo fbo1;

	ColourGradient colour;
//	Sound sound;
	GuiColourGradient gui;
	input_selector input;
//	output_selector outs;
	ImageLoader image;
	CamLoader camera;
	VideoLoader video;
	Spout2Reciever spoutIn;
	ShaderToy shaders;
	NDIoutput ndiOut;

//	NDIoutput NDI;
//	Spout2Sender Spout2;

	//VideoLoader vid;
	//ImageLoader img;
	//CamLoader cam;
	//ColourGradient col;
	//Spout2Reciever spout;
	

	void OutputController();
	void output();

	//bool spout2Sender, NDIsender, noSender;


private:


};
