#include "ofApp.h"
float x;
float r_a, r_b, r_c, r_d, g_a, g_b, g_c, g_d, b_a, b_b, b_c, b_d;
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	x = 0.001;
	r_a = 0.5;
	r_b = 0.5;
	r_c = 0.25;
	r_d = 0.5;
	g_a = 0.5;
	g_b = 0.5;
	g_c = 0.25;
	g_d = 0.5;
	b_a = 0.5;
	b_b = 0.5;
	b_c = 0.25;
	b_d = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){

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
