#include "Spout2Sender.h"



void Spout2Sender::setup() {
	
	input.setup(&vid, &img, &cam, &col, &spout1);

	fbo.allocate(ofGetWidth(), ofGetHeight());
}

void Spout2Sender::send() {

	//SPOUT
	fbo.begin();
	
	// ============ your application draw goes here ===============

	input.draw(0, 0, 1920, 1080);
	
	// =============================================================
	
	//SPOUT
	fbo.end();

	spout.sendTexture(fbo.getTexture(), "GradientMapper");

}

void Spout2Sender::exit() {

	spout.exit();

}