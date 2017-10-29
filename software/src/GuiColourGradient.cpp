//--------------
//  GuiColourGradient.cpp
// --------------
//  Created by Joshua Batty on 4/4/17.
//---------------
//---------------
//--- ADAPTED BY 
//----MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

//--------------------------------------------------------------
#include "GuiColourGradient.h"
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

//--------------------------------------------------------------
GuiColourGradient::GuiColourGradient() {
	
	tileXpos = 0;
	tileYpos = 0;
	tileWidth = 256;
	tileHeight = 144;

	canvasWidth = 1280;
	canvasHeight = 720;

	tileZoom = 0.25;
}


//-------------------------------------------------
void GuiColourGradient::setup(ColourGradient *_colour, input_selector *_inputs, output_selector *_outputs) {



	//---------------
	gui.setup();
	guiVisible = true;

	colour = _colour;
	//sound = _sound;
	inputs = _inputs;
	outputs = _outputs;

	activeVid = 0;
	activeImg = 0;

	//fboSettings.width = w;
	//fboSettings.height = h;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;

	//fboSettings.width = w / 3;
	//fboSettings.height = h / 2;

	fboSettings.width = tileWidth;
	fboSettings.height = tileHeight;

	Overpass.load("/Overpass/Overpass-Regular.ttf", 100);

	input_num = 7;

	IDs = { "test", "video", "image", "camera", "shader", "spout", "ndi" };
	//spout = false;
	
	// populate vectors
	for (int i = 0; i <= input_num; i++) {
		
		add_instances.push_back(0);
		toggles.push_back(0);
		selectors.push_back(0);
	}

	for (int i = 0; i <= input_num; i++) {
		select_vect.push_back(selectors);
	}

	//allocate and clear fbos
	for (int i = 0; i <= 9; i++) {

		GuiFbo.allocate(fboSettings);
		GuiFbo.begin();
		ofClear(255, 255, 255, 0);
		GuiFbo.end();
		GuiFbos.push_back(GuiFbo);
		GuiID = (ImTextureID)GuiFbos[i].getTexture().texData.textureID;
		gui_tex_ids.push_back(GuiID);

	}

	for (int i = 0; i <= 9; i++) {

		TestFbo.allocate(fboSettings);
		TestFbo.begin();
		ofClear(255, 255, 255, 0);
		TestFbo.end();
		TestFbos.push_back(TestFbo);

		TestID = (ImTextureID)TestFbos[i].getTexture().texData.textureID;
		test_tex_ids.push_back(TestID);

		test_spout.push_back(false);
		test_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		VideoFbo.allocate(fboSettings);
		VideoFbo.begin();
		ofClear(255, 255, 255, 0);
		VideoFbo.end();
		VideoFbos.push_back(VideoFbo);

		VideoID = (ImTextureID)VideoFbos[i].getTexture().texData.textureID;
		video_tex_ids.push_back(VideoID);

		video_spout.push_back(false);
		video_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		ImageFbo.allocate(fboSettings);
		ImageFbo.begin();
		ofClear(255, 255, 255, 0);
		ImageFbo.end();
		ImageFbos.push_back(ImageFbo);

		ImageID = (ImTextureID)ImageFbos[i].getTexture().texData.textureID;
		image_tex_ids.push_back(ImageID);

		image_spout.push_back(false);
		image_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		CameraFbo.allocate(fboSettings);
		CameraFbo.begin();
		ofClear(255, 255, 255, 0);
		CameraFbo.end();
		CameraFbos.push_back(CameraFbo);

		CameraID = (ImTextureID)CameraFbos[i].getTexture().texData.textureID;
		camera_tex_ids.push_back(CameraID);

		camera_spout.push_back(false);
		camera_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		ShaderFbo.allocate(fboSettings);
		ShaderFbo.begin();
		ofClear(255, 255, 255, 0);
		ShaderFbo.end();
		ShaderFbos.push_back(ShaderFbo);

		ShaderID = (ImTextureID)ShaderFbos[i].getTexture().texData.textureID;
		shader_tex_ids.push_back(ShaderID);

		shader_spout.push_back(false);
		shader_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		SpoutFbo.allocate(fboSettings);
		SpoutFbo.begin();
		ofClear(255, 255, 255, 0);
		SpoutFbo.end();
		SpoutFbos.push_back(SpoutFbo);

		SpoutID = (ImTextureID)SpoutFbos[i].getTexture().texData.textureID;
		spout_tex_ids.push_back(SpoutID);

		spout_spout.push_back(false);
		spout_ndi.push_back(false);
	}

	for (int i = 0; i <= 9; i++) {

		NDIFbo.allocate(fboSettings);
		NDIFbo.begin();
		ofClear(255, 255, 255, 0);
		NDIFbo.end();
		NDIFbos.push_back(NDIFbo);

		NDIID = (ImTextureID)NDIFbos[i].getTexture().texData.textureID;
		ndi_tex_ids.push_back(NDIID);
	
		ndi_spout.push_back(false);
		ndi_ndi.push_back(false);
	}

	spoutBools.push_back(test_spout);
	spoutBools.push_back(video_spout);
	spoutBools.push_back(image_spout);
	spoutBools.push_back(camera_spout);
	spoutBools.push_back(shader_spout);
	spoutBools.push_back(spout_spout);
	spoutBools.push_back(ndi_spout);

	ndiBools.push_back(test_ndi);
	ndiBools.push_back(video_ndi);
	ndiBools.push_back(image_ndi);
	ndiBools.push_back(camera_ndi);
	ndiBools.push_back(shader_ndi);
	ndiBools.push_back(spout_ndi);
	ndiBools.push_back(ndi_ndi);


	tex_vect = { test_tex_ids, video_tex_ids, image_tex_ids, camera_tex_ids, shader_tex_ids, spout_tex_ids, ndi_tex_ids };
	Fbos = { GuiFbos, TestFbos, VideoFbos, ImageFbos, CameraFbos, ShaderFbos, SpoutFbos, NDIFbos };
	
	//mesh
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(1);

}

