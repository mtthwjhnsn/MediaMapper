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

//--------------------------------------------------------------
#include "GuiColourGradient.h"
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))

//--------------------------------------------------------------
GuiColourGradient::GuiColourGradient() {
	
	tileXpos = 0;
	tileYpos = 0;
	tileWidth = 256;
	tileHeight = 144;

	canvasWidth = 1280;
	canvasHeight = 720;

	tileZoom = 0.25;
}

//-------------------------------------------------
void GuiColourGradient::setup(input_selector *_inputs) {

	ofxSpout2::Sender placeholder;

	NDIsearching, SpoutSearching, setup_spout = false;	
	spoutNum, ndiNum = 0;

	assign_styles = false;

	NDI_reciever.setup();
	//------------------------

	io = &ImGui::GetIO();
	font_config; font_config.OversampleH = 1; font_config.OversampleV = 1; font_config.PixelSnapH = 1;
	f = io->Fonts->AddFontFromFileTTF("data/Overpass/Overpass-Regular.ttf", 16.0f, NULL, io->Fonts->GetGlyphRangesChinese());

	//---------------
	gui.setup();
	
	guiVisible = true;

	inputs = _inputs;

	activeVid = 0;
	activeImg = 0;

	//fboSettings.width = w;
	//fboSettings.height = h;
	fboSettings.internalformat = GL_RGBA;
	fboSettings.textureTarget = GL_TEXTURE_2D;

	//fboSettings.width = w / 3;
	//fboSettings.height = h / 2;

	fboSettings.width = tileWidth;
	fboSettings.height = tileHeight;

	Overpass.load("/Overpass/Overpass-Regular.ttf", 100);

	input_num = 7;

	IDs = { "test", "video", "image", "camera", "shader", "spout", "ndi" };
	//spout = false;
	
	// populate vectors
	for (int i = 0; i <= input_num; i++) {
		
		add_instances.push_back(0);
		toggles.push_back(0);
		selectors.push_back(0);
	}

	for (int i = 0; i <= input_num; i++) {
		select_vect.push_back(selectors);
	}

	for (int i = 0; i <= 9; i++) {

		TestFbo.allocate(fboSettings);
		TestFbo.begin();
		ofClear(255, 255, 255, 0);
		TestFbo.end();
		TestFbos.push_back(TestFbo);

		TestID = (ImTextureID)TestFbos[i].getTexture().texData.textureID;
		test_tex_ids.push_back(TestID);

		test_spout.push_back(false);
		test_ndi.push_back(false);

		test_spout_sends.push_back(placeholder);

	}

	for (int i = 0; i <= 9; i++) {

		VideoFbo.allocate(fboSettings);
		VideoFbo.begin();
		ofClear(255, 255, 255, 0);
		VideoFbo.end();
		VideoFbos.push_back(VideoFbo);

		VideoID = (ImTextureID)VideoFbos[i].getTexture().texData.textureID;
		video_tex_ids.push_back(VideoID);

		video_spout.push_back(false);
		video_ndi.push_back(false);

		video_spout_sends.push_back(placeholder);
	}

	for (int i = 0; i <= 9; i++) {

		ImageFbo.allocate(fboSettings);
		ImageFbo.begin();
		ofClear(255, 255, 255, 0);
		ImageFbo.end();
		ImageFbos.push_back(ImageFbo);

		ImageID = (ImTextureID)ImageFbos[i].getTexture().texData.textureID;
		image_tex_ids.push_back(ImageID);

		image_spout.push_back(false);
		image_ndi.push_back(false);

		image_spout_sends.push_back(placeholder);
	}

	for (int i = 0; i <= 9; i++) {

		CameraFbo.allocate(fboSettings);
		CameraFbo.begin();
		ofClear(255, 255, 255, 0);
		CameraFbo.end();
		CameraFbos.push_back(CameraFbo);

		CameraID = (ImTextureID)CameraFbos[i].getTexture().texData.textureID;
		camera_tex_ids.push_back(CameraID);

		camera_spout.push_back(false);
		camera_ndi.push_back(false);

		camera_spout_sends.push_back(placeholder);
	}

	for (int i = 0; i <= 9; i++) {

		ShaderFbo.allocate(fboSettings);
		ShaderFbo.begin();
		ofClear(255, 255, 255, 0);
		ShaderFbo.end();
		ShaderFbos.push_back(ShaderFbo);

		ShaderID = (ImTextureID)ShaderFbos[i].getTexture().texData.textureID;
		shader_tex_ids.push_back(ShaderID);

		shader_spout.push_back(false);
		shader_ndi.push_back(false);

		shader_spout_sends.push_back(placeholder);
	}

	for (int i = 0; i <= 9; i++) {

		SpoutFbo.allocate(fboSettings);
		SpoutFbo.begin();
		ofClear(255, 255, 255, 0);
		SpoutFbo.end();
		SpoutFbos.push_back(SpoutFbo);

		SpoutID = (ImTextureID)SpoutFbos[i].getTexture().texData.textureID;
		spout_tex_ids.push_back(SpoutID);

		spout_spout.push_back(false);
		spout_ndi.push_back(false);

		spout_spout_sends.push_back(placeholder);
	}

	for (int i = 0; i <= 9; i++) {

		NDIFbo.allocate(fboSettings);
		NDIFbo.begin();
		ofClear(255, 255, 255, 0);
		NDIFbo.end();
		NDIFbos.push_back(NDIFbo);

		NDIID = (ImTextureID)NDIFbos[i].getTexture().texData.textureID;
		ndi_tex_ids.push_back(NDIID);
	
		ndi_spout.push_back(false);
		ndi_ndi.push_back(false);
	
		ndi_spout_sends.push_back(placeholder);
	}

	spoutBools.push_back(test_spout);
	spoutBools.push_back(video_spout);
	spoutBools.push_back(image_spout);
	spoutBools.push_back(camera_spout);
	spoutBools.push_back(shader_spout);
	spoutBools.push_back(spout_spout);
	spoutBools.push_back(ndi_spout);

	ndiBools.push_back(test_ndi);
	ndiBools.push_back(video_ndi);
	ndiBools.push_back(image_ndi);
	ndiBools.push_back(camera_ndi);
	ndiBools.push_back(shader_ndi);
	ndiBools.push_back(spout_ndi);
	ndiBools.push_back(ndi_ndi);


	
	spoutSenders = {test_spout_sends, video_spout_sends, image_spout_sends, camera_spout_sends, shader_spout_sends, spout_spout_sends, ndi_spout_sends };
	tex_vect = { test_tex_ids, video_tex_ids, image_tex_ids, camera_tex_ids, shader_tex_ids, spout_tex_ids, ndi_tex_ids };
	Fbos = {TestFbos, VideoFbos, ImageFbos, CameraFbos, ShaderFbos, SpoutFbos, NDIFbos};
	
	//mesh
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(1);

}

