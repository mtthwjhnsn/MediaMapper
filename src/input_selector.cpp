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

	params.setup = false;

	select = "input1.png";
	splash.load(select);
}

void input_selector::splash_draw(int x, int y, int w, int h) {
	splash.draw(x, y, w, h);
}

void input_selector::video_draw(int x, int y, int w, int h) {
	vid->draw(x, y, w, h);
}

void input_selector::image_draw(int x, int y, int w, int h) {
	img->draw(x, y, w, h);
}

void input_selector::camera_draw(int x, int y, int w, int h) {
	cam->draw(x, y, w, h);
}

void input_selector::spout_draw(int x, int y, int w, int h) {
	spout->draw(x, y, w, h);
}

/*
void input_selector::draw(ofFbo fbo, int x, int y, int w, int h, ofFbo splash, ofFbo video, ) {

	if (no_input == true) {
		splash.draw(x, y, w, h);
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
		fbo.draw(x, y, w, h);
	}

	else if (Spout2 == true) {
		spout->draw(x, y, w, h);
	}

}*/

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

		params.setup = false;
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

		vid->setup();

		params.setup = false;
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

		params.setup = false;
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

		params.setup = false;
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

		params.setup = true;
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

		params.setup = false;
	}
}