ImTextureID GuiColourGradient::getTextureIDGui() {
	return GuiID;
}
ImTextureID GuiColourGradient::getTextureIDTest() {
	return TestID;
}
ImTextureID GuiColourGradient::getTextureIDImage() {
	return ImageID;
}
ImTextureID GuiColourGradient::getTextureIDVideo() {
	return VideoID;
}
ImTextureID GuiColourGradient::getTextureIDCamera() {
	return CameraID;
}
ImTextureID GuiColourGradient::getTextureIDShader() {
	return ShaderID;
}
ImTextureID GuiColourGradient::getTextureIDSpout() {
	return SpoutID;
}
ImTextureID GuiColourGradient::getTextureIDNDI() {
	return NDIID;
}

void GuiColourGradient::update() {
}

//-------------------------------------------------
void GuiColourGradient::draw(ofFbo fboinput) {

	int w = 800;
	int h = 180;

	if (guiVisible) {
		//IMGUI		
		imGui();

	}
	float H = h * .5;

	float t = ofGetElapsedTimef();
	float speed = (colour->params.animate_speed*3.0)*t;

	float dc1 = colour->params.dc.x;
	float amp1 = colour->params.amp.x;
	float freq1 = colour->params.freq.x;
	float phase1 = colour->params.phase.x;


	float dc2 = colour->params.dc.y;
	float amp2 = colour->params.amp.y;
	float freq2 = colour->params.freq.y;
	float phase2 = colour->params.phase.y;

	float dc3 = colour->params.dc.z;
	float amp3 = colour->params.amp.z;
	float freq3 = colour->params.freq.z;
	float phase3 = colour->params.phase.z;

	float freq_lfo_amp = colour->params.freq_lfo_amp;
	float freq_lfo_speed = colour->params.freq_lfo_speed;
	float freq_cycle_speed = colour->params.freq_cycle_speed;

	float amp_lfo_amp = colour->params.amp_lfo_amp;
	float amp_lfo_speed = colour->params.amp_lfo_speed;
	float amp_cycle_speed = colour->params.amp_cycle_speed;

	float phase_lfo_amp = colour->params.phase_lfo_amp;
	float phase_lfo_speed = colour->params.phase_lfo_speed;
	float phase_cycle_speed = colour->params.phase_cycle_speed;

	//float phase3 = colour->params.phase.z;
	if (inputs->params.input_type == 4)
	{
		//FBO
		GuiFbos[0].begin();

		ofSetColor(50, 50, 50, 50);
		ofRect(0, 0, w, h);

		for (int i = 0; i < w; i++) {

			float xval = ofMap(i, 0, w, 0.00, 1.00, true);

			float red_wave = (colour->ColourGradient::lfo(colour->params.palette_lfo_red, 6.28318*(freq1*(speed + xval) + phase1)));
			float green_wave = colour->ColourGradient::lfo(colour->params.palette_lfo_green, 6.28318*(freq2*(speed + xval) + phase2));
			float blue_wave = colour->ColourGradient::lfo(colour->params.palette_lfo_blue, 6.28318*(freq3*(speed + xval) + phase3));

			mesh.addVertex(ofVec2f(i, dc1 * H + H * amp1 * red_wave));
			mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));

			mesh.addVertex(ofVec2f(i, dc2 * H + H * amp2 * green_wave));
			mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));

			mesh.addVertex(ofVec2f(i, dc3 * H + H * amp3 * blue_wave));
			mesh.addColor(ofFloatColor(0.0, 0.0, 1.0));
		}

		mesh.drawVertices();
		mesh.clearVertices();
		mesh.clearColors();
		GuiFbos[0].end();

		int _w = w / 3;
		int _h = h / 2;
		int _H = _h * .5;

		//frequency lfo
		GuiFbos[1].begin();
		ofSetColor(50, 50);
		ofRect(0, 0, _w, _h);
		for (int i = 0; i < _w; i++) {
			float xval = ofMap(i, 0, _w, 0.00, 1.00, true);
			float freq_wave = (colour->ColourGradient::lfo(colour->params.freq_lfo_type, 6.28318*(freq_cycle_speed * xval + 1)));
			mesh.addVertex(ofVec2f(i, H / 2 + H * freq_lfo_amp * freq_wave));
			mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
		}
		mesh.drawVertices();
		mesh.clearVertices();
		mesh.clearColors();
		GuiFbos[1].end();

		// amp lfo
		GuiFbos[2].begin();
		ofSetColor(50, 50);
		ofRect(0, 0, _w, _h);
		for (int i = 0; i < _w; i++) {
			float xval = ofMap(i, 0, _w, 0.00, 1.00, true);
			float amp_wave = (colour->ColourGradient::lfo(colour->params.amp_lfo_type, 6.28318*(amp_cycle_speed * xval + 1)));
			mesh.addVertex(ofVec2f(i, H / 2 + H * amp_lfo_amp * amp_wave));
			mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
		}
		mesh.drawVertices();
		mesh.clearVertices();
		mesh.clearColors();
		GuiFbos[2].end();

		// phase lfo
		GuiFbos[3].begin();
		ofSetColor(50, 50);
		ofRect(0, 0, _w, _h);
		for (int i = 0; i < _w; i++) {
			float xval = ofMap(i, 0, _w, 0.00, 1.00, true);
			float phase_wave = (colour->ColourGradient::lfo(colour->params.phase_lfo_type, 6.28318*(phase_cycle_speed * xval + 1)));
			mesh.addVertex(ofVec2f(i, H / 2 + H * phase_lfo_amp * phase_wave));
			mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
		}
		mesh.drawVertices();
		mesh.clearVertices();
		mesh.clearColors();
		GuiFbos[3].end();

		// red adsr visual
				GuiFbos[4].begin();
				/*float red_attack = ofMap(sound->s_params.red_Attack, 0, 10000.0, 0, _w);
				float red_decay = ofMap(sound->s_params.red_Decay, 0, 10000.0, 0, _w);
				float red_sustain = ofMap(sound->s_params.red_Sustain, 0, 10000.0, 0, _h);
				float red_release = ofMap(sound->s_params.red_Release, 0, 10000.0, 0, _w);

				ofSetColor(255, 50);
				ofRect(0, 0, _w, _h);
				ofSetColor(255, 0, 0);
				ofLine(0, _h, red_attack, 0);
				ofLine(red_attack, 0, red_attack + red_decay, _h - red_sustain);
				ofLine(red_attack + red_decay, _h - red_sustain, _w - red_release, _h - red_sustain);
				ofLine(_w - red_release, _h - red_sustain, _w, _h);
				*/GuiFbos[4].end();

				// green adsr visual
				GuiFbos[5].begin();
				/*float green_attack = ofMap(sound->s_params.green_Attack, 0, 10000.0, 0, _w);
				float green_decay = ofMap(sound->s_params.green_Decay, 0, 10000.0, 0, _w);
				float green_sustain = ofMap(sound->s_params.green_Sustain, 0, 10000.0, 0, _h);
				float green_release = ofMap(sound->s_params.green_Release, 0, 10000.0, 0, _w);

				ofSetColor(50, 50);
				ofRect(0, 0, _w, _h);
				ofSetColor(0, 255, 0);
				ofLine(0, _h, green_attack, 0);
				ofLine(green_attack, 0, green_attack + green_decay, _h - green_sustain);
				ofLine(green_attack + green_decay, _h - green_sustain, _w - green_release, _h - green_sustain);
				ofLine(_w - green_release, _h - green_sustain, _w, _h);
				*/GuiFbos[5].end();

				// blue adsr visual
				GuiFbos[6].begin();/*
				float blue_attack = ofMap(sound->s_params.blue_Attack, 0, 10000.0, 0, _w);
				float blue_decay = ofMap(sound->s_params.blue_Attack, 0, 10000.0, 0, _w);
				float blue_sustain = ofMap(sound->s_params.blue_Sustain, 0, 10000.0, 0, _h);
				float blue_release = ofMap(sound->s_params.blue_Release, 0, 10000.0, 0, _w);

				ofSetColor(50, 50);
				ofRect(0, 0, _w, _h);
				ofSetColor(0, 0, 255);
				ofLine(0, _h, blue_attack, 0);
				ofLine(blue_attack, 0, blue_attack + blue_decay, _h - blue_sustain);
				ofLine(blue_attack + blue_decay, _h - blue_sustain, _w - blue_release, _h - blue_sustain);
				ofLine(_w - blue_release, _h - blue_sustain, _w, _h); */
				GuiFbos[6].end();
			}
		
		for (int i = 0; i < TestFbos.size(); i++) {
			TestFbos[i].begin();
			ofBackground(50, 50);
			inputs->splash_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("test " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			TestFbos[i].end();
		}
		for (int i = 0; i < inputs->vid->videoThumbs.size(); i++) {
			VideoFbos[i].begin();
			ofBackground(50, 50);
			if (i == activeVid) {
				inputs->video_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			}
			else {
				inputs->video_drawThumbs(i, tileXpos, tileYpos, tileWidth, tileHeight);
			}
			
			//Overpass.drawString("video " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			VideoFbos[i].end();
		}
		for (int i = 0; i < inputs->img->imageThumbs.size(); i++) {
			ImageFbos[i].begin();
			ofBackground(50, 50);
			if (i == activeImg) {
				inputs->image_draw(0, 0, 1920, 1080);
			}
			else {
				inputs->image_drawThumbs(i, tileXpos, tileYpos, tileWidth, tileHeight);
			}
			//Overpass.drawString("image " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			ImageFbos[i].end();
		}
		for (int i = 0; i < inputs->cam->cams.size(); i++) {
			CameraFbos[i].begin();
			ofBackground(50, 50);
			inputs->camera_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("camera " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			CameraFbos[i].end();
		}
		for (int i = 0; i < ShaderFbos.size(); i++) {
			ShaderFbos[i].begin();
			ofBackground(50, 50);
			//inputs->gradient_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("shader " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			ShaderFbos[i].end();
		}
		for (int i = 0; i < SpoutFbos.size(); i++) {
			SpoutFbos[i].begin();
			ofBackground(50, 50);
			//inputs->spout_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("spout " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			SpoutFbos[i].end();
		}
		for (int i = 0; i < NDIFbos.size(); i++) {
			NDIFbos[i].begin();
			ofBackground(50, 50);
			//inputs->NDI_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("ndi " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			NDIFbos[i].end();
		}
	}
	

	/*
	for (int i = 0; i < GuiFbos.size(); i++) {
		GuiFbos[i].begin();
		ofBackground(50, 50);
		Overpass.drawString("GUI elements " + ofToString(i), 50, 50);
		GuiFbos[i].end();
	}*/

	/*
	for (int i = 0; i <= 9; i++) {
		TestFbos[i].draw(i + (100* i), i + (100 * i), 1920, 1080);
		Overpass.drawString(ofToString(TestFbos[i].getId()), i + (100 * i), i + (100 * i));
	}*/
//}

//--------------------------------------------------------------
void GuiColourGradient::lfo_selection(int* type_param) {
	vector<string> types = { "sine","tri","saw","sqr","rnd" };
	ImGui::Columns(types.size());
	for (int i = 0; i < types.size(); i++) {
		ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), type_param, i);
		ImGui::NextColumn();
	}
	ImGui::Columns(1);
	ImGui::Separator();
}
/*
//--------------------------------------------------------------
void GuiColourGradient::lfo_selection_red(int* type_param_red) {
	ImGui::Text("RED WAVE");
	ImGui::SameLine();
	if (ImGui::CollapsingHeader("Red_Wave_Type"))
	{
		vector<string> types = { "sine","tri","saw","sqr","rnd" };
		ImGui::Columns(types.size(), "", false);
		for (int i = 0; i < types.size(); i++) {
			ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), type_param_red, i);
			ImGui::NextColumn();
		}
		ImGui::Columns(1);
		ImGui::Separator();
	}
}

//--------------------------------------------------------------
void GuiColourGradient::lfo_selection_green(int* type_param_green) {
	ImGui::Text("GREEN WAVE");
	ImGui::SameLine();
	if (ImGui::CollapsingHeader("Green_Wave_Type"))
	{
		vector<string> types = { "sine","tri","saw","sqr","rnd" };
		ImGui::Columns(types.size(), "", false);
		for (int i = 0; i < types.size(); i++) {
			ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), type_param_green, i);
			ImGui::NextColumn();
		}
		ImGui::Columns(1);
		ImGui::Separator();
	}
}

//--------------------------------------------------------------
void GuiColourGradient::lfo_selection_blue(int* type_param_blue) {
	ImGui::Text("BLUE WAVE");
	ImGui::SameLine();
	if (ImGui::CollapsingHeader("Blue_Wave_Type"))
	{
		vector<string> types = { "sine","tri","saw","sqr","rnd" };
		ImGui::Columns(types.size(), "", false);
		for (int i = 0; i < types.size(); i++) {
			ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), type_param_blue, i);
			ImGui::NextColumn();
		}
		ImGui::Columns(1);
		ImGui::Separator();
	}
}

//--------------------------------------------------------------
void GuiColourGradient::sound_selection(int* sound_param) {
	vector<string> types = { "OFF", "RED","GREEN","BLUE" };
	ImGui::Columns(types.size());
	for (int i = 0; i < types.size(); i++) {
		ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), sound_param, i);
		ImGui::NextColumn();
	}
	ImGui::Columns(1);
	ImGui::Separator();
}

//--------------------------------------------------------------
void GuiColourGradient::oscillator(int* oscillator_param) {
	vector<string> types = { "sine","tri","saw", "sqr", "noise" };
	ImGui::Columns(types.size());
	for (int i = 0; i < types.size(); i++) {
		ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), oscillator_param, i);
		ImGui::NextColumn();
	}
	ImGui::Columns(1);
	ImGui::Separator();
}
*/
//--------------------------------------------------------------
void GuiColourGradient::Resolutions() {
	static float customWidth = 1920, customHeight = 1080;
	ofVec2f custom = {customWidth, customHeight};
	vector<ofVec2f> resolutions = { custom, {256, 144}, {384, 216}, {512, 218}, {640, 360}, {768, 432}, {1280, 720}, {1920, 1080}, {2560, 1440}, {3840, 2160}, {7680, 4320} };
	const char* resolutions1[] = { "custom", "256 x 144", "384 x 216", "512 X 218", "640 x 360", "768 x 432", "1280 x 720 (720p)", "1920 x 1080 (1080p)", "2560 x 1440 (QHD)", "3840 x 2160 (4k)", "7680 x 4320 (8k)"};
	static int resolutions2 = -1;

	ImGui::Combo("output resolution", &resolutions2, resolutions1, IM_ARRAYSIZE(resolutions1));

	if(resolutions2 == 0) {
		static int i0 = 1920;
		static int i1 = 1080;
		ImGui::InputInt("output_width", &i0);
		ImGui::InputInt("output_height", &i1);
		customWidth = i0;
		customHeight = i1;
	}

	for (int i = 0; i <= resolutions.size(); i++) {
		if (resolutions2 == i) {
			tileWidth = resolutions[i][0];
			tileHeight = resolutions[i][1];
		}
	}
}

