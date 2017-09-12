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

#include "GuiColourGradient.h"
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

int w = 800;
int h = 180;

//-------------------------------------------------
void GuiColourGradient::setup(ColourGradient *_colour, Sound *_sound, input_selector *_inputs, output_selector *_outputs) {

	tileXpos = 0;
	tileYpos = 0;
	tileWidth = 640;
	tileHeight = 480;
	zoom = 1.00;

	gui.setup();
	guiVisible = true;
	
	colour = _colour;
	sound = _sound;
	inputs = _inputs;
	outputs = _outputs;

	ofFbo::Settings fboSettings;
	fboSettings.width = w;
	fboSettings.height = h;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;
	
	fbo.allocate(fboSettings);
	
	fboSettings.width = w/3;
	fboSettings.height = h/2;

	fbo1.allocate(fboSettings);
	fbo2.allocate(fboSettings);
	fbo3.allocate(fboSettings);

	fbo4.allocate(fboSettings);
	fbo5.allocate(fboSettings);
	fbo6.allocate(fboSettings);

	fboSettings.width = tileWidth;
	fboSettings.height = tileHeight;
	fbo7.allocate(fboSettings);
	
	textureid = fbo.getTexture().texData.textureID;
	textureid1 = fbo.getTexture().texData.textureID;
	textureid2 = fbo2.getTexture().texData.textureID;
	textureid3 = fbo3.getTexture().texData.textureID;
	textureid4 = fbo4.getTexture().texData.textureID;
	textureid5 = fbo5.getTexture().texData.textureID;
	textureid6 = fbo6.getTexture().texData.textureID;
	textureid7 = fbo7.getTexture().texData.textureID;

	fbo.begin();
	ofClear(255, 255, 255, 0);
	fbo.end();

	fbo1.begin();
	ofClear(255, 255, 255, 0);
	fbo1.end();
	
	fbo2.begin();
	ofClear(255, 255, 255, 0);
	fbo2.end();
	
	fbo3.begin();
	ofClear(255, 255, 255, 0);
	fbo3.end();
	
	fbo4.begin();
	ofClear(255, 255, 255, 0);
	fbo4.end();

	fbo5.begin();
	ofClear(255, 255, 255, 0);
	fbo5.end();

	fbo6.begin();
	ofClear(255, 255, 255, 0);
	fbo6.end();

	fbo7.begin();
	ofClear(255, 255, 255, 0);
	fbo7.end();

	//mesh
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(1);
}


GLuint GuiColourGradient::getTextureID() {
	return textureid;
}

GLuint GuiColourGradient::getTextureID1() {
	return textureid1;
}

GLuint GuiColourGradient::getTextureID2() {
	return textureid2;
}

GLuint GuiColourGradient::getTextureID3() {
	return textureid3;
}
GLuint GuiColourGradient::getTextureID4() {
	return textureid4;
}

GLuint GuiColourGradient::getTextureID5() {
	return textureid5;
}

GLuint GuiColourGradient::getTextureID6() {
	return textureid6;
}

GLuint GuiColourGradient::getTextureID7() {
	return textureid7;
}

//-------------------------------------------------
void GuiColourGradient::draw(ofFbo fboinput) {


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
		fbo.begin();

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
		fbo.end();

		int _w = w / 3;
		int _h = h / 2;
		int _H = _h * .5;

		//frequency lfo
		fbo1.begin();
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
		fbo1.end();

		// amp lfo
		fbo2.begin();
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
		fbo2.end();

		// phase lfo
		fbo3.begin();
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
		fbo3.end();

		// red adsr visual
		fbo4.begin();
		float red_attack = ofMap(sound->s_params.red_Attack, 0, 10000.0, 0, _w);
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
		fbo4.end();

		// green adsr visual
		fbo5.begin();
		float green_attack = ofMap(sound->s_params.green_Attack, 0, 10000.0, 0, _w);
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
		fbo5.end();

		// blue adsr visual
		fbo6.begin();
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
		ofLine(_w - blue_release, _h - blue_sustain, _w, _h);
		fbo6.end();
	}
	/*ofFbo::Settings fboSettings;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;

	fboSettings.width = tileWidth;
	fboSettings.height = tileHeight;
	fbo7.allocate(fboSettings);
	*/
	fbo7.begin();
	ofBackground(50, 50);
	fboinput.draw(tileXpos, tileYpos, tileWidth, tileHeight);
	fbo7.end();

}

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
vector<string> types = { "sine","tri","saw", "sqr", "noise"};
ImGui::Columns(types.size());
for (int i = 0; i < types.size(); i++) {
	ImGui::RadioButton(ofxImGui::GetUniqueName(types[i]), oscillator_param, i);
	ImGui::NextColumn();
}
ImGui::Columns(1);
ImGui::Separator();
}

