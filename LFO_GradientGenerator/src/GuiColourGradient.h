//
//Matthew Johnson
//Colour Sound Synth
//
//

#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ColourGradient.h"
#include "Sound.h"

//#include "ofxMaxim.h"




class GuiColourGradient {
public:
	void setup(ColourGradient *_colour, Sound *_sound);
	void draw();

	
	GLuint getTextureID();
	GLuint getTextureID2();
	GLuint getTextureID3();
	GLuint getTextureID4();

	void lfo_selection(int* type_param);
	void lfo_selection_red(int* type_param_red);
	void lfo_selection_green(int* type_param_green);
	void lfo_selection_blue(int* type_param_blue);
	void sound_selection(int* sound_param);



private:
	ColourGradient *colour;
	Sound *sound;

	ofMesh mesh;
	ofFbo fbo;
	ofFbo fbo2;

	ofFbo fbo3;
	ofFbo fbo4;


	GLuint textureid;
	GLuint textureid2;
	GLuint textureid3;
	GLuint textureid4;

	ofShader shader;
	ofImage image;
	

	// Gui
	bool imGui();

	ofxImGui::Gui gui;
	bool guiVisible;
	bool mouseOverGui;

	
};
