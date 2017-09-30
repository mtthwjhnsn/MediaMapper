//---------------
//----Sound.h---
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#pragma once
#include "ofMain.h"

struct SoundParams {

	float red_Attack;
	float red_Decay;
	float red_Sustain;
	float red_Release;
	float frequency_red;
	float modFreq_max_red;
	float modFreq_min_red;
	float modIndex_red;
	
	float green_Attack;
	float green_Decay;
	float green_Sustain;
	float green_Release;
	float frequency_green;
	float modFreq_max_green;
	float modFreq_min_green;
	float modIndex_green;

	float blue_Attack;
	float blue_Decay;
	float blue_Sustain;
	float blue_Release;
	float frequency_blue;
	float modFreq_max_blue;
	float modFreq_min_blue;
	float modIndex_blue;

	int sound_colour;
	int oscillator_type_red;
	int oscillator_type_green;
	int oscillator_type_blue;

};


class Sound
{
public:

	SoundParams s_params;
	void setup();
	void draw();

	

};

