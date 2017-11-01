#include "ImageLoader.h"

ImageLoader::ImageLoader()
{
}

ImageLoader::~ImageLoader()
{
}

void ImageLoader::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
}


void ImageLoader::draw(int x, int y, int w, int h) {
	image.draw(x, y, w, h);
}

void ImageLoader::drawThumbs(int selection, int x, int y, int w, int h) {
	if (imageThumbs.size() > 0) {
		imageThumbs[selection].draw(x, y, w, h);
	}
}

void ImageLoader::swap(int selection) {
	image.clear();
	//video.close();
	//image.setPixelFormat(OF_PIXELS_RGBA);
	image.load(imagePaths[selection]);
}

void ImageLoader::dragEvent(ofDragInfo info) {

	if (info.files.size() > 0) {

		filesSize = info.files.size();

		for (int i = 0; i < info.files.size(); i++) {

			cout << "file = " << info.files.at(i) << endl;

			const std::string sentence = info.files.at(i);

			vector<std::string> search = { ".jpg", ".bmp", ".png", ".cr2", ".CR2", ".tiff", ".gif", ".jpf", ".jp2" };

			size_t pos;

			for (int j = 0; j < search.size(); j++) {

				pos = sentence.find(search[j]);
				if (pos != std::string::npos) {

					//print image type
					std::cout << "image type: " << search[j] << std::endl;

					//pushback
					imagePaths.push_back(info.files.at(i));

					fileName = ofSplitString(imagePaths.back(), "\\"); //Find on the last name in the path
					fileName = ofSplitString(fileName.at(fileName.size() - 1), "."); //Remove the .mov extension from the fileName

					img.load(imagePaths.back());
					//img.play();

					if (img.isAllocated()) {
						cout << "LOADED!" << endl;
					}
					else {
						cout << "FUCK!" << endl;
					}

					//Basically until the image is loaded then all these calls aren't going to work

					if (img.isAllocated()) {

						ofImage image;

						image.setFromPixels(img.getPixels());

						image.crop(0, 0, img.getWidth(), img.getHeight());
						image.resize(100, 100);

						img.clear();

						image.save("ImageThumbnails/" + fileName.at(fileName.size() - 2) + ".png");

						image.load("ImageThumbnails/" + fileName.at(fileName.size() - 2) + ".png");
						
						imageThumbs.push_back(image);

						//swap(i);
					}
				}
			}
		}
	}
}
