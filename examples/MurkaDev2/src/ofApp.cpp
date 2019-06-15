#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    panel1 = murka.addChildToViewT(new MurkaBlankPanel(),
                                   NULL,
                                   {100, 20, 20, "panel1"},
                                   {50, 50, 250, 500});
    
    
    b1 = murka.addChildToViewT(panel1, new MurkaWidgetButton(),
                               NULL, // the data it controls
                               {"button1"},
                               {20, 20, 100, 35});


    auto params2 = new MurkaWidgetButton::Parameters("button2");

    b2 = murka.addChildToViewT(panel1, new MurkaWidgetButton(),
                               NULL, // the data it controls
                               {120, 120, 120, "button2"},
                               {20, 120, 100, 35});
    
    slider1 = murka.addChildToViewT(panel1, new MurkaSliderFloat(),
                                    &TESTER,
                                    {0, 1, "slider 1"},
                                    {20, 220, 210, 35});
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(30);
    
    ofSetColor(255, 0, 0);
    
    auto time = ofGetElapsedTimef();
    
//    panel1->shape.position = {100 + 50 * sin(time * 5), 50};
    
    
    b1->tParams->b = sin(time * 10) * 100 + 100;
    
    

    murka.drawCycle();
    
//    if (b1->getResults() == true) ofLog() << "button 1 true!";
//    if (b2->getResults() == true) ofLog() << "button 2 true!";
    
//    ofLog() << *(b1->castResults(b1->resultsInternal));

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
