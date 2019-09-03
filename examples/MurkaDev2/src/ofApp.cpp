#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Murka setup
    
    murka.setupFonts("Roboto-Regular.ttf", 12,
                     "Roboto-Regular.ttf", 20,
                     "CamingoCode-Regular.ttf", 12);
    
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
    
    // TODO: there is a weird bug that makes these two widgets a part of the panel
    // even though they're added to the core murka view.
    header1 = murka.addChildToView(/*panel1, */ new Header(),
                                   NULL,
                                   {"OOP Mode"},
                                   {10, 5, 260, 50});
    
    label1 = murka.addChildToView(/*panel1, */ new Label(),
                                  NULL,
                                  {"Manually created widget graph"},
                                  {10, 55, 260, 50});
    
/*
    
    View v;
    v.layoutGenerator.setLayoutStructure({{30, RIGHT},
                                           0.5,
                                           1.0});
     */
    
    
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
    

    ///////////////// Immediate mode with manual layout

    murka.beginDrawingInView(&murka);
    drawWidget<BlankPanel>(murka, {"", booleanTest}, {350, 50, 260, 500});
    
    
    auto panelShape = murka.getLatestChildShape(); // going to use this to resize widgets manually

    murka.beginDrawingInLatestView();
    
    drawWidget<Header>(murka, {"IM Mode"}, {20, 5,  panelShape.size.x - 40, 35});

    drawWidget<Label>(murka, {"Manual IM mode layout"}, {20, 55,  panelShape.size.x - 40, 35});
    drawWidget<Checkbox>(murka, &booleanTest, {"Moveable panel"}, {20, 85, panelShape.size.x - 40, 35});
    
    drawWidget<SliderFloat>(murka, &(*testArray.begin()), {"slider 2"}, {20, 120, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 1)), {"slider 3"}, {20, 160, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 2)), {"slider 4"}, {20, 200, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(murka, &(*(testArray.begin() + 3)), {"slider 5"}, {20, 240, panelShape.size.x - 40, 35});

    drawWidget<Button>(murka, {"button 1"}, {20, 280, panelShape.size.x - 40, 35});

    drawWidget<PlainTextField>(murka, &testString, false, {20, 330, panelShape.size.x - 40, 35});
    
    drawWidget<DraggableNumberEditor>(murka, &numberEditorTest, {4, 800.0, 8000.0}, {20, 420, panelShape.size.x - 40, 35});
    
    
    ///////////////// Immediate mode with automatic layout
    
    
    murka.beginDrawingInView(&murka);
    drawWidget<BlankPanel>(murka, {}, {650, 50, 260, 500});
    murka.beginDrawingInLatestView();
    drawWidget<Header>(murka, {"IM Autolayout"}, {20, 5,  260, 35});
    
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
