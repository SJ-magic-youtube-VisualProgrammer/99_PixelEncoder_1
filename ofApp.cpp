/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(){
}

/******************************
******************************/
ofApp::~ofApp(){
	delete Gui_Global;
	
	if(fp_Log)	fclose(fp_Log);
}

/******************************
******************************/
void ofApp::exit(){
	printf("> Good-bye\n");
	fflush(stdout);
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("shaderTest");
	
	ofSetWindowShape( WINDOW_WIDTH, WINDOW_HEIGHT );
	ofSetVerticalSync(true);	// trueとどっちがいいんだろう？
	ofSetFrameRate(30);
	
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	fp_Log = fopen("../../../data/Log.csv", "w");
	setup_Gui();
	
	/********************
	********************/
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA); // OF_BLENDMODE_ADD
	ofEnableSmoothing();
	
	/********************
	********************/
	img.load("img/img.png");
	
	shader.load( "shader_sj/shader.vert", "shader_sj/shader.frag" );
}

/******************************
description
	memoryを確保は、app start後にしないと、
	segmentation faultになってしまった。
******************************/
void ofApp::setup_Gui()
{
	/********************
	********************/
	Gui_Global = new GUI_GLOBAL;
	Gui_Global->setup("param", "gui.xml", 10, 10);
}

/******************************
******************************/
void ofApp::update(){

}

/******************************
******************************/
void ofApp::draw(){
	/********************
	********************/
	ofBackground(0);
	
	/********************
	********************/
	shader.begin();
		shader.setUniform1i( "NumDots", int(Gui_Global->NumDots) );
		shader.setUniform1i( "xN", int(Gui_Global->xN) );
		shader.setUniform1i( "id", min(int(Gui_Global->id), int(Gui_Global->NumDots) * int(Gui_Global->NumDots) - 1) );
		
		ofSetColor(255);
		img.draw(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();
	
	/********************
	********************/
	if(Gui_Global->b_Disp){
		/********************
		********************/
		Gui_Global->gui.draw();
		
		/********************
		********************/
		{
			ofSetColor(255);
			string info;
			info += "FPS = " + ofToString(ofGetFrameRate(), 2) + "\n";
			ofDrawBitmapString(info, 30, 30);
		}
	}
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	/********************
	********************/
	switch(key){
		case 'd':
			Gui_Global->b_Disp = !Gui_Global->b_Disp;
			break;
			
		case 'm':
			Gui_Global->gui.minimizeAll();
			break;
			
		case 'j':
			img_Screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img_Screen.save("screenshot.jpg");
			
			printf("> saved image\n");
			fflush(stdout);
			break;
			
		case 'p':
			img_Screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img_Screen.save("screenshot.png");
			
			printf("> saved image\n");
			fflush(stdout);
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
