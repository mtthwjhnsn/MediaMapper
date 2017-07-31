#include "input_selector.h"






//-----------------------------
void input_selector::setup() {

	params.img = false;
	params.camera = false;
	params.video = false;

}


//----------------------
void input_selector::draw() {
	
	if (params.input_type == 0) {

		image.clear();
		cam.close();

		player.draw();
	}

	else if (params.input_type == 1) {
		player.close();
		cam.close();

		image.draw();
	}

	else if (params.input_type == 2) {
		image.clear();
		player.close();

		cam.draw();
	}

	else if (params.input_type == 3) {
		image.clear();
		player.close();

		cam.draw();
	}

}

void input_selector::selection() {

	if (ofGetMouseX() <= ofGetWidth() / 2) {

		params.video = true;
		params.img = false;
		params.camera = false;

		player.setup();
	}
	else if (ofGetMouseX() > ofGetWidth() * 1 / 3 && ofGetMouseX() < ofGetWidth() * 2 / 3) {

		params.video = false;
		params.img = true;
		params.camera = false;

		image.setup();
	}

	else if (ofGetMouseX() > ofGetWidth() * 2 / 3) {

		params.video = false;
		params.img = false;
		params.camera = true;


		cam.setup();


	}
}