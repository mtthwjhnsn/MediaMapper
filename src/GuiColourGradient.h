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
#include "ofxSpout2Sender.h"

class GuiColourGradient {
public:
	~GuiColourGradient() {};
	GuiColourGradient();


	int active;
	int active1;

	ofTrueTypeFont Overpass;

	vector<int> selectors;
	vector<int> add_instances;
	vector<int> toggles;
	vector<string> IDs;
	vector<vector<ImTextureID>> tex_vect;
	vector<vector<int>> select_vect;
	
	int input_num; //number of input types //test, video, image, camera, shader, spout, ndi

	void setup(ColourGradient *_colour, input_selector *_inputs, output_selector *_outputs);
	
	void draw(ofFbo fboinput);

	ImTextureID GuiID, TestID, VideoID, ImageID, CameraID, ShaderID, SpoutID, NDIID;
	vector<ImTextureID> gui_tex_ids, test_tex_ids, video_tex_ids, image_tex_ids, camera_tex_ids, shader_tex_ids, spout_tex_ids, ndi_tex_ids;

	ImTextureID getTextureIDGui(), getTextureIDTest(), getTextureIDVideo(), getTextureIDImage(), getTextureIDShader(), getTextureIDCamera(), getTextureIDSpout(), getTextureIDNDI();

	ofFbo GuiFbo, TestFbo, VideoFbo, ImageFbo, CameraFbo, ShaderFbo, SpoutFbo, NDIFbo;
	vector<ofFbo> GuiFbos, TestFbos, VideoFbos, ImageFbos, CameraFbos, ShaderFbos, SpoutFbos, NDIFbos;

	vector<bool> colours;

	void Resolutions();
	void Navigate();
	void InputWindow(int selection);
	void OutputWindow(int selection);
	void lfo_selection(int* type_param);
	//void lfo_selection_red(int* type_param_red);
	//void lfo_selection_green(int* type_param_green);
	//void lfo_selection_blue(int* type_param_blue);
	//void sound_selection(int* sound_param);
	//void oscillator(int* oscillator_param);

	//tile
	int tileXpos, tileYpos, tileWidth, tileHeight;
	float tileZoom;

private:

	ofFbo::Settings fboSettings;

	ColourGradient *colour;
	//Sound *sound;
	input_selector *inputs;
	output_selector *outputs;

	ofxSpout2::Sender spoutSender, spoutSender1, spoutSender2, spoutSender3, spoutSender4, spoutSender5, spoutSender6;

	ofMesh mesh;

	ofShader shader;
	ofImage image;

	// Gui
	bool imGui();

	ofxImGui::Gui gui;
	bool guiVisible;
	bool mouseOverGui;
};
