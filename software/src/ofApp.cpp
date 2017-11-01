
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

	colour.setup(gui.tileWidth, gui.tileHeight);
	
	input.setup(&image, &camera, &video, &spoutIn, &shaders, &ndiOut);
	gui.setup(&colour, &input);
	
	ofFbo::Settings fboSettings;
	fboSettings.width = 1920; //2560
	fboSettings.height = 1080; //1440
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;

	fbo.allocate(fboSettings);

	fbo.begin();
	ofClear(255, 255, 255, 0);
	fbo.end();

	fbo1.begin();
	ofClear(255, 255, 255, 0);
	fbo1.end();


}

void ofApp::backgrounddraw() {
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
}
//--------------------------------------------------------------
void ofApp::colourfbo() {
	fbo1.begin();
	colour.draw();
	fbo1.end();
}
//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	fbo.begin();
	colourfbo();

	fbo.end();
}
//--------------------------------------------------------------
void ofApp::gui_draw() {
	gui.draw(fbo);
}

//--------------------------------------------------------------
void ofApp::draw() {
	backgrounddraw();
	update();
	gui_draw();
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