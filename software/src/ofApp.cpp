
//---------------
//----ofApp.cpp
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	background.load("background.png");

	int w = ofGetWidth();
	int h = ofGetHeight();

	input.setup(&image, &camera, &video, &spoutIn, &shaders, &ndiOut);
	gui.setup(&input);

}

void ofApp::backgrounddraw() {
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}
//--------------------------------------------------------------
void ofApp::gui_draw() {
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::draw() {
	backgrounddraw();
	update();
	gui_draw();

	//ofSetColor(255);
	//ofDrawBitmapString("mouse X: " + ofToString(ofGetMouseX()) + "mouse y: " + ofToString(ofGetMouseY()), ofGetWidth() - 200, ofGetHeight() - 200);
	//ofSetColor(0, 0, 0, 0);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

	video.dragEvent(dragInfo);
	image.dragEvent(dragInfo);

}