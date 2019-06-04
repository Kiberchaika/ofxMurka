#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Should I bundle parameters into the widget object instead
    // of a separate parameters object?

    auto params = new MurkaWidgetButton::Parameters{.r = 100,
                                                    .g = 0,
                                                    .b = 0,
                                                    .label = "yo",
                                                    .Callback = [](){}};
    
//    b1 = murka.addChildToViewT(new MurkaWidgetButton(),
//                              NULL, // the data it controls
//                              params,
//                              {100, 100, 100, 35});

    b1 = murka.addChildToViewT(new MurkaWidgetButton(),
                               NULL, // the data it controls
                               params,
                               {100, 100, 100, 35});
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
    
    
    b1->tParams->b = sin(ofGetElapsedTimef() * 10) * 100 + 100;
    
    

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
