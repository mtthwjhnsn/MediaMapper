#pragma once

#include "ofMain.h"
#include "ofxNDI.h"

class NDIoutput
{
public:

	~NDIoutput() {};
	NDIoutput() {};


	void setup();
	void send(ofFbo fbo);
	void exit();

	//ofFbo fbo;

	//input_selector input;

	GLuint textureid;

	
private:

	ofxNDIsender ndiSender;    // NDI sender object
	char senderName[256];      // Sender name
	unsigned int senderWidth;  // Width of the sender output
	unsigned int senderHeight; // Height of the sender output
	ofFbo ndiFbo;              // Fbo used for data transfer
	ofPixels ndiBuffer[2];     // Two pixel buffers for async sending
	int idx;                   // Index used for async buffer swapping
	ofImage textureImage;      // Texture image for the 3D cube graphics
	float rotX, rotY;          // Cube rotation increment

	GLuint ndiPbo[2];
	int PboIndex;
	int NextPboIndex;
	bool bUsePBO;
	bool ReadFboPixels(ofFbo fbo, unsigned int width, unsigned int height, unsigned char *data);

};