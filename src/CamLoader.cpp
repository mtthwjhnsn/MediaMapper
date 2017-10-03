#include "CamLoader.h"

void CamLoader::setup() {
	cam.setup(640, 480);
}

void CamLoader::draw(int x, int y, int w, int h) {
	cam.update();
	cam.draw(x, y, w, h);
}

void CamLoader::close() {
	cam.close();
}
