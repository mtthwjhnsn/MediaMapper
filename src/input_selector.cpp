#include "input_selector.h"

//-----------------------------
void input_selector::setup(ImageLoader *_img, CamLoader *_cam, VideoLoader *_vid, Spout2Reciever * _spoutIn, ShaderToy * _shaderToy, NDIoutput * _ndiOut) {

	vid = _vid;
	img = _img;
	cam = _cam;
	spoutIn = _spoutIn;
	shaderToy = _shaderToy;
	ndiOut = _ndiOut;

	vector<string> select = {"input0.png", "input1.png", "input2.png", "input3.png", "input4.png", "input5.png", "input6.png", "input7.png", "input8.png", "input9.png" };
	
	for (int i = 0; i <= 9; i++) {
		splash.load(select[i]);
		splashes.push_back(splash);
	}

	shaderToy->setup();
	ndiOut->setup();

}

void input_selector::splash_draw(int test_pattern, int x, int y, int w, int h) {
	splashes[test_pattern].draw(x, y, w, h);

}

void input_selector::video_draw(int x, int y, int w, int h) {
	vid->draw(x, y, w, h);
}

void input_selector::video_drawThumbs(int selection, int x, int y, int w, int h) {
	vid->drawThumbs(selection, x, y, w, h);
}

void input_selector::video_swap(int selection) {
	vid->swap(selection);
}

void input_selector::image_drawThumbs(int selection, int x, int y, int w, int h) {
	img->drawThumbs(selection, x, y, w, h);
}

void input_selector::image_draw(int x, int y, int w, int h) {
	img->draw(x, y, w, h);
}

void input_selector::image_swap(int selection) {
	img->swap(selection);
}

void input_selector::camera_draw(int selection, int x, int y, int w, int h) {
	cam->draw(selection, x, y, w, h);
}

void input_selector::spout_draw(int selection, int x, int y, int w, int h) {
	spoutIn->draw(selection, x, y, w, h);
}
void input_selector::spout_list(int selection) {
	spoutIn->spout_list(selection);
}

void input_selector::shader_draw(int selection, int x, int y, int w, int h){
	shaderToy->draw(selection, x, y, w, h);
}

void input_selector::NDI_out(ofFbo fbo, int x, int y, int w, int h) {
	ndiOut->send(fbo, x, y, w, h);
}