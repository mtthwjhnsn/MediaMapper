#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofBackground(255);
	load = 0;

	//thread.setup();
	thread.startThread();
	//thread.setup();
	//thread.startThread();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	if (load >= 1) {
	//	thread.draw(load, 10 + load * 200, 10, 200, 200);
	}
	//thread.startThread();
	//thread.draw(load, 0, 0, ofGetWidth(), ofGetHeight());
}

////--------------------------------------------------------------
void ofApp::keyPressed(int key){
//	if (key == 't') {
	if (key == 'a') {
		load = load - 1; // do something
	}
	if (key == 'd') {
		load = load + 1; // do something
	}
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

void ofApp::exit() {
	thread.stopThread();
}
