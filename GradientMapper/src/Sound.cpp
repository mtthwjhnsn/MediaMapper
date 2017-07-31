//---------------
//----Sound.cpp
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#include "Sound.h"

#include "ofMain.h"

void Sound::setup() {
	s_params.red_Attack = 2000;
	s_params.red_Decay = 1;
	s_params.red_Sustain = 1;
	s_params.red_Release = 3000;
	s_params.frequency_red = 150;
	s_params.modFreq_max_red = 150;
	s_params.modFreq_min_red = 0;
	s_params.modIndex_red = 150;

	s_params.green_Attack = 2000;
	s_params.green_Decay = 1;
	s_params.green_Sustain = 1;
	s_params.green_Release = 3000;
	s_params.frequency_green = 150;
	s_params.modFreq_max_green = 150;
	s_params.modFreq_min_green = 0;
	s_params.modIndex_green = 150;

	s_params.blue_Attack = 2000;
	s_params.blue_Decay = 1;
	s_params.blue_Sustain = 1;
	s_params.blue_Release = 3000;
	s_params.frequency_blue = 150;
	s_params.modFreq_max_blue = 150;
	s_params.modFreq_min_blue = 0;
	s_params.modIndex_blue = 150;
}


void Sound::draw() {

}

