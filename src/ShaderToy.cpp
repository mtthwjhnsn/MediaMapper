#include "ShaderToy.h"



ShaderToy::ShaderToy()
{
}


ShaderToy::~ShaderToy()
{
}

void ShaderToy::setup() {
	strobey.load("shaders/ColourStrobe.frag");
	hypnose.load("shaders/Hypnose.frag");
	BitForBit.load("shaders/BitForBit.frag");
	ElSquareo.load("shaders/ElSquareo.frag");
	heyx3DistanceEstimatedFractal.load("shaders/heyx3DistanceEstimatedFractal.frag");
	ngWaves0E.load("shaders/ngWaves0E.frag");
	klksSimplePlasma.load("shaders/klksSimplePlasma.frag");
	StrobescentOne.load("shaders/StrobescentOne.frag");
	Kajastus.load("shaders/Kajastus.frag");
	SeizureMachine.load("shaders/SeizureMachine.frag");
	
}

void ShaderToy::draw(int selection, int x, int y, int w, int h) {
	


	if (selection == 0) { strobey.draw(x, y); }
	strobey.setWidth(w);
	strobey.setHeight(h);
	if (selection == 1) { hypnose.draw(x, y);
	hypnose.setWidth(w);
	hypnose.setHeight(h);
	}
	if (selection == 2) { BitForBit.draw(x, y); 
	BitForBit.setWidth(w);
	BitForBit.setHeight(h);
	}
	if (selection == 3) { ElSquareo.draw(x, y);
	ElSquareo.setWidth(w);
	ElSquareo.setHeight(h);
	}
	if (selection == 4) { heyx3DistanceEstimatedFractal.draw(x, y, w, h); 
	heyx3DistanceEstimatedFractal.setWidth(w);
	heyx3DistanceEstimatedFractal.setHeight(h);
	}
	if (selection == 5) {
		ngWaves0E.draw(x, y, w, h);
		ngWaves0E.setWidth(w);
		ngWaves0E.setHeight(h);
	}
	if (selection == 6) {
		klksSimplePlasma.draw(x, y, w, h);
		klksSimplePlasma.setWidth(w);
		klksSimplePlasma.setHeight(h);
	}
	if (selection == 7) {
		StrobescentOne.draw(x, y, w, h);
		StrobescentOne.setWidth(w);
		StrobescentOne.setHeight(h);
	}
	if (selection == 8) {
		Kajastus.draw(x, y, w, h);
		Kajastus.setWidth(w);
		Kajastus.setHeight(h);
	}
	if (selection == 8) {
		SeizureMachine.draw(x, y, w, h);
		SeizureMachine.setWidth(w);
		SeizureMachine.setHeight(h);
	}
}