//------------------------------------------------
void GuiColourGradient::Navigate() {

	ImGui::SameLine();
	//ypos
//	ImGui::VSliderInt("tileYpos", ImVec2(18, 180), &tileYpos, 2160, -2160);
	//xpos
	static int i2 = 100;

	//	ImGui::SliderInt("tileXpos", &tileXpos, -3840, 3840);
	//	ImGui::SameLine();
	if (ImGui::Button("left")) {
		tileXpos = tileXpos - 10;
	}
	ImGui::SameLine();
	if (ImGui::Button("right")) {
		tileXpos = tileXpos + 10;
	}
	ImGui::NextColumn();
	if (ImGui::Button("up")) {
		tileYpos = tileYpos - 10;
	}
	ImGui::SameLine();
	if (ImGui::Button("down")) {
		tileYpos = tileYpos + 10;
	}

	ImGui::InputInt("Zoom %", &i2);
	tileZoom = i2 * .01;
	tileWidth = tileWidth * tileZoom;
	tileHeight = tileHeight * tileZoom;
}


void GuiColourGradient::InputWindow(int selection) {

	int columns = 3;
	ImGui::Columns(columns);
	ImGui::SetColumnOffset(0, 0);
	ImGui::SetColumnOffset(1, 160);
	ImGui::SetColumnOffset(2, 320);
	
	ImVec4 c2 = ImColor::HSV(1.00f, 0.80f, 0.80f);
	ImVec4 c1 = ImColor::HSV(0.14f, 0.24f, 0.30f);

	if (ImGui::CollapsingHeader(ofxImGui::GetUniqueName(IDs[selection]), true)) {
		for (int j = 0; j <= 9; j++) {
			
			if (select_vect[selection][toggles[selection]] == j) {

				ImGui::PushStyleColor(ImGuiCol_Button, c2);
			}
			else { ImGui::PushStyleColor(ImGuiCol_Button, c1); }
			
			//if input thumbnail is pressed the active output equals the thumbnail number
			if (ImGui::ImageButton(tex_vect[selection][j], ofVec2f(160, 90))) {
				select_vect[selection][toggles[selection]] = j;
				
				//for the video thumbnail trigger the path swapping function
				if (selection == 1) {
					inputs->video_swap(j);
					activeVid = j;
				}
				if (selection == 1) {
					inputs->image_swap(j);
					activeImg = j;
				}
			}
			
			if (select_vect[selection][toggles[selection]] == j) {
				ImGui::PopStyleColor();
			}
			else { ImGui::PopStyleColor(); }
			ImGui::NextColumn();
		}
	}
	ImGui::Columns(1);
}


