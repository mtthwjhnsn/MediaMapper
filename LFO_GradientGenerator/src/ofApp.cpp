#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	colour.setup(ofGetWidth(), ofGetHeight());
	gui.setup(&colour);
	
	sampleRate = 44100;
	bufferSize = 512;
	ofBackground(0);
	ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
	frequency = 440;
	modSpeed = 2;
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	colour.draw();


	/*for (int i = 0; i < ofGetWidth(); i++) {
		ofSetColor(c[i]);
		ofDrawRectangle(i, ofGetHeight() / 2, 1, ofGetHeight() / 2);
	}*/

	gui.draw();

	//sound.audioOut(this, bufferSize, 2);


}
//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

		float red_sound = ofMap(colour.get_colour(0)[0], 0, 255, 0, 100);
		float green_sound = ofMap(colour.get_colour(0)[1], 0, 255, 0, 100);
		float blue_sound = ofMap(colour.get_colour(0)[2], 0, 255, 0, 100);

	for (unsigned i = 0; i < bufferSize; i++) {
		currentSample = osc.coswave(frequency) * red_sound * green_sound * blue_sound;
		mix.stereo(currentSample, outputs, 0.5);
		output[i * nChannels] = outputs[0];
		output[i * nChannels + 1] = outputs[1];
	}

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

}
