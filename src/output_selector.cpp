#include "output_selector.h"

//-----------------------------
void output_selector::setup(NDIoutput *_NDI, Spout2Sender *_spout) {
	
	NDIsender = _NDI;
	SpoutSender = _spout;
	no_output = true;
	NDI = false;
	spout = false;

}

void output_selector::draw() {

	if (NDI == true) {
		NDIsender->update();
		NDIsender->send();
	}

	if (spout == true) {
		SpoutSender->send();
	}
}

void output_selector::selection() {
	int menu_input = params.output_type;

	if (menu_input == 0) {

		spout = true;
		NDI = false;
		no_output = false;

		NDIsender->exit();
		SpoutSender->exit();
		SpoutSender->setup();
		
	}

	if (menu_input == 1) {

		spout = false;
		NDI = true;
		no_output = false;


		SpoutSender->exit();
		NDIsender->exit();
		NDIsender->setup();

	}
	if (menu_input == 3) {

		spout = false;
		NDI = false;
		no_output = true;

		SpoutSender->exit();
		NDIsender->exit();

	}

}