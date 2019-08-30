#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Murka setup
    
    murka.setupFonts("Roboto-Regular.ttf", 12,
                     "Roboto-Regular.ttf", 20);
    
    //
    
    panel1 = murka.addChildToView(new BlankPanel(),
                                   NULL,
                                   {"panel1", true},
                                   {50, 50, 260, 500});
    
    
    b1 = murka.addChildToView(panel1, new Button(),
                               NULL, // the data it controls
                               {"button1"},
                               {20, 120, 100, 35});

    b2 = murka.addChildToView(panel1, new Button(),
                               NULL, // the data it controls
                               {120, 120, 120, "button2"},
                               {140, 120, 100, 35});
    
    slider1 = murka.addChildToView(panel1, new SliderFloat(),
                                    &(*testArray.begin()),
                                    {0, 1, "slider 1"},
                                    {20, 220, 220, 35});
    
    textField1 = murka.addChildToView(panel1, new PlainTextField(),
                                       &testString,
                                       {},
                                       {20, 270, 220, 35});
    
    View v;
    v.layoutGenerator.setLayoutStructure({{30, RIGHT},
                                           0.5,
                                           1.0});
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofClear(10);
    
    ofSetColor(255, 0, 0);
    
    auto time = ofGetElapsedTimef();
    
    b1->tParams->b = sin(time * 10) * 100 + 100;
    
    // Initial drawing and setup & object-oriented mode

    murka.drawCycle();
    
    if (b1->getResults() == true) ofLog() << "button 1 true!";
    if (b2->getResults() == true) ofLog() << "button 2 true!";
    

    ///////////////// Immediate mode with custom widget sizes

    murka.beginDrawingInView(&murka);
    drawWidget<BlankPanel>(murka, {"", true}, {350, 50, 260, 500});
    
    auto panelShape = murka.getLatestChildShape();

    murka.beginDrawingInLatestView();
    drawWidget<SliderFloat>(murka, &(*testArray.begin()), {"slider 2"}, {20, 120, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 1)), {"slider 3"}, {20, 160, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 2)), {"slider 4"}, {20, 200, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 3)), {"slider 5"}, {20, 240, panelShape.size.x - 40, 35});

    if (drawWidget<Button>(murka, {"button 1"}, {20, 280, panelShape.size.x - 40, 35})) {
        ofLog() << "it worked " << ofRandom(255);
    }
    
    drawWidget<PlainTextField>(murka, &testString, false, {20, 330, panelShape.size.x - 40, 35});
    
    return;
    
    
    ofClear(0);
    
    ofSetColor(255, 0, 0);
    ofDrawLine(200, 0, 0, 200);
    
    ofSetColor(255);
    ofPushView();
    auto vport = ofGetCurrentViewport();
    ofViewport(ofRectangle(0, 0, 200, 200));
    ofScale((vport.getWidth() / 200.), (vport.getHeight() / 200.));
    ofDrawLine(0, 0, 200, 200);
    ofPopView();
    
    ofDrawBitmapStringHighlight("LALALA", 200, 200);
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
