//
//  ColourGradient.hpp
//  ColourGradientTool
//
//  Created by Joshua Batty on 14/4/17.
//---------------
//----ADAPTED BY
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#pragma once 
#include "ofMain.h"
#include "ofxUbo.h"

enum FillType {
	SOLID,
	GRADIENT
};

struct GradientParams {
	ofVec3f dc;
	ofVec3f amp;
	ofVec3f freq;
	ofVec3f phase;
	float num_bands;
	float animate_speed;
	int palette_lfo_red;
	int palette_lfo_green;
	int palette_lfo_blue;
	int amp_lfo_type;
	int freq_lfo_type;
	int phase_lfo_type;

	float amp_lfo_speed;
	float freq_lfo_speed;
	float phase_lfo_speed;
	
	float amp_lfo_amp;
	float freq_lfo_amp;
	float phase_lfo_amp;
	
	float amp_cycle_speed;
	float freq_cycle_speed;
	float phase_cycle_speed;
};

class ColourGradient {
public:
	void setup(int w, int h);
	void draw();


	vector<ofColor> get_pixel_colours(int num_points);

	ofTexture& getTexture();
	GLuint getTextureID();

	GradientParams params;

	// Generate
	ofVec3f pal(float t, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d);
	float lfo(int type, float x);
	ofVec3f lfo(int type, ofVec3f x);
	ofColor get_colour(float pos);

	void set_fill_type(int type);
	int get_fill_type();

	float solid_colour[3];
	FillType fillType;

private:
	int w, h;
	ofxUboShader shader;
	ofFbo fbo;
	GLuint videoButtonID;
};
