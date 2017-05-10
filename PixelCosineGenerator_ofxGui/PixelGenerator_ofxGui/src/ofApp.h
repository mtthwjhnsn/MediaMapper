#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

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

	ofxPanel gui;
	ofxFloatSlider r_a;
	ofxFloatSlider g_a;
	ofxFloatSlider b_a;

	ofxFloatSlider r_b;
	ofxFloatSlider g_b;
	ofxFloatSlider b_b;


	ofxFloatSlider r_c;
	ofxFloatSlider g_c;
	ofxFloatSlider b_c;

	ofxFloatSlider r_d;
	ofxFloatSlider g_d;
	ofxFloatSlider b_d;

	ofxPanel gui2;
	ofxButton rand_red;
	ofxButton rand_green;
	ofxButton rand_blue;
	ofxButton rand_a;
	ofxButton rand_b;
	ofxButton rand_c;
	ofxButton rand_d;
	ofxButton rand_all;
};