//--------------------------------------------------------------
void GuiColourGradient::OutputWindow(int selection) {

	static char buf[64], buf1[64], buf2[64], buf3[64], buf4[64], buf5[64], buf6[64] = "";
	
	int mini_width = 320;
	int mini_height = 180;

	if (ImGui::CollapsingHeader(ofxImGui::GetUniqueName(IDs[selection]), false)) {
		ImGui::InputInt(ofxImGui::GetUniqueName("textures"), &add_instances[selection]);
		ImGui::Spacing();


		for (int i = 0; i <= add_instances[selection]; i++) {
			// -------------Toggles
			ImGui::SameLine();
			ImGui::RadioButton(ofxImGui::GetUniqueName(ofToString(i)), &toggles[selection], i);
		
		}

		for (int i = 0; i <= add_instances[selection]; i++) {
			// -------------Toggles
			ImGui::Text(ofxImGui::GetUniqueName(IDs[selection] + ofToString(i)));
			ImGui::SameLine();
			ImGui::RadioButton(ofxImGui::GetUniqueName(ofToString(i)), &toggles[selection], i);
			Resolutions();
			ImGui::Image(tex_vect[selection][select_vect[selection][i]], ofVec2f(mini_width, mini_height));
			Navigate();
			ImGui::InputText("Send_ID" + i, buf, 64, ImGuiInputTextFlags_CharsNoBlank);
			ImGui::SameLine();

			ImGui::Checkbox(ofxImGui::GetUniqueName("spout" + ofToString(i)), &spoutBools[selection][i]);
			ImGui::SameLine();
			ImGui::Checkbox(ofxImGui::GetUniqueName("ndi" + ofToString(i)), &ndiBools[selection][i]);
			
		}
	}


	////else spoutSender.exit();
	//if (&test_spouts == true) SpoutSender0.sendTexture(VideoFbos[selection].getTexture(), buf1);
	//else SpoutSender0.exit();
	//if (&video_spouts == true) SpoutSender1.sendTexture(ImageFbos[selection].getTexture(), buf2);
	//else SpoutSender1.exit();
	//if (&image_spouts == true)	SpoutSender2.sendTexture(CameraFbos[selection].getTexture(), buf3);
	//else SpoutSender2.exit();

	//if (spout4 == true)	spoutSender4.sendTexture(fboGradients.getTexture(), buf4);
	//else spoutSender4.exit();
	//if (spout5 == true) spoutSender5.sendTexture(fboSpouts.getTexture(), buf5);
	//else spoutSender5.exit();
	//if (spout6 == true) spoutSender6.sendTexture(fboNDIs.getTexture(), buf6);
	//else spoutSender6.exit();
	//*/

}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

										GUI
