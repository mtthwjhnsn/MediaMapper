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
#include "Sound.h"
#include "input_selector.h"
#include "ofxSpout2Sender.h"
#include "ofxSpout2Receiver.h"
#include "NDIreciever.h"

class GuiColourGradient {
public:
	~GuiColourGradient() {};
	GuiColourGradient();

	ofTrueTypeFont Overpass;
	
	int activeVid;
	int activeImg;

	int vidArraySize; 
	vector<int> selectors;
	vector<int> add_instances;
	vector<int> toggles;
	vector<string> IDs;
	
	vector<vector<ImTextureID>> tex_vect;
	vector<vector<int>> select_vect;
	
	vector<vector<ofFbo>> fbo_vect;

	ImVector<ImVector<bool>> spoutBools;
	ImVector<bool> test_spout, video_spout, image_spout, camera_spout, shader_spout, spout_spout, ndi_spout;
	
	ImVector<ImVector<bool>> ndiBools;
	ImVector<bool> test_ndi, video_ndi, image_ndi, camera_ndi, shader_ndi, spout_ndi, ndi_ndi;
	
	int input_num; //number of input types //test, video, image, camera, shader, spout, ndi

	void setup(input_selector *_inputs);
	void update();
	void draw();

	ImTextureID GuiID, TestID, VideoID, ImageID, CameraID, ShaderID, SpoutID, NDIID;
	vector<ImTextureID> gui_tex_ids, test_tex_ids, video_tex_ids, image_tex_ids, camera_tex_ids, shader_tex_ids, spout_tex_ids, ndi_tex_ids;
	//vector<ofFbo> gui_tex_fbos, test_tex_fbos, video_tex_fbos, image_tex_fbos, camera_tex_fbos, shader_tex_fbos, spout_tex_fbos, ndi_tex_fbos;
	ImTextureID getTextureIDGui(), getTextureIDTest(), getTextureIDVideo(), getTextureIDImage(), getTextureIDShader(), getTextureIDCamera(), getTextureIDSpout(), getTextureIDNDI();

	ofFbo GuiFbo, TestFbo, VideoFbo, ImageFbo, CameraFbo, ShaderFbo, SpoutFbo, NDIFbo;
	vector<ofFbo> GuiFbos, TestFbos, VideoFbos, ImageFbos, CameraFbos, ShaderFbos, SpoutFbos, NDIFbos;
	vector<vector<ofFbo>> Fbos;
	vector<bool> colours;
	
	//ofxSpoutSe

	void Resolutions();
	void Navigate();
	void InputWindow(int selection);
	void OutputWindow(int selection);
	void styles();
	
	//void lfo_selection(int* type_param);
	//void lfo_selection_red(int* type_param_red);
	//void lfo_selection_green(int* type_param_green);
	//void lfo_selection_blue(int* type_param_blue);
	//void sound_selection(int* sound_param);
	//void oscillator(int* oscillator_param);

	//tile
	int tileXpos, tileYpos, tileWidth, tileHeight, canvasWidth, canvasHeight;
	float tileZoom;

	vector<ofxSpout2::Sender> test_spout_sends, video_spout_sends, image_spout_sends, camera_spout_sends, shader_spout_sends, spout_spout_sends, ndi_spout_sends;
	vector<vector<ofxSpout2::Sender>> spoutSenders;

	NDIreciever NDI_reciever;

	bool NDIsearching;

	bool SpoutSearching;
	bool setup_spout;

	int spoutNum;
	int ndiNum;

	ImGuiIO * io;
	ImFontConfig font_config;
	ImFont* f;
	//ImGuiStyle& style;


private:
	bool assign_styles;

	//ImFont *font1;
	ofFbo::Settings fboSettings;
	
//	ColourGradient *colour;
	//Sound *sound;
	input_selector *inputs;
	//output_selector *outputs;
		
	ofMesh mesh;

	ofShader shader;
	ofImage image;

	// Gui
	bool imGui();

	ofxImGui::Gui gui;
	bool guiVisible;
	bool mouseOverGui;
};
