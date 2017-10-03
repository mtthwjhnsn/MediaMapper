
//---------------
//----ofApp.cpp
//---------------
//--- MATTHEWJOHNSON
//--- COLOUR GRADIENT AND SYNTH
//---------------
//---- 9/06/17
//---------------
//---------------

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	background.load("vhs.png");

	int w = ofGetWidth();
	int h = ofGetHeight();

	sampleRate = 44100;
	bufferSize = 512;
	ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);

	colour.setup(gui.tileWidth, gui.tileHeight);
	sound.setup();
	
	input.setup(&image);
	gui.setup(&colour, &sound, &input, &outs);
	outs.setup();
	
	ofFbo::Settings fboSettings;
	fboSettings.width = 1920;
	fboSettings.height = 1080;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;

	fbo.allocate(fboSettings);

	fbo.begin();
	ofClear(255, 255, 255, 0);
	fbo.end();

	fbo1.begin();
	ofClear(255, 255, 255, 0);
	fbo1.end();
}

/*
void ofApp::coloursetup() {
	if (input.params.setup == true) {
		colour.setup(1920, 1080);
		input.params.setup = false;
	}
}
*/

void ofApp::colourfbo() {
	fbo1.begin();
	colour.draw();
	fbo1.end();
}

void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	fbo.begin();
	//coloursetup();
	colourfbo();
	//input.draw(fbo1, gui.tileXpos, gui.tileYpos, gui.tileWidth, gui.tileHeight);

	fbo.end();
}


void ofApp::OutputController() {
}

void ofApp::output() {
	outs.draw(fbo);
	gui.draw(fbo);
}

//--------------------------------------------------------------
void ofApp::draw() {
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
	update();
	output();
	//fbo.draw(0, ofGetHeight()*.25, ofGetWidth()*.5, ofGetHeight()*.5);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (sound.s_params.sound_colour == 0) {
		env_red.trigger = 0;
		env_green.trigger = 0;
		env_blue.trigger = 0;
	}
	if (sound.s_params.sound_colour == 1) {
		env_red.trigger = 1;
		env_green.trigger = 0;
		env_blue.trigger = 0;
	}
	else if (sound.s_params.sound_colour == 2) {
		env_green.trigger = 1;
		env_red.trigger = 0;
		env_blue.trigger = 0;
	}
	else if (sound.s_params.sound_colour == 3) {
		env_blue.trigger = 1;
		env_red.trigger = 0;
		env_green.trigger = 0;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
		env_red.trigger = 0;
		env_green.trigger = 0;
		env_blue.trigger = 0;
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
	
	env_red.setAttack(sound.s_params.red_Attack);
	env_red.setDecay(sound.s_params.red_Decay);
	env_red.setSustain(sound.s_params.red_Sustain);
	env_red.setRelease(sound.s_params.red_Release);

	env_green.setAttack(sound.s_params.green_Attack);
	env_green.setDecay(sound.s_params.green_Decay);
	env_green.setSustain(sound.s_params.green_Sustain);
	env_green.setRelease(sound.s_params.green_Release);

	env_blue.setAttack(sound.s_params.blue_Attack);
	env_blue.setDecay(sound.s_params.blue_Decay);
	env_blue.setSustain(sound.s_params.blue_Sustain);
	env_blue.setRelease(sound.s_params.blue_Release);

	
	frequency_red = sound.s_params.frequency_red;
	modulationFrequency_red = ofMap(colour.get_colour(0)[0], 0, 255, sound.s_params.modFreq_min_red, sound.s_params.modFreq_max_red);
	modulationIndex_red = sound.s_params.modIndex_red;

	frequency_green = sound.s_params.frequency_green;
	modulationFrequency_green = ofMap(colour.get_colour(1)[1], 0, 255, sound.s_params.modFreq_min_green, sound.s_params.modFreq_max_green);
	modulationIndex_green = sound.s_params.modIndex_green;

	frequency_blue = sound.s_params.frequency_blue;
	modulationFrequency_blue = ofMap(colour.get_colour(2)[2], 0, 255, sound.s_params.modFreq_min_blue, sound.s_params.modFreq_max_blue);
	modulationIndex_blue = sound.s_params.modIndex_blue;


	for (int i = 0; i < bufferSize; i++) {

		float red_modulation = frequency_red + env_red.adsr(mod_red.sinewave(modulationFrequency_red), env_red.trigger) * modulationIndex_red;
		float green_modulation = frequency_green + env_green.adsr(mod_green.sinewave(modulationFrequency_green), env_green.trigger) * modulationIndex_green;
		float blue_modulation = frequency_blue + env_blue.adsr(mod_blue.sinewave(modulationFrequency_blue), env_blue.trigger) * modulationIndex_blue;
		
		if (sound.s_params.sound_colour == 0) {
			currentSample = 0;
		}
		else if (sound.s_params.sound_colour == 1) {
			if (sound.s_params.oscillator_type_red == 0) {
				currentSample = osc_red.sinewave(red_modulation);
			}
			if (sound.s_params.oscillator_type_red == 1) {
				currentSample = osc_red.triangle(red_modulation);
			}
			if (sound.s_params.oscillator_type_red == 2) {
				currentSample = osc_red.saw(red_modulation);
			}
			if (sound.s_params.oscillator_type_red == 3) {
				currentSample = osc_red.square(red_modulation);
			}
			if (sound.s_params.oscillator_type_red == 4) {
				currentSample = osc_red.noise();
			}
		}
		else if (sound.s_params.sound_colour == 2) {
			if (sound.s_params.oscillator_type_green == 0) {
				currentSample = osc_green.sinewave(green_modulation);
			}
			if (sound.s_params.oscillator_type_green == 1) {
				currentSample = osc_green.triangle(green_modulation);
			}
			if (sound.s_params.oscillator_type_green == 2) {
				currentSample = osc_green.saw(green_modulation);
			}
			if (sound.s_params.oscillator_type_green == 3) {
				currentSample = osc_green.square(green_modulation);
			}
			if (sound.s_params.oscillator_type_green == 4) {
				currentSample = osc_green.noise();
			}
		}
		else if (sound.s_params.sound_colour == 3) {
			if (sound.s_params.oscillator_type_blue == 0) {
				currentSample = osc_blue.sinewave(blue_modulation);
			}
			if (sound.s_params.oscillator_type_blue == 1) {
				currentSample = osc_blue.triangle(blue_modulation);
			}
			if (sound.s_params.oscillator_type_blue == 2) {
				currentSample = osc_blue.saw(blue_modulation);
			}
			if (sound.s_params.oscillator_type_blue == 3) {
				currentSample = osc_blue.square(blue_modulation);
			}
			if (sound.s_params.oscillator_type_blue == 4) {
				currentSample = osc_blue.noise();
			}
		}
		mix.stereo(currentSample, outputs, 0.5);
		output[i * nChannels] = outputs[0];
		output[i * nChannels + 1] = outputs[1];

	}
}
