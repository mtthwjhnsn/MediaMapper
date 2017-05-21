#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetVerticalSync(true);
	//ofEnableDepthTest();

	numLights = 12;
	numModules = 20;

	colour.setup(ofGetWidth(), ofGetHeight());
	gui.setup(&colour);


	//artnet

	// ARTNET (NULL is local IP) - note: the IP is this machine's IP
	// "" is local ip, subnet 0, long name, short name
	//    m_artnetSender.Init( "", 0, "OF Artnet Test", "OFTest" );
	//    m_artnetSender.Init( "192.168.0.112", 0, "OF Artnet Test", "OFTest" );
	m_artnetSender.Init("127.0.0.1", 0, "OF Artnet Test", "OFTest");

	memset(m_data, 128, 512); // clear the data
	for (int i = 0; i < 512; i++) {
		m_data[i] = 0;
	}
}

// Make sure to address the '6' later as the offset
int ofApp::getStartingAddress(int i, int split, int first_start_address, int second_start_address, int numChannels) {
	if (i < split) {
		return (i * numChannels) + (first_start_address - 1);
	}
	else {
		return ((i - split) * numChannels) + (second_start_address - 1);
	}
}


void ofApp::tempBottomEnd() {

	    vector<float> params;
    for(int i = 0; i < 512; i++){
        params.push_back(0.0);
    }

	int numLights = 7;
	int numChannels = 12;

	for (int i = 0; i < numLights; i++) {

		int starting_address = getStartingAddress(i, 3, 1, 241, numChannels);

		params[starting_address + 0] = 255; // Pan Fine
		params[starting_address + 1] = 255; // Tilt Coarse
		params[starting_address + 2] = 255; // Tilt Fine
		params[starting_address + 3] = 255;; // Fixture
		params[starting_address + 4] = 0; // Color W
		params[starting_address + 4] = 255;  // Red
		params[starting_address + 6] = 0; // Green
		params[starting_address + 7] = 255; // Blue
		params[starting_address + 8] = 255; // White
		params[starting_address + 9] = 0; // Green
		params[starting_address + 10] = 255; // Blue
		params[starting_address + 11] = 255; // White
	}

	///----------------- ARTNET
	// Subnet, universe, data, size of array.
	m_artnetSender.SendRawDMX(0, 0, m_data, 512);
}


//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	
	tempBottomEnd();

	int numChannels = 3;
	for (int i = 0; i < numLights; i++) {

		m_data[(i*numChannels)] = 255; // Pan Fin
		m_data[1 + (i*numChannels)] = 255; // Pan Fin
		m_data[2 + (i*numChannels)] = 255; // Pan Fin
	}
///----------------- ARTNET
//Subnet, universe, data, size of array.
//m_artnetSender.SendRawDMX( 0, 0, m_data, 512 );

}

//--------------------------------------------------------------
void ofApp::draw() {
	colour.draw();

	vector<ofColor> c = colour.get_pixel_colours(ofGetWidth());
	/*for (int i = 0; i < ofGetWidth(); i++) {
		ofSetColor(c[i]);
		ofDrawRectangle(i, ofGetHeight() / 2, 1, ofGetHeight() / 2);
	}*/
	gui.draw();
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