ImTextureID GuiColourGradient::getTextureIDGui() {
	return GuiID;
}
ImTextureID GuiColourGradient::getTextureIDTest() {
	return TestID;
}
ImTextureID GuiColourGradient::getTextureIDImage() {
	return ImageID;
}
ImTextureID GuiColourGradient::getTextureIDVideo() {
	return VideoID;
}
ImTextureID GuiColourGradient::getTextureIDCamera() {
	return CameraID;
}
ImTextureID GuiColourGradient::getTextureIDShader() {
	return ShaderID;
}
ImTextureID GuiColourGradient::getTextureIDSpout() {
	return SpoutID;
}
ImTextureID GuiColourGradient::getTextureIDNDI() {
	return NDIID;
}

void GuiColourGradient::update() {
}

//-------------------------------------------------
void GuiColourGradient::draw() {

	int w = 800;
	int h = 180;

	if (guiVisible) {
		//IMGUI		
		imGui();

	}
	
		for (int i = 0; i < TestFbos.size(); i++) {
			TestFbos[i].begin();
			ofBackground(50, 50);
			inputs->splash_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("test " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			TestFbos[i].end();
		}
		for (int i = 0; i < inputs->vid->videoThumbs.size(); i++) {
			VideoFbos[i].begin();
			ofBackground(50, 50);
			if (i == activeVid) {
				inputs->video_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			}
			else {
				inputs->video_drawThumbs(i, tileXpos, tileYpos, tileWidth, tileHeight);
			}
			
			//Overpass.drawString("video " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			VideoFbos[i].end();
		}
		for (int i = 0; i < inputs->img->imageThumbs.size(); i++) {
			ImageFbos[i].begin();
			ofBackground(50, 50);
			if (i == activeImg) {
				inputs->image_draw(tileXpos, tileYpos, tileWidth, tileHeight);
			}
			else {
				inputs->image_drawThumbs(i, tileXpos, tileYpos, tileWidth, tileHeight);
			}
			//Overpass.drawString("image " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			ImageFbos[i].end();
		}
		for (int i = 0; i < inputs->cam->cams.size(); i++) {
			CameraFbos[i].begin();
			ofBackground(50, 50);
			inputs->camera_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			//Overpass.drawString("camera " + ofToString(i) + " " + ofToString(tileWidth) + " x " + ofToString(tileHeight), 50, 150);
			CameraFbos[i].end();
		}
		for (int i = 0; i < 10; i++) {
			ShaderFbos[i].begin();
			ofBackground(50, 50);
			inputs->shader_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			ShaderFbos[i].end();
		}

		for (int i = 0; i < spoutNum; i++) {
			if (SpoutSearching == true && setup_spout == true) {
				inputs->spout_draw(i, tileXpos, tileYpos, tileWidth, tileHeight);
			}
			SpoutFbos[i].begin();
			ofBackground(50, 50);
			if (SpoutSearching == true && setup_spout == true) {
				inputs->spoutIn->texs[i].draw(tileXpos, tileYpos, tileWidth, tileHeight);
			}
			SpoutFbos[i].end();
		}

		for (int i = 0; i < ndiNum; i++) {
			NDIFbos[i].begin();
			ofBackground(50, 50);
			if (NDIsearching == true) {
				NDI_reciever.draw(tileXpos, tileYpos, tileWidth, tileHeight);
			}
			NDIFbos[i].end();
		}
	}
//--------------------------------------------------------------
void GuiColourGradient::styles() {
	
	ImGuiStyle& style = ImGui::GetStyle();
	style.Colors[ImGuiCol_Text] = ImVec4(0.61f, 1.00f, 0.77f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(1.00f, 1.00f, 1.00f, 0.96f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.05f, 0.84f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.11f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.49f, 0.44f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.13f, 0.14f, 0.17f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.49f, 0.44f, 0.35f, 0.88f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.49f, 0.44f, 0.24f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.90f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.61f, 1.00f, 0.77f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.43f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.00f, 1.00f, 0.47f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.00f, 0.00f, 0.59f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.59f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.84f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.59f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.47f, 0.77f, 0.83f, 0.32f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.59f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.01f, 0.13f, 1.00f, 0.58f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(0.86f, 0.93f, 0.89f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.86f, 0.93f, 0.89f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.82f, 0.18f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.49f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.82f, 0.18f, 0.29f, 0.56f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.82f, 0.18f, 0.29f, 0.50f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.74f);


	//style.WindowPadding = ImVec2(20);

	ImGuiStyle* style1 = &ImGui::GetStyle();

	style1->WindowPadding = ImVec2(20.0f, 20.0f);
	style1->WindowRounding = 0.0f;
	style1->ChildWindowRounding = 0.0f;
	style1->FramePadding = ImVec2(5.0f, 5.0f);
	style1->FrameRounding = 0.0f;
	style1->ItemSpacing = ImVec2(20.0f, 2.0f);
	style1->ItemInnerSpacing = ImVec2(3.0f, 0.0f);
	style1->TouchExtraPadding = ImVec2(3.0f, 0.0f);
	style1->IndentSpacing = 10.0f;
	style1->ScrollbarSize = 13.0f;
	style1->ScrollbarRounding = 16.0f;
	style1->GrabMinSize = 5.0f;
	style1->GrabRounding = 0.0f;
	style1->WindowMinSize = ImVec2(550.0f, 360.0f);

	ImFontAtlas* atlas = ImGui::GetIO().Fonts;
}

//--------------------------------------------------------------
void GuiColourGradient::Resolutions() {
	static float customWidth = 1920, customHeight = 1080;
	ofVec2f custom = {customWidth, customHeight};
	vector<ofVec2f> resolutions = { custom, {256, 144}, {384, 216}, {512, 218}, {640, 360}, {768, 432}, {1280, 720}, {1920, 1080}, {2560, 1440}, {3840, 2160}, {7680, 4320} };
	const char* resolutions1[] = { "custom", "256 x 144", "384 x 216", "512 X 218", "640 x 360", "768 x 432", "1280 x 720 (720p)", "1920 x 1080 (1080p)", "2560 x 1440 (QHD)", "3840 x 2160 (4k)", "7680 x 4320 (8k)"};
	static int resolutions2 = -1;

	ImGui::Combo("output resolution", &resolutions2, resolutions1, IM_ARRAYSIZE(resolutions1));

	if(resolutions2 == 0) {
		static int i0 = 1920;
		static int i1 = 1080;
		ImGui::InputInt("output_width", &i0);
		ImGui::InputInt("output_height", &i1);
		customWidth = i0;
		customHeight = i1;
	}

	//int select = resolutions2;

	//resolutions[select][0] = tileWidth;
	//resolutions[select][1] = tileHeight;

	cout << ofToString(tileWidth) + "  " + ofToString(tileHeight) << endl;
	

	for (int i = 0; i <= resolutions.size(); i++) {
		if (resolutions2 == i) {
			tileWidth = resolutions[i][0];
			tileHeight = resolutions[i][1];
		}
	}
}

//------------------------------------------------
void GuiColourGradient::Navigate() {

	ImGui::SameLine();
	//ypos
//	ImGui::VSliderInt("tileYpos", ImVec2(18, 180), &tileYpos, 2160, -2160);
	//xpos
	static int i2 = 100;

	//	ImGui::SliderInt("tileXpos", &tileXpos, -3840, 3840);
	//	ImGui::SameLine();
	if (ImGui::Button("left")) {
		tileXpos = tileXpos - 10;
	}
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

	ImGui::InputInt("Zoom %", &i2);
	tileZoom = i2 * .01;
	tileWidth = tileWidth * tileZoom;
	tileHeight = tileHeight * tileZoom;
}


void GuiColourGradient::InputWindow(int selection) {

	ImVec4 c1 = ImColor::HSV(0.61f, 1.00f, 0.77f, 1.00f);
	ImVec4 c2 = ImColor(0.61f, 1.00f, 0.77f, 1.00f);
	

	if (ImGui::CollapsingHeader(ofxImGui::GetUniqueName(IDs[selection]), true)) {
		
		if (selection == 1 || selection == 2) {
			ImGui::Text("Drag media from your drives into the Window to Load!");
		}


		//spout toggle searching and setup
		if (selection == 5) {
			if (setup_spout == false) {
				if (ImGui::Button("configure")) {
					inputs->spoutIn->setup();
					setup_spout = true;
				}
			}
			else {
				ImGui::Checkbox("Spout_Searching", &SpoutSearching);
			}
		}
		if (selection == 5) {
			ImGui::InputInt("Spout_Textures", &spoutNum);
		}


		//NDI toggle searching
		if (selection == 6) {
			ImGui::Checkbox("NDI_Searching", &NDIsearching);
			ImGui::InputInt("NDI_Textures", &ndiNum);
		}

		int loop = 9;
		if (selection == 3) { loop = 0; }
		if (selection == 4) { loop = 8; }
		if (selection == 5) { loop = spoutNum; }
		if (selection == 6) { loop = ndiNum; }

		int columns = 2;
		ImGui::Columns(columns);
		ImGui::SetColumnOffset(0, 0);
		ImGui::SetColumnOffset(1, 160);
		ImGui::SetColumnOffset(2, 320);

		for (int j = 0; j <= loop; j++) {
			//spoutmenu
			if (selection == 5) {
				if (ImGui::Button(ofxImGui::GetUniqueName("Choose_Spout" + ofToString(j)))) {
					inputs->spout_list(j);
				}
			}
			// active senders are highlighted
			if (select_vect[selection][toggles[selection]] == j) {
				ImGui::PushStyleColor(ImGuiCol_Button, c2);
			}
			else { ImGui::PushStyleColor(ImGuiCol_Button, c1); }

			//if input thumbnail is pressed the active output equals the thumbnail number
			if (ImGui::ImageButton(tex_vect[selection][j], ofVec2f(160, 90))) {
				select_vect[selection][toggles[selection]] = j;
				//for the video thumbnail trigger the path swapping function
				if (selection == 1) {
					inputs->video_swap(j);
					activeVid = j;
				}
				if (selection == 2) {
					inputs->image_swap(j);
					activeImg = j;
				}
			}

			if (select_vect[selection][toggles[selection]] == j) {
				ImGui::PopStyleColor();
			}
			else { ImGui::PopStyleColor(); }
			ImGui::NextColumn();
		}
	}

	ImGui::Columns(1);
}


//--------------------------------------------------------------
void GuiColourGradient::OutputWindow(int selection) {

	static char buf[64], buf1[64], buf2[64], buf3[64], buf4[64], buf5[64], buf6[64] = "";

	int mini_width = 320;
	int mini_height = 180;

	if (ImGui::CollapsingHeader(ofxImGui::GetUniqueName(IDs[selection]), false)) {
		ImGui::InputInt(ofxImGui::GetUniqueName("textures"), &add_instances[selection]);
		ImGui::Spacing();

		for (int i = 0; i < add_instances[selection]; i++) {
			// -------------Toggles
			ImGui::SameLine();
			ImGui::RadioButton(ofxImGui::GetUniqueName(ofToString(i)), &toggles[selection], i);

		}

		for (int i = 0; i <= add_instances[selection]; i++) {
			// -------------Toggles
			ImGui::Text(ofxImGui::GetUniqueName(IDs[selection] + ofToString(i)));
			ImGui::SameLine();
			ImGui::RadioButton(ofxImGui::GetUniqueName(ofToString(i)), &toggles[selection], i);
			Resolutions();
			ImGui::Image(tex_vect[selection][select_vect[selection][i]], ofVec2f(mini_width, mini_height));
			Navigate();
			//ImGui::InputText("Send_ID" + i, buf, 64, ImGuiInputTextFlags_CharsNoBlank);
			//ImGui::SameLine();

			ImGui::Checkbox(ofxImGui::GetUniqueName("spout" + ofToString(i)), &spoutBools[selection][i]);
			ImGui::SameLine();
			
			if (spoutBools[selection][i] == true) {
				spoutSenders[selection][i].sendTexture(Fbos[selection][select_vect[selection][i]].getTexture(), "Mapper" + ofToString(selection) + ofToString(i));
			}

			ImGui::Checkbox(ofxImGui::GetUniqueName("ndi" + ofToString(i)), &ndiBools[selection][i]);
						if (ndiBools[selection][i] == true) {
							inputs->NDI_out(Fbos[selection][select_vect[selection][i]], tileXpos, tileYpos, tileWidth, tileHeight);
			}
		}
	}
}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

										GUI
______________________________________________________________________________________
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

bool GuiColourGradient::imGui()
{
	if (assign_styles == false) {
		styles();
		assign_styles = true;
	}

	int gui_width = 700;
	auto mainSettings = ofxImGui::Settings();
	ofVec2f pos(180, 40);
	ofVec2f pos1(650, 40);
	ofVec2f pos2(1250, 40);

	mainSettings.windowPos = pos;
	this->gui.begin();

	{

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("INPUT"))
			{
				ImGui::MenuItem("(dummy menu)", NULL, false, false);
				if (ImGui::MenuItem("No_Input")) {
					//inputs->params.input_type = 0;
					//inputs->selection();
				}
				if (ImGui::MenuItem("Video", "Ctrl+V")) {
					//inputs->params.input_type = 1;
					//inputs->selection();
				}
				if (ImGui::MenuItem("Image", "Ctrl+I")) {
					//inputs->params.input_type = 2;
					//inputs->selection();
				}
				if (ImGui::MenuItem("Camera", "Ctrl+C")) {
					//inputs->params.input_type = 3;
					//inputs->selection();
				}
				if (ImGui::MenuItem("Gradient", "Ctrl+G")) {
					//inputs->params.input_type = 4;
					//inputs->selection();
				}
				if (ImGui::MenuItem("Spout2", "Ctrl+O")) {
					//inputs->params.input_type = 5;
					//inputs->selection();
				}
				ImGui::EndMenu();
			}


			if (ImGui::BeginMenu("Outputs"))
			{
/*
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
					ImGui::EndMenu();
				}*/

				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		//TEXTURES

		//WINDOWS---------------------------------------------------------------
		//WINDOWS---------------------------------------------------------------
		//WINDOWS---------------------------------------------------------------

		mainSettings.windowPos = pos1;
		if (ofxImGui::BeginWindow("OUTPUT_TEXTURES", mainSettings, false)) {
			ImGui::Separator();
			for (int i = 0; i < input_num; i++) {

				OutputWindow(i);
				//spoutToggles();
			}
			ofxImGui::EndWindow(mainSettings);
		}


		ImGuiStyle* style1 = &ImGui::GetStyle();
		style1->WindowMinSize = ImVec2(320.0f, 360.0f);
		mainSettings.windowPos = pos;
		if (ofxImGui::BeginWindow("INPUT_TEXTURES", mainSettings, false)) {
			ImGui::Separator();
						
			for (int i = 0; i < input_num; i++) {
				InputWindow(i);
			}
			ofxImGui::EndWindow(mainSettings);
		}

		mainSettings.windowPos = pos2;
		style1->WindowMinSize = ImVec2(180.0f, 180.0f);
		if (ofxImGui::BeginWindow("Sending_Moniter", mainSettings, false)) {
			ImGui::Separator();
			ImGui::Text("Spout");
			for (int i = 0; i < input_num; i++) {
				for (int j = 0; j < spoutBools[i].size(); j++) {
					if (spoutBools[i][j] == true) {
						ImGui::Text(ofxImGui::GetUniqueName("SENDING type: " + ofToString(IDs[i]) + ", number: " + ofToString(j) + " ID: Mapper" + ofToString(i) + ofToString(j)));
					}
					else {
						if (j == 0 && i == 0) { ImGui::Text("NO SPOUT SENDING"); }
					}
				}
			}
			ImGui::Text("NDI");
			for (int i = 0; i < input_num; i++) {
				for (int j = 0; j < ndiBools[i].size(); j++) {
					if (ndiBools[i][j] == true) {
						ImGui::Text(ofxImGui::GetUniqueName("SENDING type: " + ofToString(IDs[i]) + ", number: " + ofToString(j) + " ID: Mapper" + ofToString(i) + ofToString(j)));
					}
					else {
						if (j == 0 && i == 0) { ImGui::Text("NO NDI SENDING"); }
					}
				}
			}

			ofxImGui::EndWindow(mainSettings);
		}

		this->gui.end();
		return mainSettings.mouseOverGui;
	}

}