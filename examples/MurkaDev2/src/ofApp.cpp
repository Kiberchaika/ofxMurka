#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	murka.addChildToView(murka.getRootView(), &b, NULL);
    
//    b.Label = "aga";
//    b.menuList = {"x", "y", "z"};
    
    murka.addChildToView(murka.getRootView(), new MurkaWidgetButton("ok", // label
        []() {
            ofLog() << "alright, clicked on it...";
        }, // button press callback
        {100, 100, 75, 25} // shape on screen
    ), NULL);

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
    
    ofLog() << "!!!";

//    ofLog() << "calling draw cycle";
//    murka.drawCycle();
    
//    ofLog() << murka.children.size();
    
    MurkaContext m = MurkaContext();
    m.currentViewShape.position = {100, 100};
    m.currentViewShape.size = {100, 30};
    auto mm = murka.children.back();
    auto mmm = get<0>(mm);
    
    auto castedParametersObject = ((MurkaWidgetButton*)mmm);
    ofLog() << "label = " << castedParametersObject->Label;
    ofLog() << "real label = " << b.Label;
    
    auto draw2 = [](void* data, void* parametersObject, MurkaContext & context)->void* {
        auto castedParametersObject = ((MurkaWidgetButton*)parametersObject);
        ofLog() << "and now the label is " << castedParametersObject->Label;
        //            ofLog() << "calling the button draw...";

    };
    


    draw2(NULL, mmm, m);
    
    
    auto copiedDraw = b.draw;
//    copiedDraw(NULL, mmm, m);
//    b.draw(NULL, mmm, m);
    
    ofLog() << ";;;;";
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
