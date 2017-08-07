//---------------
//----GuiColourGradient.h
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ColourGradient.h"
#include "Sound.h"
#include "input_selector.h"
#include "output_selector.h"
#include "NDIoutput.h"

class GuiColourGradient {
public:
	void setup(ColourGradient *_colour, Sound *_sound, input_selector *_inputs, output_selector *_outputs, NDIoutput *_NDI);
	//void update();
	void draw();

	
	GLuint getTextureID();
	GLuint getTextureID1();
	GLuint getTextureID2();
	GLuint getTextureID3();
	GLuint getTextureID4();
	GLuint getTextureID5();
	GLuint getTextureID6();

	GLuint getTextureID7();

	void lfo_selection(int* type_param);
	void lfo_selection_red(int* type_param_red);
	void lfo_selection_green(int* type_param_green);
	void lfo_selection_blue(int* type_param_blue);
	void sound_selection(int* sound_param);
	void oscillator(int* oscillator_param);

	


private:
	ColourGradient *colour;
	Sound *sound;
	input_selector *inputs;
	output_selector *outputs;
	NDIoutput *NDI;

	input_selector inputbutton;


	ofMesh mesh;
	ofFbo fbo;
	ofFbo fbo1;
	ofFbo fbo2;
	ofFbo fbo3;
	ofFbo fbo4;
	ofFbo fbo5;
	ofFbo fbo6;
	ofFbo fbo7;
	
	GLuint textureid;
	GLuint textureid1;
	GLuint textureid2;
	GLuint textureid3;
	GLuint textureid4;
	GLuint textureid5;
	GLuint textureid6;
	GLuint textureid7;
	
	ofShader shader;
	ofImage image;
	

	// Gui
	bool imGui();

	ofxImGui::Gui gui;
	bool guiVisible;
	bool mouseOverGui;
};
