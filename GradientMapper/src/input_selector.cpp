#include "input_selector.h"

//-----------------------------
void input_selector::setup() {

	

	image = false;
	camera = false;
	video = false;
	colour = false;

}


//----------------------
void input_selector::draw() {
	
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

		video = true;
		image = false;
		camera = false;
		colour = false;

		vid.setup();
	}

	else if (params.input_type == 1) {

		video = false;
		image = true;
		camera = false;
		colour = false;

		img.setup();
	}

	else if (params.input_type == 2) {

		video = false;
		image = false;
		camera = true;
		colour = false;

		cam.setup();
	}

	else if (params.input_type == 3) {

		video = false;
		image = false;
		camera = false;
		colour = true;

		gradient.setup(ofGetWidth(), ofGetHeight());
	}
}