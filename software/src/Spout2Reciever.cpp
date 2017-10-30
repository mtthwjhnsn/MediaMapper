#include "Spout2Reciever.h"

void Spout2Reciever::setup() {
	spoutReceiver.setup();
}

void Spout2Reciever::draw(int x, int y, int w, int h) {
	
	ofClear(255, 0, 0);
	spoutReceiver.updateTexture();
	spoutReceiver.getTexture().draw(x, y, w, h);
}

//void Spout2Reciever::drawThumbs(int selection, int x, int y, int w, int h) {
//	if (imageThumbs.size() > 0) {
//		imageThumbs[selection].draw(x, y, w, h);
//	}
//}

void Spout2Reciever::exit() {
	spoutReceiver.exit();
}