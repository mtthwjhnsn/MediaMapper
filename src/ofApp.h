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
#include "input_selector.h"
#include "VideoLoader.h"
#include "ImageLoader.h"
#include "CamLoader.h"
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

	ofImage background;
	GuiColourGradient gui;
	input_selector input;
	ImageLoader image;
	CamLoader camera;
	VideoLoader video;
	Spout2Reciever spoutIn;
	ShaderToy shaders;
	NDIoutput ndiOut;

	void gui_draw();


private:


};
