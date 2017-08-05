#include "input_selector.h"

//-----------------------------
void input_selector::setup() {
	
	image = false;
	camera = false;
	video = false;
	colour = false;
	no_input = false;
	Spout2 = false;

}


//----------------------
void input_selector::draw() {

	if (video == true) {
		vid.draw();
	}

	else if (image == true) {
		img.draw();
	}

	else if (camera == true) {
		cam.draw();
	}

	else if (colour == true) {
		gradient.draw();
	}

	else if (Spout2 == true) {
		spout.draw();
	}

}

void input_selector::selection() {

	if (params.input_type == 0) {

		video = false;
		image = false;
		camera = false;
		colour = false;
		no_input = true;
		Spout2 = false;

		img.clear();
		cam.close();
		vid.close();
		spout.exit();

	}

	if (params.input_type == 1) {

		video = true;
		image = false;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = false;

		img.clear();
		cam.close();
		spout.exit();

		vid.setup();
	}

	else if (params.input_type == 2) {

		video = false;
		image = true;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = false;

		vid.close();
		cam.close();
		spout.exit();

		img.setup();
	}

	else if (params.input_type == 3) {

		video = false;
		image = false;
		camera = true;
		colour = false;
		no_input = false;
		Spout2 = false;

		img.clear();
		vid.close();
		spout.exit();

		cam.setup();
	}

	else if (params.input_type == 4) {

		video = false;
		image = false;
		camera = false;
		colour = true;
		no_input = false;
		Spout2 = false;

		img.clear();
		vid.close();
		spout.exit();
		cam.close();

		gradient.setup(ofGetWidth(), ofGetHeight());
	}

	else if (params.input_type == 5) {

		video = false;
		image = false;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = true;

		img.clear();
		vid.close();
		cam.close();

		spout.setup();
	}
}