#define TEX_ID (ImTextureID)(uintptr_t)
#define TEX_ID1 (ImTextureID)(uintptr_t)
#define TEX_ID2 (ImTextureID)(uintptr_t)
#define TEX_ID3 (ImTextureID)(uintptr_t)
#define TEX_ID4 (ImTextureID)(uintptr_t)
#define TEX_ID5 (ImTextureID)(uintptr_t)
#define TEX_ID6 (ImTextureID)(uintptr_t)
#define TEX_ID7 (ImTextureID)(uintptr_t)


//#define TEX_ID8 (ImTextureID)(uintptr_t)
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

				if (ImGui::BeginMenu("Open Recent"))
				{
					ImGui::MenuItem("fish_hat.c");
					ImGui::MenuItem("fish_hat.inl");
					ImGui::MenuItem("fish_hat.h");
					if (ImGui::BeginMenu("More.."))
					{
						ImGui::MenuItem("Hello");
						ImGui::MenuItem("Sailor");
						if (ImGui::BeginMenu("Recurse.."))
						{
							//ShowExampleMenuFile();
							ImGui::EndMenu();
						}
						ImGui::EndMenu();
					}
					ImGui::EndMenu();
				}
				if (ImGui::MenuItem("Save", "Ctrl+S")) {}
				if (ImGui::MenuItem("Save As..")) {}
				ImGui::Separator();
				if (ImGui::BeginMenu("Options"))
				{
					static bool enabled = true;
					ImGui::MenuItem("Enabled", "", &enabled);
					ImGui::BeginChild("child", ImVec2(0, 60), true);
					for (int i = 0; i < 10; i++)
						ImGui::Text("Scrolling Text %d", i);
					ImGui::EndChild();
					static float f = 0.5f;
					static int n = 0;
					ImGui::SliderFloat("Value", &f, 0.0f, 1.0f);
					ImGui::InputFloat("Input", &f, 0.1f);
					ImGui::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Colors"))
				{
					for (int i = 0; i < ImGuiCol_COUNT; i++)
						ImGui::MenuItem(ImGui::GetStyleColName((ImGuiCol)i));
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Disabled", false)) // Disabled
				{
					IM_ASSERT(0);
				}
				if (ImGui::MenuItem("Checked", NULL, true)) {}
				if (ImGui::MenuItem("Quit", "Alt+F4")) {}
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
					ImGui::MenuItem("fish_hat.inl");
					ImGui::MenuItem("fish_hat.h");
					if (ImGui::BeginMenu("More.."))
					{
						ImGui::MenuItem("Hello");
						ImGui::MenuItem("Sailor");
						if (ImGui::BeginMenu("Recurse.."))
						{
							//ShowExampleMenuFile();
							ImGui::EndMenu();
						}
						ImGui::EndMenu();
					}
					ImGui::EndMenu();
				}

				if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
				if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
				ImGui::Separator();
				if (ImGui::MenuItem("Cut", "CTRL+X")) {}
				if (ImGui::MenuItem("Copy", "CTRL+C")) {}
				if (ImGui::MenuItem("Paste", "CTRL+V")) {}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

		if (inputs->params.input_type == 0 || inputs->params.input_type == 1 || inputs->params.input_type == 2 || inputs->params.input_type == 3 || inputs->params.input_type == 4 || inputs->params.input_type == 5) {

			if (ofxImGui::BeginWindow("Input", mainSettings, false)) {
				//zoom
				if (ImGui::Button("-zoom")) {
					tileWidth = tileWidth - 100;
					tileHeight = tileHeight - 100;
				}
				ImGui::SameLine();
				if (ImGui::Button("+zoom")) {
					tileWidth = tileWidth + 100;
					tileHeight = tileHeight + 100;
				}
				//ImGui::ImageButton(TEX_ID7 getTextureID7(), ofVec2f(640, 360));
				ImGui::Image(TEX_ID7 getTextureID7(), ofVec2f(640, 360));
				ImGui::SameLine();
				//ypos
				ImGui::VSliderInt("tileYpos", ImVec2(18, 360), &tileYpos, 2160, 0);
				//xpos
				ImGui::Columns(2);
				if (ImGui::Button("left")) {
					tileXpos = tileXpos - 10;
				}            ImGui::SameLine();
				ImGui::SliderInt("tileXpos", &tileXpos, 0, 3840);
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
				ImGui::SameLine();
				ofxImGui::EndWindow(mainSettings);
				
			}
		}
		
		if (inputs->params.input_type == 4)
		
		{



			mainSettings.windowPos = pos4;

			//BANDS AND SPEED------------------------------------------------------
			//BANDS AND SPEED------------------------------------------------------
			//BANDS AND SPEED------------------------------------------------------


			if (ofxImGui::BeginWindow("Gradient Generator", mainSettings, false))
			{
				//ofDrawBitmapString(ImGui::GetWindowPos(), 10, 10);

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

			if (ofxImGui::BeginWindow("Colours", mainSettings, false))
			{
				//ofDrawBitmapString(ImGui::GetWindowPos(), 10, 20);

				//----COLOURS
				if (ofxImGui::BeginTree("COLOURS", mainSettings))
				{

					ImGui::ImageButton(TEX_ID getTextureID(), ofVec2f(w, h));

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
			if (ofxImGui::BeginWindow("LFOS", mainSettings, false))
			{
				//ofDrawBitmapString(ImGui::GetWindowPos(), 10, 30);

				//----ALL
				if (ofxImGui::BeginTree("LFOs", mainSettings)) {

					ImGui::ImageButton(TEX_ID1 getTextureID1(), ofVec2f(w / 3, h / 2));

					//----FREQ LFO
					if (ofxImGui::BeginTree("FREQ LFO", mainSettings)) {
						lfo_selection(&colour->params.freq_lfo_type);
						ImGui::SliderFloat("amp", &colour->params.freq_lfo_amp, 0.0, 1.0);
						ImGui::SliderFloat("speed", &colour->params.freq_lfo_speed, 0.0, 1.0);
						ImGui::SliderFloat("freq", &colour->params.freq_cycle_speed, 0.0, 10.0);
						ofxImGui::EndTree(mainSettings);
					}

					ImGui::ImageButton(TEX_ID2 getTextureID2(), ofVec2f(w / 3, h / 2));

					//----AMP LFO
					if (ofxImGui::BeginTree("AMP LFO", mainSettings)) {
						lfo_selection(&colour->params.amp_lfo_type);
						ImGui::SliderFloat("amp", &colour->params.amp_lfo_amp, 0.0, 1.0);
						ImGui::SliderFloat("speed", &colour->params.amp_lfo_speed, 0.0, 1.0);
						ImGui::SliderFloat("freq", &colour->params.amp_cycle_speed, 0.0, 10.0);
						ofxImGui::EndTree(mainSettings);
					}

					ImGui::ImageButton(TEX_ID3 getTextureID3(), ofVec2f(w / 3, h / 2));

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
			if (ofxImGui::BeginWindow("sound", mainSettings, false))
			{

				//ofDrawBitmapString(ImGui::GetWindowPos(), 10, 40);

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
					ImGui::ImageButton(TEX_ID4 getTextureID4(), ofVec2f(w / 3, h / 2));
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
					ImGui::ImageButton(TEX_ID5 getTextureID5(), ofVec2f(w / 3, h / 2));
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
					ImGui::ImageButton(TEX_ID6 getTextureID6(), ofVec2f(w / 3, h / 2));
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
		}

		this->gui.end();
		return mainSettings.mouseOverGui;



	}



}




