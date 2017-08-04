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
#include "Sound.h"
#include "ofxMaxim.h"
#include "input_selector.h"
#include "ofxSpout2Sender.h"

//#include "ofxNDI.h"



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

	void exit();

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
	void audioOut(float * output, int bufferSize, int nChannels);

	unsigned bufferSize, sampleRate;
	double currentSample;
	float frequency_red, modulationIndex_red, modulationFrequency_red,   frequency_green, modulationIndex_green, modulationFrequency_green, frequency_blue, modulationIndex_blue, modulationFrequency_blue;
	double outputs[2];

	maxiOsc osc_red, mod_red, osc_green, mod_green, osc_blue, mod_blue, phaser;
	maxiMix mix;
	maxiEnv env_red, env_green, env_blue;
	

	//ofFbo fbo;
	//GLuint textureid;

	ColourGradient colour;
	Sound sound;
	GuiColourGradient gui;
	input_selector input;


	//Spout2Sender

	ofFbo fbo;
	ofxSpout2::Sender spout;

private:

	/*
	ofxNDIsender ndiSender;    // NDI sender object
	char senderName[256];      // Sender name
	unsigned int senderWidth;  // Width of the sender output
	unsigned int senderHeight; // Height of the sender output
	ofFbo ndiFbo;              // Fbo used for data transfer
	ofPixels ndiBuffer[2];     // Two pixel buffers for async sending
	int idx;                   // Index used for async buffer swapping
	ofImage textureImage;      // Texture image for the 3D cube graphics
	float rotX, rotY;          // Cube rotation increment

	GLuint ndiPbo[2];
	int PboIndex;
	int NextPboIndex;
	bool bUsePBO;
	bool ReadFboPixels(ofFbo fbo, unsigned int width, unsigned int height, unsigned char *data);
	*/

};
