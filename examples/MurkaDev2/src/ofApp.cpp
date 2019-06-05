#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panel1 = murka.addChildToViewT(new MurkaBlankPanel(),
                                   NULL,
                                   {.r = 100, .g = 20, .b = 20, .label = "panel1"},
                                   {50, 50, 250, 500});
    
    
    auto params = new MurkaWidgetButton::Parameters{.r = 100,
                                                    .g = 0,
                                                    .b = 0,
                                                    .label = "yo",
                                                    .Callback = [](){}};
    
    b1 = murka.addChildToViewT(panel1, new MurkaWidgetButton(),
                               NULL, // the data it controls
                               params,
                               {20, 20, 100, 35});
}

//--------------------------------------------------------------
void ofApp::update(){

}

/*
void ofApp::reinit() {
	ofLog() << "reinited... " << ofRandomuf() * 23;


}
 */

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(30);
    
    ofSetColor(255, 0, 0);
    
    /*
    MurkaWidgetButton::parameters(murka.children[0])->r = sin(ofGetElapsedTimef() * 10) * 100 + 100;
    */
    
    
//    MurkaWidgetButton::parameters(b1)->g = sin(ofGetElapsedTimef() * 20) * 100 + 100;
    
    auto time = ofGetElapsedTimef();
    
//    panel1->shape.position = {100 + 50 * sin(time * 5), 50};
    
    
    b1->tParams->b = sin(time * 10) * 100 + 100;
    
    

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
