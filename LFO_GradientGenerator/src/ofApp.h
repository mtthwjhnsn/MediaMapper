#pragma once

#include "ofMain.h"
#include "GuiColourGradient.h"
#include "ColourGradient.h"
#include "ofxMaxim.h"
#include "ofxSpout2Sender.h"

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

	void audioOut(float * output, int bufferSize, int nChannels);

	double outputs[2];
	unsigned bufferSize, sampleRate;

	double frequency, modSpeed, currentSample;
	maxiOsc osc, modulator;
	maxiMix mix;

	ofFbo fbo;
	GLuint textureid;

	ColourGradient colour;
	GuiColourGradient gui;

	ofxSpout2::Sender spout;

};
