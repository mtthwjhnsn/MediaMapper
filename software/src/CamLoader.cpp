#include "CamLoader.h"

void CamLoader::setup() {

	for (int i = 0; i <= 0; i++) {
		cam.setup(640, 480);
		cams.push_back(cam);
	}

}

void CamLoader::draw(int selection, int x, int y, int w, int h) {
	cams[selection].update();
	cams[selection].draw(x, y, w, h);
}

void CamLoader::close(int selection) {
	cams[selection].close();
}
