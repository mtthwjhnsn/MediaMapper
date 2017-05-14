//
//  GuiColourGradient.cpp
//  Kortex_Laser_Jen
//
//  Created by Joshua Batty on 4/4/17.
//
//

#include "GuiColourGradient.h"

//-------------------------------------------------
void GuiColourGradient::setup(ColourGradient *_colour) {
	colour = _colour;

	gui.setup();
	guiVisible = true;
}

//-------------------------------------------------
void GuiColourGradient::draw() {
	if (guiVisible) {
		imGui();
	}
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
}

//--------------------------------------------------------------
bool GuiColourGradient::imGui()
{
	int gui_width = 350;
	auto mainSettings = ofxImGui::Settings();
	mainSettings.windowPos = ofVec2f(ofGetWidth() - gui_width, 10);

	this->gui.begin();
	{
		if (ofxImGui::BeginWindow("Gradient Generator", mainSettings, false))
		{
			ImGui::Text("%.1f FPS (%.3f ms/frame)", ofGetFrameRate(), 1000.0f / ImGui::GetIO().Framerate);

			if (ofxImGui::BeginTree("Master", mainSettings))
			{
				lfo_selection(&colour->params.palette_lfo_type);
				ImGui::SliderFloat("num bands", &colour->params.num_bands, 1, 100);
				ImGui::SliderFloat("animate speed", &colour->params.animate_speed, 0.0, 1.0);
				ofxImGui::EndTree(mainSettings);
			}
			//----RED
			if (ofxImGui::BeginTree("RED", mainSettings)) {
				ImGui::SliderFloat("dc", &colour->params.dc[0], 0.0, 1.0);
				ImGui::SliderFloat("amp", &colour->params.amp[0], 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.freq[0], 0.0, 1.0);
				ImGui::SliderFloat("phase", &colour->params.phase[0], 0.0, 1.0);

				ofxImGui::EndTree(mainSettings);
			}
			//----GREEN
			if (ofxImGui::BeginTree("GREEN", mainSettings)) {
				ImGui::SliderFloat("dc", &colour->params.dc[1], 0.0, 1.0);
				ImGui::SliderFloat("amp", &colour->params.amp[1], 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.freq[1], 0.0, 1.0);
				ImGui::SliderFloat("phase", &colour->params.phase[1], 0.0, 1.0);
				ImGui::Button("rand_green");
				ofxImGui::EndTree(mainSettings);
			}
			//----BLUE
			if (ofxImGui::BeginTree("BLUE", mainSettings)) {
				ImGui::SliderFloat("dc", &colour->params.dc[2], 0.0, 1.0);
				ImGui::SliderFloat("amp", &colour->params.amp[2], 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.freq[2], 0.0, 1.0);
				ImGui::SliderFloat("phase", &colour->params.phase[2], 0.0, 1.0);
				ImGui::Button("rand_blue");
				ofxImGui::EndTree(mainSettings);
			}
			//----ALL
			if (ofxImGui::BeginTree("ALL", mainSettings)) {
				
				if (ImGui::Button("rand_red"))
				{
					colour->params.dc[0] = ofRandom(-1.00, 1.00);
					colour->params.amp[0] = ofRandom(-1.00, 1.00);
					colour->params.freq[0] = ofRandom(-1.00, 1.00);
					colour->params.phase[0] = ofRandom(-1.00, 1.00);
				}

				if (ImGui::Button("rand_green"))
				{
					colour->params.dc[1] = ofRandom(-1.00, 1.00);
					colour->params.amp[1] = ofRandom(-1.00, 1.00);
					colour->params.freq[1] = ofRandom(-1.00, 1.00);
					colour->params.phase[1] = ofRandom(-1.00, 1.00);
				}

				if (ImGui::Button("rand_blue"))
				{
					colour->params.dc[2] = ofRandom(-1.00, 1.00);
					colour->params.amp[2] = ofRandom(-1.00, 1.00);
					colour->params.freq[2] = ofRandom(-1.00, 1.00);
					colour->params.phase[2] = ofRandom(-1.00, 1.00);
				}

				if (ImGui::Button("rand_all"))
				{
					colour->params.dc[0] = ofRandom(-1.00, 1.00);
					colour->params.amp[0] = ofRandom(-1.00, 1.00);
					colour->params.freq[0] = ofRandom(-1.00, 1.00);
					colour->params.phase[0] = ofRandom(-1.00, 1.00);
					
					colour->params.dc[1] = ofRandom(-1.00, 1.00);
					colour->params.amp[1] = ofRandom(-1.00, 1.00);
					colour->params.freq[1] = ofRandom(-1.00, 1.00);
					colour->params.phase[1] = ofRandom(-1.00, 1.00);

					colour->params.dc[2] = ofRandom(-1.00, 1.00);
					colour->params.amp[2] = ofRandom(-1.00, 1.00);
					colour->params.freq[2] = ofRandom(-1.00, 1.00);
					colour->params.phase[2] = ofRandom(-1.00, 1.00);
				}

				if (ImGui::Button("rand_dc"))
				{
					colour->params.dc[0] = ofRandom(-1.00, 1.00);
					colour->params.dc[1] = ofRandom(-1.00, 1.00);
					colour->params.dc[2] = ofRandom(-1.00, 1.00);
				}

				if (ImGui::Button("rand_amp"))
				{\
					colour->params.amp[0] = ofRandom(-1.00, 1.00);
					colour->params.amp[1] = ofRandom(-1.00, 1.00);
					colour->params.amp[2] = ofRandom(-1.00, 1.00);
					}

				if (ImGui::Button("rand_freq"))
				{	colour->params.freq[0] = ofRandom(-1.00, 1.00);
					colour->params.freq[1] = ofRandom(-1.00, 1.00);
					colour->params.freq[2] = ofRandom(-1.00, 1.00);
									}
				if (ImGui::Button("rand_phase"))
				{
					colour->params.phase[0] = ofRandom(-1.00, 1.00);
					colour->params.phase[1] = ofRandom(-1.00, 1.00);
					colour->params.phase[2] = ofRandom(-1.00, 1.00);
				}

				ofxImGui::EndTree(mainSettings);


			}
			//----FREQ LFO
			if (ofxImGui::BeginTree("FREQ LFO", mainSettings)) {
				lfo_selection(&colour->params.freq_lfo_type);
				ImGui::SliderFloat("amp", &colour->params.freq_lfo_amp, 0.0, 1.0);
				ImGui::SliderFloat("speed", &colour->params.freq_lfo_speed, 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.freq_cycle_speed, 0.0, 1.0);
				ofxImGui::EndTree(mainSettings);
			}
			//----AMP LFO
			if (ofxImGui::BeginTree("AMP LFO", mainSettings)) {
				lfo_selection(&colour->params.amp_lfo_type);
				ImGui::SliderFloat("amp", &colour->params.amp_lfo_amp, 0.0, 1.0);
				ImGui::SliderFloat("speed", &colour->params.amp_lfo_speed, 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.amp_cycle_speed, 0.0, 1.0);
				ofxImGui::EndTree(mainSettings);
			}
			//----PHASE LFO
			if (ofxImGui::BeginTree("PHASE LFO", mainSettings)) {
				lfo_selection(&colour->params.phase_lfo_type);
				ImGui::SliderFloat("amp", &colour->params.phase_lfo_amp, 0.0, 1.0);
				ImGui::SliderFloat("speed", &colour->params.phase_lfo_speed, 0.0, 1.0);
				ImGui::SliderFloat("freq", &colour->params.phase_cycle_speed, 0.0, 1.0);
				ofxImGui::EndTree(mainSettings);
			}

		}
		ofxImGui::EndWindow(mainSettings);
	}
	this->gui.end();
	return mainSettings.mouseOverGui;
}


