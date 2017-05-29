#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	
	int w = ofGetWidth();
	int h = ofGetHeight();

	colour.setup(ofGetWidth(), ofGetHeight());
	gui.setup(&colour);
	
	ofFbo::Settings fboSettings;
	fboSettings.width = w;
	fboSettings.height = h;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;
	fbo.allocate(fboSettings);
	
	
	//fbo.allocate(ofGetWidth(), ofGetHeight());

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
	
	fbo.begin();
	ofClear(0, 0, 0, 255);
	colour.draw();
	fbo.end();

	spout.sendTexture(fbo.getTexture(), "colour");

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	ofClear(0, 0, 0, 255);
	fbo.draw(0, 0);



	//remove for glsl

	/*for (int i = 0; i < ofGetWidth(); i++) {
		ofSetColor(c[i]);
		ofDrawRectangle(i, ofGetHeight() / 2, 1, ofGetHeight() / 2);
	}*/

	gui.draw();



}

void ofApp::exit() {
	spout.exit();
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
