//
//  ColourGradient.cpp
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

#include "ColourGradient.h"

//--------------------------------------------------------------
void ColourGradient::setup(int w, int h) {
	this->w = w;
	this->h = h;
	shader.load("shaders/Colour_Gradient");
	fillType = FillType::GRADIENT;
	solid_colour[0] = 1.0;
	solid_colour[1] = 0.0;
	solid_colour[2] = 0.0;

	params.dc = ofVec3f(0.5, 0.35, 0.5);
	params.amp = ofVec3f(0.5, 0.5, 0.5);
	params.freq = ofVec3f(0.5, 1.0, 0.5);
	params.phase = ofVec3f(0.338, 0.090, 0.230);

	params.num_bands = 1.0;
	params.animate_speed = 0.15;

	params.palette_lfo_red = 0;
	params.palette_lfo_green = 0;
	params.palette_lfo_blue = 0;

	params.amp_lfo_type = 0;
	params.freq_lfo_type = 0;
	params.phase_lfo_type = 0;

	params.amp_lfo_speed = 0.0;
	params.freq_lfo_speed = 0.0;
	params.phase_lfo_speed = 0.0;

	params.amp_lfo_amp = 0.0;
	params.freq_lfo_amp = 0.0;
	params.phase_lfo_amp = 0.0;

	params.amp_cycle_speed = 0.0;
	params.freq_cycle_speed = 0.0;
	params.phase_cycle_speed = 0.0;

	ofFbo::Settings fboSettings;
	fboSettings.width = w;
	fboSettings.height = h;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;
	fbo.allocate(fboSettings);
	videoButtonID = fbo.getTexture().texData.textureID;

}

//--------------------------------------------------------------
void ColourGradient::set_fill_type(int type) {
	fillType = (FillType)type;
}
int ColourGradient::get_fill_type() {
	return fillType;
}

//--------------------------------------------------------------
GLuint ColourGradient::getTextureID() {
	return videoButtonID;
}

//--------------------------------------------------------------
ofTexture& ColourGradient::getTexture() {
	return fbo.getTexture();
}

//--------------------------------------------------------------
vector<ofColor> ColourGradient::get_pixel_colours(int num_points) {
	vector<ofColor> c;
	for (int i = 0; i < num_points; i++) {
		float idx = ofMap(i, 0, num_points, 0.0, 1.0);
		c.push_back(get_colour(idx));
	}
	return c;
}

//--------------------------------------------------------------
void ColourGradient::draw() {

	fbo.begin();
	ofClear(0, 0, 0, 0);
	shader.begin();
	shader.setUniform3f("iResolution", w, h, 1);
	shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
	shader.setUniformBuffer("Params", params);


	ofDrawRectangle(0, 0, w, h);
	shader.end();

	fbo.end();

	ofSetColor(255);
	fbo.draw(0, 0);

	//fbo.readToPixels(pix);
	//int pix_h = 1;
	//glReadPixels(0, 0,w, pix_h, GL_RGB, GL_UNSIGNED_BYTE, pix.getPixels());
}

//--------- LFO's --------------
float fract(float f) {
	float temp;
	return modf(f, &temp);
}

// FLOATS
float tri(float x) {
	return asin(sin(x)) / (PI / 2.);
}
float puls(float x) {
	return (floor(sin(x)) + 0.5)*2.;
}
float saw(float x) {
	return (fract((x / 2.) / PI) - 0.5)*2.;
}
float noise(float x) {
	return (fract(sin((x*2.) *(12.9898 + 78.233)) * 43758.5453) - 0.5)*2.;
}

