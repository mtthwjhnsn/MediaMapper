#include "output_selector.h"

//-----------------------------
void output_selector::setup() {
	params.output_type = 0;

}


void output_selector::draw(ofFbo fbo) {

	if (NDIsender == true) {
		NDI.send(fbo);
	}

	if (spout2Sender == true) {
		Spout2.send(fbo);
	}
}




void output_selector::selection() {
	int menu_input = params.output_type;
	
	if (menu_input == 1) {

		spout2Sender = true;
		NDIsender = false;
		noSender = false;

		NDI.exit();
		Spout2.exit();


		Spout2.setup();
	}

	if (menu_input == 2) {

		spout2Sender = false;
		NDIsender = true;
		noSender = false;


		Spout2.exit();
		NDI.exit();
		NDI.setup();
	}

	if (menu_input == 0) {

		spout2Sender = false;
		NDIsender = false;
		noSender = true;

		Spout2.exit();
		NDI.exit();
	}


}