______________________________________________________________________________________
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

bool GuiColourGradient::imGui()
{
	int gui_width = 700;
	auto mainSettings = ofxImGui::Settings();
	ofVec2f pos(640, 140);
	ofVec2f pos4(680, 180);
	ofVec2f pos1(640, 290);
	ofVec2f pos2(1500, 140);
	ofVec2f pos3(25, 140);

	mainSettings.windowPos = pos;

	ImVec4 col = ImColor::HSV(0.14f, 0.24f, 0.42f);
	ImVec4 col1 = ImColor::HSV(0.14f, 0.24f, 0.30f);
	ImGui::PushStyleColor(ImGuiCol_Header, col);
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, col1);
	//ImGui::PushStyleColor(ImGuiCol_Button, col);
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, col1);
	ImGui::PushStyleColor(ImGuiCol_SliderGrab, col);
	ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, col1);
	ImGui::PushStyleColor(ImGuiCol_CheckMark, col);
	ImGui::PushStyleColor(ImGuiCol_TitleBgActive, col1);


	this->gui.begin();

	{

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("INPUT"))
			{
				ImGui::MenuItem("(dummy menu)", NULL, false, false);
				if (ImGui::MenuItem("No_Input")) {
					inputs->params.input_type = 0;
					inputs->selection();
				}
				if (ImGui::MenuItem("Video", "Ctrl+V")) {
					inputs->params.input_type = 1;
					inputs->selection();
				}
				if (ImGui::MenuItem("Image", "Ctrl+I")) {
					inputs->params.input_type = 2;
					inputs->selection();
				}
				if (ImGui::MenuItem("Camera", "Ctrl+C")) {
					inputs->params.input_type = 3;
					inputs->selection();
				}
				if (ImGui::MenuItem("Gradient", "Ctrl+G")) {
					inputs->params.input_type = 4;
					inputs->selection();
				}
				if (ImGui::MenuItem("Spout2", "Ctrl+O")) {
					inputs->params.input_type = 5;
					inputs->selection();
				}
				ImGui::EndMenu();
			}


			if (ImGui::BeginMenu("Outputs"))
			{

				if (ImGui::MenuItem("no_output")) {
					outputs->params.output_type = 0;
					outputs->selection();
				}
				if (ImGui::MenuItem("Spout2")) {
					outputs->params.output_type = 1;
					outputs->selection();
				}
				if (ImGui::MenuItem("NDI")) {
					outputs->params.output_type = 2;
					outputs->selection();
				}
				if (ImGui::BeginMenu("Output Resolution"))
				{
					ImGui::MenuItem("fish_hat.c");
					ImGui::EndMenu();
				}

				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		//TEXTURES



		//WINDOWS---------------------------------------------------------------
		//WINDOWS---------------------------------------------------------------
		//WINDOWS---------------------------------------------------------------


		if (ofxImGui::BeginWindow("OUTPUT_TEXTURES", mainSettings, false)) {
			ImGui::Separator();
			for (int i = 0; i < input_num; i++) {

				OutputWindow(i);
				//spoutToggles();
			}
			ofxImGui::EndWindow(mainSettings);
		}


		if (ofxImGui::BeginWindow("INPUT_TEXTURES", mainSettings, false)) {
			ImGui::Separator();
			for (int i = 0; i < input_num; i++) {
				InputWindow(i);
			}
			ofxImGui::EndWindow(mainSettings);
		}

		if (inputs->params.input_type == 4)
		{/*
			mainSettings.windowPos = pos4;

			//BANDS AND SPEED------------------------------------------------------
			//BANDS AND SPEED------------------------------------------------------
			//BANDS AND SPEED------------------------------------------------------

			if (ofxImGui::BeginWindow("Gradient Generator", mainSettings, true))
			{
				//Overpass.drawString(ImGui::GetWindowPos(), 10, 10);

				ImGui::Text("%.1f FPS (%.3f ms/frame)", ofGetFrameRate(), 1000.0f / ImGui::GetIO().Framerate);

				if (ofxImGui::BeginTree("Master", mainSettings))
				{

					ImGui::SliderFloat("num bands", &colour->params.num_bands, 1, 100);
					ImGui::SliderFloat("animate speed", &colour->params.animate_speed, 0.0, 1.0);

					ofxImGui::EndTree(mainSettings);
				}
				ofxImGui::EndWindow(mainSettings);
			}

			//COLOUR GRADIENT------------------------------------------------------
			//COLOUR GRADIENT------------------------------------------------------
			//COLOUR GRADIENT------------------------------------------------------
			//COLOUR GRADIENT------------------------------------------------------


			mainSettings.windowPos = pos1;

			if (ofxImGui::BeginWindow("Colours", mainSettings, true))
			{
				//Overpass.drawString(ImGui::GetWindowPos(), 10, 20);

				//----COLOURS
				if (ofxImGui::BeginTree("COLOURS", mainSettings))
				{

					//ImGui::Image(TEX_ID getTextureID(), ofVec2f(w, h));

					//ImGui::PlotLines("LFO", , 100);


					//HEADINGS
					ImGui::Columns(5);
					ImGui::Text("");
					ImGui::NextColumn();
					ImGui::Text("DC");
					ImGui::NextColumn();
					ImGui::Text("AMP");
					ImGui::NextColumn();
					ImGui::Text("FREQ");
					ImGui::NextColumn();
					ImGui::Text("PHASE");
					ImGui::Columns(1);
					ImGui::Separator();



					// red wave tyoe
					lfo_selection_red(&colour->params.palette_lfo_red);


					//red paramaters
					ImGui::Columns(5);
					ImGui::Separator();

					if (ImGui::Button("rand_red"))
					{
						colour->params.dc[0] = ofRandom(-1.00, 1.00);
						colour->params.amp[0] = ofRandom(-1.00, 1.00);
						colour->params.freq[0] = ofRandom(0.00, 1.00);
						colour->params.phase[0] = ofRandom(0.00, 1.00);
					}

					ImGui::NextColumn();
					ImGui::SliderFloat("R_dc", &colour->params.dc[0], -1.0, 2.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("R_amp", &colour->params.amp[0], -1.0, 1.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("R_freq", &colour->params.freq[0], 0.0, 10.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("R_phase", &colour->params.phase[0], 0.0, 1.0);
					ImGui::Columns(1);
					ImGui::Separator();


					//green wave type
					lfo_selection_green(&colour->params.palette_lfo_green);


					//green paramaters
					ImGui::Columns(5);
					ImGui::Separator();
					if (ImGui::Button("rand_green"))
					{
						colour->params.dc[1] = ofRandom(0.00, 1.00);
						colour->params.amp[1] = ofRandom(-1.00, 1.00);
						colour->params.freq[1] = ofRandom(0.00, 1.00);
						colour->params.phase[1] = ofRandom(0.00, 1.00);
					}

					ImGui::NextColumn();
					ImGui::SliderFloat("G_dc", &colour->params.dc[1], 0.0, 2.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("G_amp", &colour->params.amp[1], -1.0, 1.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("G_freq", &colour->params.freq[1], 0.0, 10.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("G_phase", &colour->params.phase[1], 0.0, 1.0);
					ImGui::Columns(1);
					ImGui::Separator();


					//blue wave type
					lfo_selection_blue(&colour->params.palette_lfo_blue);

					//blue paramaters
					ImGui::Columns(5);
					ImGui::Separator();

					if (ImGui::Button("rand_blue"))
					{
						colour->params.dc[2] = ofRandom(0.00, 1.00);
						colour->params.amp[2] = ofRandom(-1.00, 1.00);
						colour->params.freq[2] = ofRandom(0.00, 1.00);
						colour->params.phase[2] = ofRandom(0.00, 1.00);
					}
					ImGui::NextColumn();
					ImGui::SliderFloat("B_dc", &colour->params.dc[2], 0.0, 2.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("B_amp", &colour->params.amp[2], -1.0, 1.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("B_freq", &colour->params.freq[2], 0.0, 10.0);
					ImGui::NextColumn();
					ImGui::SliderFloat("B_phase", &colour->params.phase[2], 0.0, 1.0);
					ImGui::Columns(1);
					ImGui::Separator();


					ImGui::Columns(5);
					ImGui::Separator();
					if (ImGui::Button("rand_all"))
					{
						colour->params.dc[0] = ofRandom(0.00, 2.00);
						colour->params.amp[0] = ofRandom(-1.00, 1.00);
						colour->params.freq[0] = ofRandom(0.00, 10.00);
						colour->params.phase[0] = ofRandom(0.00, 1.00);

						colour->params.dc[1] = ofRandom(0.00, 2.00);
						colour->params.amp[1] = ofRandom(-1.00, 1.00);
						colour->params.freq[1] = ofRandom(0.00, 10.00);
						colour->params.phase[1] = ofRandom(0.00, 1.00);

						colour->params.dc[2] = ofRandom(0.00, 2.00);
						colour->params.amp[2] = ofRandom(-1.00, 1.00);
						colour->params.freq[2] = ofRandom(0.00, 10.00);
						colour->params.phase[2] = ofRandom(0.00, 1.00);
					}
					ImGui::NextColumn();
					if (ImGui::Button("rand_dc"))
					{
						colour->params.dc[0] = ofRandom(0.00, 2.00);
						colour->params.dc[1] = ofRandom(0.00, 2.00);
						colour->params.dc[2] = ofRandom(0.00, 2.00);
					}
					ImGui::NextColumn();
					if (ImGui::Button("rand_amp"))
					{
						colour->params.amp[0] = ofRandom(-1.00, 1.00);
						colour->params.amp[1] = ofRandom(-1.00, 1.00);
						colour->params.amp[2] = ofRandom(-1.00, 1.00);
					}
					ImGui::NextColumn();
					if (ImGui::Button("rand_freq"))
					{
						colour->params.freq[0] = ofRandom(0.00, 10.00);
						colour->params.freq[1] = ofRandom(0.00, 10.00);
						colour->params.freq[2] = ofRandom(0.00, 10.00);
					}
					ImGui::NextColumn();
					if (ImGui::Button("rand_phase"))
					{
						colour->params.phase[0] = ofRandom(0.00, 1.00);
						colour->params.phase[1] = ofRandom(0.00, 1.00);
						colour->params.phase[2] = ofRandom(0.00, 1.00);
					}
					ImGui::Columns(1);
					ImGui::Separator();

					ofxImGui::EndTree(mainSettings);
				}
				ofxImGui::EndWindow(mainSettings);
			}


			//LFOS------------------------------------------------------
			//LFOS------------------------------------------------------
			//LFOS------------------------------------------------------
			//LFOS------------------------------------------------------


			mainSettings.windowPos = pos2;
			if (ofxImGui::BeginWindow("LFOS", mainSettings, true))
			{
				//Overpass.drawString(ImGui::GetWindowPos(), 10, 30);

				//----ALL
				if (ofxImGui::BeginTree("LFOs", mainSettings)) {

					//	ImGui::Image(TEX_ID1 getTextureID1(), ofVec2f(w / 3, h / 2));

						//----FREQ LFO
					if (ofxImGui::BeginTree("FREQ LFO", mainSettings)) {
						lfo_selection(&colour->params.freq_lfo_type);
						ImGui::SliderFloat("amp", &colour->params.freq_lfo_amp, 0.0, 1.0);
						ImGui::SliderFloat("speed", &colour->params.freq_lfo_speed, 0.0, 1.0);
						ImGui::SliderFloat("freq", &colour->params.freq_cycle_speed, 0.0, 10.0);
						ofxImGui::EndTree(mainSettings);
					}

					//	ImGui::Image(TEX_ID2 getTextureID2(), ofVec2f(w / 3, h / 2));

						//----AMP LFO
					if (ofxImGui::BeginTree("AMP LFO", mainSettings)) {
						lfo_selection(&colour->params.amp_lfo_type);
						ImGui::SliderFloat("amp", &colour->params.amp_lfo_amp, 0.0, 1.0);
						ImGui::SliderFloat("speed", &colour->params.amp_lfo_speed, 0.0, 1.0);
						ImGui::SliderFloat("freq", &colour->params.amp_cycle_speed, 0.0, 10.0);
						ofxImGui::EndTree(mainSettings);
					}

					//		ImGui::Image(TEX_ID3 getTextureID3(), ofVec2f(w / 3, h / 2));

							//----PHASE LFO
					if (ofxImGui::BeginTree("PHASE LFO", mainSettings)) {
						lfo_selection(&colour->params.phase_lfo_type);
						ImGui::SliderFloat("amp", &colour->params.phase_lfo_amp, 0.0, 1.0);
						ImGui::SliderFloat("speed", &colour->params.phase_lfo_speed, 0.0, 1.0);
						ImGui::SliderFloat("freq", &colour->params.phase_cycle_speed, 0.0, 10.0);
						ofxImGui::EndTree(mainSettings);
					}
					ofxImGui::EndTree(mainSettings);

				}
				ofxImGui::EndWindow(mainSettings);

			}

			//SYNTHS------------------------------------------------------
			//SYNTHS------------------------------------------------------
			//SYNTHS------------------------------------------------------
			//SYNTHS------------------------------------------------------

			mainSettings.windowPos = pos3;
			if (ofxImGui::BeginWindow("sound", mainSettings, true))
			{

				//Overpass.drawString(ImGui::GetWindowPos(), 10, 40);

				ImGui::TextWrapped("PICK YOUR OSCILLATOR... HIT ANY KEY FOR TONE... USE COLOUR CONTROLS AND LFOS FOR FURTHER MODULATION... ENJOY");
				sound_selection(&sound->s_params.sound_colour);

				//----RED SYNTH

				if (ofxImGui::BeginTree("RED_SYNTH", mainSettings)) {

					ImGui::Columns(2);
					ImGui::Text("RED ADSR");
					ImGui::SliderFloat("Attack", &sound->s_params.red_Attack, 0.0, 10000.0);
					ImGui::SliderFloat("Decay", &sound->s_params.red_Decay, 0.0, 10000.0);
					ImGui::SliderFloat("Sustain", &sound->s_params.red_Sustain, 0.0, 10000.0);
					ImGui::SliderFloat("Release", &sound->s_params.red_Release, 0.0, 10000.0);
					ImGui::NextColumn();
					//	ImGui::Image(TEX_ID4 getTextureID4(), ofVec2f(w / 3, h / 2));
					ImGui::Columns(1);
					oscillator(&sound->s_params.oscillator_type_red);
					ImGui::Text("FREQUENCY MODULATION");
					ImGui::SliderFloat("Freq", &sound->s_params.frequency_red, 0.10, 500);
					ImGui::Columns(3);
					ImGui::SliderFloat("Freq_Mod_Min", &sound->s_params.modFreq_min_red, 0.0, 500);
					ImGui::NextColumn();
					ImGui::SliderFloat("Freq_Mod_Max", &sound->s_params.modFreq_max_red, 0.0, 500);
					ImGui::Columns(1);
					ImGui::SliderFloat("Mod_Index", &sound->s_params.modIndex_red, 0.0, 500);
					ofxImGui::EndTree(mainSettings);

				}


				//----GREEN SYNTH

				if (ofxImGui::BeginTree("GREEN_SYNTH", mainSettings)) {
					ImGui::Columns(2);
					ImGui::Text("GREEN ADSR");
					ImGui::SliderFloat("Attack", &sound->s_params.green_Attack, 0.0, 10000.0);
					ImGui::SliderFloat("Decay", &sound->s_params.green_Decay, 0.0, 10000.0);
					ImGui::SliderFloat("Sustain", &sound->s_params.green_Sustain, 0.0, 10000.0);
					ImGui::SliderFloat("Release", &sound->s_params.green_Release, 0.0, 10000.0);
					ImGui::NextColumn();
					//	ImGui::Image(TEX_ID5 getTextureID5(), ofVec2f(w / 3, h / 2));
					ImGui::Columns(1);
					oscillator(&sound->s_params.oscillator_type_green);
					ImGui::Text("FREQUENCY MODULATION");
					ImGui::SliderFloat("Freq", &sound->s_params.frequency_green, 0.10, 500);
					ImGui::Columns(3);
					ImGui::SliderFloat("Freq_Mod_Min", &sound->s_params.modFreq_min_green, 0.0, 500);
					ImGui::NextColumn();
					ImGui::SliderFloat("Freq_Mod_Max", &sound->s_params.modFreq_max_green, 0.0, 500);
					ImGui::Columns(1);
					ImGui::SliderFloat("Mod_Index", &sound->s_params.modIndex_green, 0.0, 500);

					ofxImGui::EndTree(mainSettings);
				}

				//----BLUE SYNTH


				if (ofxImGui::BeginTree("BLUE_SYNTH", mainSettings)) {
					ImGui::Columns(2);
					ImGui::Text("BLUE ADSR");
					ImGui::SliderFloat("Attack", &sound->s_params.blue_Attack, 0.0, 10000.0);
					ImGui::SliderFloat("Decay", &sound->s_params.blue_Decay, 0.0, 10000.0);
					ImGui::SliderFloat("Sustain", &sound->s_params.blue_Sustain, 0.0, 10000.0);
					ImGui::SliderFloat("Release", &sound->s_params.blue_Release, 0.0, 10000.0);
					ImGui::NextColumn();
					//	ImGui::Image(TEX_ID6 getTextureID6(), ofVec2f(w / 3, h / 2));
					ImGui::Columns(1);
					oscillator(&sound->s_params.oscillator_type_blue);
					ImGui::Text("FREQUENCY MODULATION");
					ImGui::SliderFloat("Freq", &sound->s_params.frequency_blue, 0.10, 500);
					ImGui::Columns(3);
					ImGui::SliderFloat("Freq_Mod_Min", &sound->s_params.modFreq_min_blue, 0.0, 500);
					ImGui::NextColumn();
					ImGui::SliderFloat("Freq_Mod_Max", &sound->s_params.modFreq_max_blue, 0.0, 500);
					ImGui::Columns(1);
					ImGui::SliderFloat("Mod_Index", &sound->s_params.modIndex_blue, 0.0, 500);
					ofxImGui::EndTree(mainSettings);
				}
				ofxImGui::EndWindow(mainSettings);
			}
		*/}

		this->gui.end();
		return mainSettings.mouseOverGui;
	}

}