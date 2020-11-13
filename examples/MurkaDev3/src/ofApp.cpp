#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Murka setup
	m.setRenderer(ofGetGLRenderer().get());
	m.setWindow(ofGetWindowPtr());
    m.setResourcesPath(ofToDataPath(""));

    //
    m.shape = {0, 0, ofGetWidth(), ofGetHeight()};
    m.setScreenScale(screenScale);

//    createChildren();
    
}

//--------------------------------------------------------------
void ofApp::createChildren(){
    /*
    panel1 = m.addChildToView(new BlankPanel(),
                                   nullptr,
                                   {"panel1", true},
                                   {350, 50, 260, 500});
    
    rb = m.addChildToView(panel1, new RadioButtonGroup(),
        &radioRata, // the data it controls
        { { "test1", "test2" } },
        { 20, 120, 100, 100 });
    
    b1 = m.addChildToView(panel1, new Button(),
                               nullptr, // the data it controls
                               {"button1"},
                               {20, 220, 100, 35});

    b2 = m.addChildToView(panel1, new Button(),
                               nullptr, // the data it controls
                               {120, 220, 120, "button2"},
                               {140, 220, 100, 35});
    
    slider1 = m.addChildToView(panel1, new SliderFloat(),
                                    &(*testArray.begin()),
                                    {0, 1, "slider 1"},
                                    {20, 320, 220, 35});
    
    textField1 = m.addChildToView(panel1, new TextField(),
                                       &testString,
                                       {},
                                       {20, 370, 220, 35});
    
*/
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofClear(10);


	auto time = ofGetElapsedTimef();


	// Initial drawing and setup & object-oriented mode

	m.setFont("Roboto-Regular.ttf", 12);



	m.begin();

    m.setColor(220, 220, 220, 255);
	drawWidget_NEW<Label>(m, { 50, 50, 200, 50 })
        .label = "time passed: " + std::to_string(ofGetElapsedTimef());
    
    m.getCurrentFont()->drawString("gggg", 5, 100);

    // Commit deferred view calls the base class draw() instead of derived one. Fix this somehow.
    m.currentContext.commitDeferredView();
    
    /*
    Label::purr(m, { 50, 50, 200, 50 })
        .label = "yo";
    
    Label().draw3(m, { 50, 50, 200, 50 });
//    commit();
     */
     
    
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
