#include "ImageLoader.h"

void ImageLoader::setup() {

	ofFileDialogResult result = ofSystemLoadDialog("Load file");
	if (result.bSuccess) {
		string path = result.getPath();
		// load your file at `path`
		image.load(path);

	}
}

void ImageLoader::draw(int x, int y, int w, int h) {
	image.draw(x, y, w, h);
}

void ImageLoader::clear() {
	image.clear();
}
