#include "CamLoader.h"

void CamLoader::setup() {

	cam.setup(640, 480);

}

void CamLoader::draw() {
	cam.update();
	cam.draw(0, 0, ofGetWidth(), ofGetHeight());

}

void CamLoader::close() {
	cam.close();
}
