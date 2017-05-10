#include "ofApp.h"
float x;
//float r_a, r_b, r_c, r_d, g_a, g_b, g_c, g_d, b_a, b_b, b_c, b_d;
//--------------------------------------------------------------
void ofApp::setup(){
	//ofBackground(0);

	gui.setup();
	gui.setDefaultHeight(30);
	gui.add(r_a.setup("r_a", 0.5, -1, 1));
	gui.add(g_a.setup("g_a", 0.5, -1, 1));
	gui.add(b_a.setup("b_a", 0.5, -1, 1));
	gui.add(r_b.setup("r_b", 0.5, -1, 1));
	gui.add(g_b.setup("g_b", 0.5, -1, 1));
	gui.add(b_b.setup("b_b", 0.5, -1, 1));
	gui.add(r_c.setup("r_c", 0.25, -1, 1));
	gui.add(g_c.setup("g_c", 0.25, -1, 1));
	gui.add(b_c.setup("b_c", 0.25, -1, 1));
	gui.add(r_d.setup("r_d", 0.5, -1, 1));
	gui.add(g_d.setup("g_d", 0.5, -1, 1));
	gui.add(b_d.setup("b_d", 0.5, -1, 1));

	gui2.setup();
	gui2.setDefaultHeight(30);
	gui2.add(rand_red.setup("rand_red"));
	gui2.add(rand_green.setup("rand_green"));
	gui2.add(rand_blue.setup("rand_blue"));
	gui2.add(rand_a.setup("rand_a"));
	gui2.add(rand_b.setup("rand_b"));
	gui2.add(rand_c.setup("rand_c"));
	gui2.add(rand_d.setup("rand_d"));
	gui2.add(rand_all.setup("rand_all"));
		;
	
	x = 0.001;

}

//--------------------------------------------------------------
void ofApp::update(){
	if (rand_red == true) {
		r_a = ofRandom(-1.00, 1.00);
		r_b = ofRandom(-1.00, 1.00);
		r_c = ofRandom(-1.00, 1.00);
		r_d = ofRandom(-1.00, 1.00);
	}
	if (rand_green == true) {
		g_a = ofRandom(-1.00, 1.00);
		g_b = ofRandom(-1.00, 1.00);
		g_c = ofRandom(-1.00, 1.00);
		g_d = ofRandom(-1.00, 1.00);
	}
	if (rand_blue == true) {
		b_a = ofRandom(-1.00, 1.00);
		b_b = ofRandom(-1.00, 1.00);
		b_c = ofRandom(-1.00, 1.00);
		b_d = ofRandom(-1.00, 1.00);
	}
	if (rand_a == true) {
		r_a = ofRandom(-1.00, 1.00);
		g_a = ofRandom(-1.00, 1.00);
		b_a = ofRandom(-1.00, 1.00);
			}

	if (rand_b == true) {
		r_b = ofRandom(-1.00, 1.00);
		g_b = ofRandom(-1.00, 1.00);
		b_b = ofRandom(-1.00, 1.00);
	}
	if (rand_c == true) {
		r_c = ofRandom(-1.00, 1.00);
		g_c = ofRandom(-1.00, 1.00);
		b_c = ofRandom(-1.00, 1.00);
	}
	if (rand_d == true) {
		r_d = ofRandom(-1.00, 1.00);
		g_d = ofRandom(-1.00, 1.00);
		b_d = ofRandom(-1.00, 1.00);
	}
	if (rand_all == true) {
		r_a = ofRandom(-1.00, 1.00);
		r_b = ofRandom(-1.00, 1.00);
		r_c = ofRandom(-1.00, 1.00);
		r_d = ofRandom(-1.00, 1.00);
		g_a = ofRandom(-1.00, 1.00);
		g_b = ofRandom(-1.00, 1.00);
		g_c = ofRandom(-1.00, 1.00);
		g_d = ofRandom(-1.00, 1.00);
		b_a = ofRandom(-1.00, 1.00);
		b_b = ofRandom(-1.00, 1.00);
		b_c = ofRandom(-1.00, 1.00);
		b_d = ofRandom(-1.00, 1.00);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < ofGetWidth(); i++)
	{
		float red = (r_a + r_b*cos(6.28318*(r_c*(i*x) + r_d))) * 255;
		float green = (g_a + g_b*cos(6.28318*(g_c*(i*x) + g_d))) * 255;
		float blue = (b_a + b_b*cos(6.28318*(b_c*(i*x) + b_d))) * 255;

		ofSetColor(red, green, blue);
		ofDrawRectangle(i, 0, 1, ofGetHeight());


	}

	gui.draw();
	gui2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
