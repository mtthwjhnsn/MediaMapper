#include "input_selector.h"

//-----------------------------
void input_selector::setup(VideoLoader *_vid, ImageLoader *_img, CamLoader *_cam, ColourGradient *_gradient, Spout2Reciever *_spout) {

	vid = _vid;
	img = _img;
	cam = _cam;
	gradient = _gradient;
	spout = _spout;

	video = false;
	image = false;
	camera = false;
	colour = false;
	no_input = true;
	Spout2 = false;

	select = "input1.png";
	splash.load(select);




}

void input_selector::draw(int x, int y, int w, int h) {

	if (no_input == true) {
		splash.draw(x, y, w, h);
		//ofSetColor(255);
		//ofEllipse(sin(ofGetFrameNum()), 0, 600, 600);
	}

	if (video == true) {
		vid->draw(x, y, w, h);
	}

	else if (image == true) {
		img->draw(x, y, w, h);
	}

	else if (camera == true) {
		cam->draw(x, y, w, h);
	}

	else if (colour == true) {
		gradient->draw();
	}

	else if (Spout2 == true) {
		spout->draw(x, y, w, h);
	}

}

void input_selector::selection() {
	int menu_input = params.input_type;

	if (menu_input == 0) {

		video = false;
		image = false;
		camera = false;
		colour = false;
		no_input = true;
		Spout2 = false;

		img->clear();
		cam->close();
		vid->close();
		spout->exit();

		splash.clear();
		splash.load(select);
	}

	if (menu_input == 1) {

		video = true;
		image = false;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = false;

		splash.clear();

		img->clear();
		cam->close();
		spout->exit();

		//vid.close();
		vid->setup();
	}

	else if (menu_input == 2) {

		video = false;
		image = true;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = false;

		splash.clear();

		vid->close();
		cam->close();
		spout->exit();

		img->clear();
		img->setup();
	}

	else if (menu_input == 3) {

		video = false;
		image = false;
		camera = true;
		colour = false;
		no_input = false;
		Spout2 = false;

		splash.clear();

		img->clear();
		vid->close();
		spout->exit();

		cam->close();
		cam->setup();
	}

	else if (menu_input == 4) {

		video = false;
		image = false;
		camera = false;
		colour = true;
		no_input = false;
		Spout2 = false;

		splash.clear();

		img->clear();
		vid->close();
		spout->exit();
		cam->close();

		gradient->setup(ofGetWidth(), ofGetHeight());
	}

	else if (menu_input == 5) {

		video = false;
		image = false;
		camera = false;
		colour = false;
		no_input = false;
		Spout2 = true;

		splash.clear();

		img->clear();
		vid->close();
		cam->close();

		spout->exit();
		spout->setup();
	}
}