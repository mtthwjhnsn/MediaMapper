#include "Spout2Reciever.h"



void Spout2Reciever::setup() {
	spoutReceiver.setup();
}

void Spout2Reciever::draw() {
	ofClear(255, 0, 0);

	spoutReceiver.updateTexture();
	//ofRect(0, 0, ofGetWidth(), ofGetHeight());
	spoutReceiver.getTexture().draw(0, 0, ofGetWidth(), ofGetHeight());
}

void Spout2Reciever::exit() {
	spoutReceiver.exit();
}