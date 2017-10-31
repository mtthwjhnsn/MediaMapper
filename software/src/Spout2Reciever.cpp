#include "Spout2Reciever.h"

void Spout2Reciever::setup() {

	ofxSpout2::Receiver add;

	ofTexture addTex;

	for (int i = 0; i <= 9; i++) {
		spoutRecievers.push_back(add);
		spoutRecievers[i].setup();
		texs.push_back(addTex);
	}

}

void Spout2Reciever::draw(int selection, int x, int y, int w, int h) {
	spoutRecievers[selection].updateTexture();
	texs[selection] = spoutRecievers[selection].getTexture();
}

void Spout2Reciever::spout_list(int selection) {
	spoutRecievers[selection].showSenders();
}

void Spout2Reciever::add_reciever(int selection){

	ofxSpout2::Receiver add;
	add.setup();
	
	ofTexture addTex;

	spoutRecievers.push_back(add);
	texs.push_back(addTex);

}

void Spout2Reciever::exit() {
	//spoutReciever.exit();

}