// VEC3
ofVec3f tri(ofVec3f x) {
	ofVec3f val;
	val[0] = asin(sin(x[0])) / (PI / 2.);
	val[1] = asin(sin(x[1])) / (PI / 2.);
	val[2] = asin(sin(x[2])) / (PI / 2.);
	return val;
}
ofVec3f puls(ofVec3f x) {
	ofVec3f val;
	val[0] = (floor(sin(x[0])) + 0.5)*2.;
	val[1] = (floor(sin(x[1])) + 0.5)*2.;
	val[2] = (floor(sin(x[2])) + 0.5)*2.;
	return val;
}
ofVec3f saw(ofVec3f x) {
	ofVec3f val;
	val[0] = (fract((x[0] / 2.) / PI) - 0.5)*2.;
	val[1] = (fract((x[1] / 2.) / PI) - 0.5)*2.;
	val[2] = (fract((x[2] / 2.) / PI) - 0.5)*2.;
	return val;
}
ofVec3f noise(ofVec3f x) {
	ofVec3f val;
	val[0] = (fract(sin((x[0] * 2.) *(12.9898 + 78.233)) * 43758.5453) - 0.5)*2.;
	val[1] = (fract(sin((x[1] * 2.) *(12.9898 + 78.233)) * 43758.5453) - 0.5)*2.;
	val[2] = (fract(sin((x[2] * 2.) *(12.9898 + 78.233)) * 43758.5453) - 0.5)*2.;
	return val;
}

//--------- LFO's --------------
float ColourGradient::lfo(int type, float x) {
	float val;
	if (type == 0) return sin(x);
	else if (type == 1) return tri(x);
	else if (type == 2) return saw(x);
	else if (type == 3) return puls(x);
	else if (type == 4) return noise(x);
	else return 0.0;
}
ofVec3f ColourGradient::lfo(int type, ofVec3f x) {
	if (type == 0) return ofVec3f(cos(x[0]), cos(x[1]), cos(x[2]));
	else if (type == 1) return tri(x);
	else if (type == 2) return saw(x);
	else if (type == 3) return puls(x);
	else if (type == 4) return noise(x);
	else return ofVec3f(0.0);
}

//--------- Colour Palette
ofVec3f ColourGradient::pal(float t, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d)
{
	ofVec3f out_pal = ofVec3f(a.x + b.x*lfo(params.palette_lfo_red, (6.28318*(c.x*t + d.x))),
		a.y + b.y*lfo(params.palette_lfo_green, (6.28318*(c.y*t + d.y))),
			a.z + b.z*lfo(params.palette_lfo_blue, (6.28318*(c.z*t + d.z))));

	return out_pal;
}

//--------------------------------------------------------------
ofColor ColourGradient::get_colour(float pos) {
	if (fillType == FillType::GRADIENT) {
		float x_pos = pos;
		// animate
		float t = ofGetElapsedTimef();
		x_pos += (params.animate_speed*3.0)*t;

		ofVec3f col = pal(x_pos, params.dc,
			(lfo(params.amp_lfo_type, t*params.amp_lfo_speed)*params.amp_lfo_amp) + params.amp + (t*(params.amp_cycle_speed*0.1)),
			(lfo(params.freq_lfo_type, t*params.freq_lfo_speed)*params.freq_lfo_amp) + params.freq + (t*(params.freq_cycle_speed*0.1)),
			(lfo(params.phase_lfo_type, t*params.phase_lfo_speed)*params.phase_lfo_amp) + params.phase + (t*(params.phase_cycle_speed*0.1)));

		//cout << "col = " << col << endl;
		//col.x = ofClamp(col.x,-1.0,1.0);
		//col.y = ofClamp(col.y,-1.0,1.0);
		//col.z = ofClamp(col.z,-1.0,1.0);

		//col.x = ofWrap(col.x,0.0,1.0);
		//col.y = ofWrap(col.y,0.0,1.0);
		//col.z = ofWrap(col.z,0.0,1.0);

		col.x = ofMap(col.x, 0.0, 1.0, 0, 255);
		col.y = ofMap(col.y, 0.0, 1.0, 0, 255);
		col.z = ofMap(col.z, 0.0, 1.0, 0, 255);

		col.x = ofClamp(col.x, 0, 255);
		col.y = ofClamp(col.y, 0, 255);
		col.z = ofClamp(col.z, 0, 255);

		return ofColor(col.x, col.y, col.z);
	}
	else {
		return ofColor(solid_colour[0] * 255, solid_colour[1] * 255, solid_colour[2] * 255);
	}



}
