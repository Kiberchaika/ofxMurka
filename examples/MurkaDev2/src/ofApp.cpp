#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	murka.addChildToView(murka.getRootView(), b, NULL);
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::reinit() {
	ofLog() << "reinited... " << ofRandomuf() * 23;


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(30);

	murka.drawCycle();
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
