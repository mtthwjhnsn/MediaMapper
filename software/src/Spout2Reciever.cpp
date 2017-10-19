#include "Spout2Reciever.h"

void Spout2Reciever::setup() {
	spoutReceiver.setup();
}

void Spout2Reciever::draw(int x, int y, int w, int h) {
	
	ofClear(255, 0, 0);
	spoutReceiver.updateTexture();
	spoutReceiver.getTexture().draw(x, y, w, h);
}

void Spout2Reciever::exit() {
	spoutReceiver.exit();
}