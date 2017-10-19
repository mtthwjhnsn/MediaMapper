#include "Spout2Sender.h"



void Spout2Sender::setup() {
	Spout2fbo.allocate(1920, 1080);

}

void Spout2Sender::send(ofFbo fbo) {

		//SPOUT
	Spout2fbo.begin();
	
	// ============ your application draw goes here ===============

	fbo.draw(0, 0, 1920, 1080);
	
	// =============================================================
	
	//SPOUT
	Spout2fbo.end();

	spout.sendTexture(Spout2fbo.getTexture(), "GradientMapper");

}

void Spout2Sender::exit() {

	spout.exit();

}