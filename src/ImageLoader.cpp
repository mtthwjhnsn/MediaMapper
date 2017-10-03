#include "ImageLoader.h"

void ImageLoader::setup() {

	
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);


	/*
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			string path = result.getPath();

			threadedImage.loadFromDisk(image, path);
		}


		/*ofFileDialogResult result = ofSystemLoadDialog("Load file");
			if (result.bSuccess) {
				string path = result.getPath();
				image.load(path);
			}*/
		
	vector<string> select = { "input0.png", "input1.png", "input2.png", "input3.png", "input4.png", "input5.png", "input6.png", "input7.png", "input8.png", "input9.png" };


	for (int i = 0; i <= 9; i++) {
		
		//threadedImage.loadFromDisk(image, select[i]);
		image.load(select[i]);
		images.push_back(image);
	}

}

void ImageLoader::draw(int selection, int x, int y, int w, int h) {
	ofSetColor(255);
	images[selection].draw(x, y, w, h);
	}

void ImageLoader::clear() {
	/*
	threadedImage.stopThread();
	image.clear();
	*/
}
