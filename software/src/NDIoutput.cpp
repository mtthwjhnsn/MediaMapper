#include "NDIoutput.h"



void NDIoutput::setup() {

//	fbo.allocate(1920, 1080);

	//NDI

	strcpy(senderName, "Openframeworks NDI Sender"); // Set the sender name
	ofSetWindowTitle(senderName); // show it on the title bar
	cout << "NDI SDK copyright NewTek (http:\\NDI.NewTek.com)" << endl;

	// Set the dimensions of the sender output here
	// This is independent of the size of the display window
	senderWidth = 1920; // HD - PBO 150fps / 120fps Async/Sync unclocked
	senderHeight = 1080; //      FBO  80fps /  75fps Async/Sync unclocked

	// Create an fbo for collection of data
	ndiFbo.allocate(senderWidth, senderHeight, GL_RGBA);

	// Initialize ofPixel buffers
	ndiBuffer[0].allocate(senderWidth, senderHeight, 4);
	ndiBuffer[1].allocate(senderWidth, senderHeight, 4);

	// Optionally set NDI asynchronous sending instead of clocked at 60fps
	ndiSender.SetAsync(false); // change to true for async

	// Create a new sender

	// Specify RGBA format here
	ndiSender.CreateSender(senderName, senderWidth, senderHeight, NDIlib_FourCC_type_RGBA);
	cout << "Created NDI sender [" << senderName << "] (" << senderWidth << "x" << senderHeight << ")" << endl;
	idx = 0; // index used for buffer swapping

	// 3D drawing setup for the demo graphics
	//glEnable(GL_DEPTH_TEST);                           // enable depth comparisons and update the depth buffer
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	//ofDisableArbTex();                                 // needed for textures to work
	//textureImage.loadImage("NDI_Box.png");             // Load a texture image for the demo
	//rotX = 0; // Cube rotation
	//rotY = 0;

	// Initialize OpenGL pbos for asynchronous read of fbo data
	glGenBuffers(2, ndiPbo);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, ndiPbo[0]);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, senderWidth*senderHeight * 4, 0, GL_STREAM_READ);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, ndiPbo[1]);
	glBufferDataARB(GL_PIXEL_UNPACK_BUFFER_ARB, senderWidth*senderHeight * 4, 0, GL_STREAM_READ);
	glBindBufferARB(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

	PboIndex = NextPboIndex = 0;
	bUsePBO = true; // Change to false to compare
	
}


void NDIoutput::send(ofFbo fbo, int x, int y, int w, int h){
	
	ndiFbo.begin();
	ofClear(13, 25, 76, 255); // background as required
	
	// ============ your application draw goes here ===============

	ofSetColor(255);
	ofClear(0, 0, 0, 255);
	fbo.draw(x, y, 1920, 1080);

	// =============================================================

	
	// End the fbo
	ndiFbo.end();

	// Draw the fbo result fitted to the display window
	//ndiFbo.draw(0, 0, ofGetWidth(), ofGetHeight());

	// For asynchronous sending, alternate between buffers because one buffer is being
	// filled in while the second is "in flight" and being processed by the API.
	if (ndiSender.GetAsync())
	idx = (idx + 1) % 2;

	// Extract pixels from the fbo.
	if (bUsePBO) {
	// Read fbo using two pbos
	ReadFboPixels(ndiFbo, senderWidth, senderHeight, ndiBuffer[idx].getPixels());
	}
	else {
	// Read fbo directly
	ndiFbo.bind();
	glReadPixels(0, 0, senderWidth, senderHeight, GL_RGBA, GL_UNSIGNED_BYTE, ndiBuffer[idx].getPixels());
	ndiFbo.unbind();
	}

	// Send the RGBA ofPixels buffer to NDI
	// If you did not set the sender pixel format to RGBA in CreateSender
	// you can convert to bgra within SendImage (specify true for bSwapRB)
	if (ndiSender.SendImage(ndiBuffer[idx].getPixels(), senderWidth, senderHeight)) {
	// Show what it is sending
	char str[256];
	sprintf(str, "Sending as : [%s] (%dx%d)", senderName, senderWidth, senderHeight);
	ofDrawBitmapString(str, 20, 30);
	// Show fps
	sprintf(str, "fps: %3.3d", (int)ofGetFrameRate());
	ofDrawBitmapString(str, ofGetWidth() - 120, 30);
	}

}

//
// Asynchronous Read-back
//
// adapted from : http://www.songho.ca/opengl/gl_pbo.html
//


bool NDIoutput::ReadFboPixels(ofFbo fbo, unsigned int width, unsigned int height, unsigned char *data)
{
void *pboMemory;

PboIndex = (PboIndex + 1) % 2;
NextPboIndex = (PboIndex + 1) % 2;

// Bind the fbo passed in
fbo.bind();

// Set the target framebuffer to read
glReadBuffer(GL_FRONT);

// Bind the current PBO
glBindBuffer(GL_PIXEL_PACK_BUFFER, ndiPbo[PboIndex]);

// Read pixels from framebuffer to the current PBO - glReadPixels() should return immediately.
//glReadPixels(0, 0, width, height, GL_BGRA_EXT GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)0);
// Send RGBA
glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)0);

// Map the previous PBO to process its data by CPU
glBindBuffer(GL_PIXEL_PACK_BUFFER, ndiPbo[NextPboIndex]);
pboMemory = glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
if (pboMemory) {
// Use SSE2 mempcy
ofxNDIutils::CopyImage((unsigned char *)pboMemory, data, width, height, width * 4);
glUnmapBuffer(GL_PIXEL_PACK_BUFFER);
}
else {
glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
fbo.unbind();
return false;
}

// Back to conventional pixel operation
glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
fbo.unbind();

return true;

}

void NDIoutput::exit() {
if (ndiPbo[0]) glDeleteBuffers(2, ndiPbo);
}
