#pragma once

#include "ofMain.h"
#include "GuiColourGradient.h"
#include "ColourGradient.h"
#include "ArtnetSender.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();

	void tempBottomEnd();

	void draw();

	int getStartingAddress(int i, int split, int first_start_address, int second_start_address, int numChannels);

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

	//im gui

	GuiColourGradient gui;
	
	ColourGradient colour;
	
	//artnet
	ArtnetSender        m_artnetSender;

	int                 m_subnet;
	int                 m_universe;
	unsigned char       m_data[512];


private:
	int numModules;
	int numLights;
};
