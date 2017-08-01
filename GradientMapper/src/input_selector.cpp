#include "input_selector.h"

//-----------------------------
void input_selector::setup() {

	

	image = false;
	camera = false;
	video = false;
	colour = false;
	no_input = false;

}


//----------------------
void input_selector::draw() {
	
	if (no_input == true) {
		img.clear();
		cam.close();
		vid.close();

	}

	if (video == true) {
		img.clear();
		cam.close();

		vid.draw();
	}

	else if (image == true) {
		vid.close();
		cam.close();

		img.draw();
	}

	else if (camera == true) {
		img.clear();
		vid.close();

		cam.draw();
	}

	else if (colour == true) {
		img.clear();
		vid.close();
		cam.close();

		gradient.draw();
	}

}

void input_selector::selection() {

	if (params.input_type == 0) {

		video = false;
		image = false;
		camera = false;
		colour = false;
		no_input = true;

	}

	if (params.input_type == 1) {

		video = true;
		image = false;
		camera = false;
		colour = false;
		no_input = false;

		vid.setup();
	}

	else if (params.input_type == 2) {

		video = false;
		image = true;
		camera = false;
		colour = false;
		no_input = false;

		img.setup();
	}

	else if (params.input_type == 3) {

		video = false;
		image = false;
		camera = true;
		colour = false;
		no_input = false;

		cam.setup();
	}

	else if (params.input_type == 4) {

		video = false;
		image = false;
		camera = false;
		colour = true;
		no_input = false;

		gradient.setup(ofGetWidth(), ofGetHeight());
	}
}