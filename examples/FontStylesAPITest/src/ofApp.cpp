#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    m.setRenderer(ofGetGLRenderer().get());
    m.setWindow(ofGetWindowPtr());
    m.setResourcesPath(ofToDataPath(""));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    
    m.begin();
    
    m.setFont("CamingoCode-Regular.ttf", 22);
    m.setColor(255, 250, 250, 255);
    drawWidget<Label>(m, {"it works"}, {100, 100, 300, 50});

    m.setFont("CamingoCode-Regular.ttf", 16);
    m.setColor(255, 0, 250, 255);
    drawWidget<Label>(m, {"it works"}, {100, 150, 300, 50});

    m.setFont("CamingoCode-Regular.ttf", 12);
    m.setColor(0, 220, 250, 255);
    drawWidget<Label>(m, {"it works"}, {100, 200, 300, 50});

    m.end();
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
