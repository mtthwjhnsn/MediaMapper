#pragma once

#include "ofMain.h"
#include "ofxShadertoy.h"


class ShaderToy
{
public:
	ShaderToy();
	~ShaderToy();

	void setup();
	void draw(int selection, int x, int y, int w, int h);

	ofxShadertoy strobey; // notoriousKnave
	ofxShadertoy hypnose; // Jespertheend 
	ofxShadertoy BitForBit; // anastadunbar
	ofxShadertoy ElSquareo; // bendecoste
	ofxShadertoy heyx3DistanceEstimatedFractal; // heyx3
	ofxShadertoy ngWaves0E; //  netgrind
	ofxShadertoy klksSimplePlasma; //  klk
	ofxShadertoy StrobescentOne; // MrHenryBemis
	ofxShadertoy Kajastus; //  Marken
	ofxShadertoy SeizureMachine; //  jackdavenport
};

