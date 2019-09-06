#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Murka setup
    
    m.setupFonts("Roboto-Regular.ttf", 12,
                     "Roboto-Regular.ttf", 20,
                     "CamingoCode-Regular.ttf", 12);
    
    //
    
    panel1 = m.addChildToView(new BlankPanel(),
                                   NULL,
                                   {"panel1", true},
                                   {350, 50, 260, 500});
    
    b1 = m.addChildToView(panel1, new Button(),
                               NULL, // the data it controls
                               {"button1"},
                               {20, 120, 100, 35});

    b2 = m.addChildToView(panel1, new Button(),
                               NULL, // the data it controls
                               {120, 120, 120, "button2"},
                               {140, 120, 100, 35});
    
    slider1 = m.addChildToView(panel1, new SliderFloat(),
                                    &(*testArray.begin()),
                                    {0, 1, "slider 1"},
                                    {20, 220, 220, 35});
    
    textField1 = m.addChildToView(panel1, new PlainTextField(),
                                       &testString,
                                       {},
                                       {20, 270, 220, 35});
    
    // TODO: there is a weird bug that makes these two widgets a part of the panel
    // even though they're added to the core murka view.
    header1 = m.addChildToView(/*panel1, */ new Header(),
                                   NULL,
                                   {"OOP Mode"},
                                   {10, 5, 260, 50});
    
    label1 = m.addChildToView(/*panel1, */ new Label(),
                                  NULL,
                                  {"Manually created widget graph"},
                                  {10, 55, 260, 50});
    
    
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

    m.drawCycle();
    
    if (b1->getResults() == true) ofLog() << "button 1 true!";
    if (b2->getResults() == true) ofLog() << "button 2 true!";
    

    ///////////////// Immediate mode with manual layout

    m.beginDrawingInView(&m);
    drawWidget<BlankPanel>(m, {"", booleanTest}, {650, 50, 260, 500});
    
    
    auto panelShape = m.getLatestChildShape(); // going to use this to resize widgets manually

    m.beginDrawingInLatestView();
    
    drawWidget<Header>(m, {"IM Mode"}, {20, 5,  panelShape.size.x - 40, 35});

    drawWidget<Label>(m, {"Manual IM mode layout"}, {20, 55,  panelShape.size.x - 40, 35});
    drawWidget<Checkbox>(m, &booleanTest, {"Moveable panel"}, {20, 85, panelShape.size.x - 40, 35});
    
    drawWidget<SliderFloat>(m, &(*testArray.begin()), {"slider 2"}, {20, 120, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 1)), {"slider 3"}, {20, 160, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 2)), {"slider 4"}, {20, 200, panelShape.size.x - 40, 35});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 3)), {"slider 5"}, {20, 240, panelShape.size.x - 40, 35});

    if (drawWidget<Button>(m, {"im button"}, {20, 280, panelShape.size.x - 40, 35})) {
        ofLog() << "im button pressed";
    }

    drawWidget<PlainTextField>(m, &testString, false, {20, 330, panelShape.size.x - 40, 35});
    
    drawWidget<DraggableNumberEditor>(m, &numberEditorTest, {4, 800.0, 8000.0}, {20, 420, panelShape.size.x - 40, 35});
    
    
    ///////////////// Immediate mode with automatic layout
    
    
    m.beginDrawingInView(&m);
    drawWidget<BlankPanel>(m, {"", true, 261, 400}, {50, 50, 261, 551});
    
    m.beginDrawingInLatestView();
    
    drawWidget<Header>(m, {"IM Autolayout"}, {20, 5,  260, 35});
    
    m.setLayoutLinearOffset(60); // This is a current offset from the top.
                                 // You can set it manually at any time if you need
                                 // to use custom layout for parts of the UI and
                                 // the auto layout for the rest of it.
    
    
    m.setCurrentLayoutStructure({{100, ALIGN_LEFT}, 1.0});
    drawWidget<SliderFloat>(m, &(*testArray.begin()), {"s1"});
    drawWidget<Label>(m, {"100 pix wide slider", TEXT_CENTER});
    
    m.setCurrentLayoutStructure({{0.5, ALIGN_LEFT}, 1.0});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 1)), {"s2"});
    drawWidget<Label>(m, {"0.5 wide slider", TEXT_CENTER});

    m.setCurrentLayoutStructure({1.0});
    drawWidget<Label>(m, {"3 widgets equally distributed", TEXT_CENTER});

    m.setCurrentLayoutStructure({0.33, 0.5, 1.0});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 1)), {"1"});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 2)), {"2"});
    drawWidget<SliderFloat>(m, &(*(testArray.begin() + 3)), {"3"});
    
    m.setLayoutLineHeight(35);

    m.setCurrentLayoutStructure({1.0});
    drawWidget<PlainTextField>(m, &testString, false);
    
    m.setCurrentLayoutStructure({1.0});
    drawWidget<DraggableNumberEditor>(m, &numberEditorTest, {4, 800.0, 8000.0});

    if (drawWidget<Button>(m, {"autolayout im button"})) {
        ofLog() << "autolayout im button pressed";
    }

    m.setLayoutLineHeight(200);
    drawWidget<NestedViewTest>(m, &pointsTest, {});

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
