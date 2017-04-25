#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("moji");

	ofBackground(255);
	ofSetFrameRate(30);


	this->font_size = 20;
	this->font_span = ofGetWidth() / 20;

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size);
	this->moji = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	this->x_noise = ofRandom(10);
	this->y_noise = ofRandom(10);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofColor moji_color;

	float tmp_x_noise = this->x_noise;
	float tmp_y_noise = this->y_noise;
	float noise = 0.005;

	for (int x = this->font_size / 2; x < ofGetWidth() - this->font_size / 2; x += this->font_span) {

		tmp_x_noise += noise;
		tmp_y_noise = this->y_noise;

		for (int y = this->font_size * 1.5; y < ofGetHeight(); y += this->font_span) {
			float noise_value = ofMap(ofNoise(tmp_x_noise, tmp_y_noise), 0, 1, 0, 25);

			moji_color.setHsb(noise_value * 10, 255, 255);
			ofSetColor(moji_color);

			this->font.drawString(this->moji.substr(noise_value, 1), x, y);
			tmp_y_noise += noise;
		}
	}

	//this->x_noise += noise;
	this->y_noise -= noise;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
