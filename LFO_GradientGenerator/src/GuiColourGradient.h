//
//  GuiColourGradient.hpp
//  Kortex_Laser_Jen
//
//  Created by Joshua Batty on 4/4/17.
//
//

#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ColourGradient.h"


class GuiColourGradient {
public:
	void setup(ColourGradient *_colour);
	void draw();

	void lfo_selection(int* type_param);
	void lfo_selection_red(int* type_param_red);
	void lfo_selection_green(int* type_param_green);
	void lfo_selection_blue(int* type_param_blue);

private:
	ColourGradient *colour;


	// Gui
	bool imGui();

	ofxImGui::Gui gui;
	bool guiVisible;
	bool mouseOverGui;
};
