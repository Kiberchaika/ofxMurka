#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    panel1 = murka.addChildToViewT(new MurkaBlankPanel(),
                                   NULL,
                                   {"panel1", true},
                                   {50, 50, 260, 500});
    
    
    b1 = murka.addChildToViewT(panel1, new MurkaWidgetButton(),
                               NULL, // the data it controls
                               {"button1"},
                               {20, 120, 100, 35});

    b2 = murka.addChildToViewT(panel1, new MurkaWidgetButton(),
                               NULL, // the data it controls
                               {120, 120, 120, "button2"},
                               {140, 120, 100, 35});
    
    slider1 = murka.addChildToViewT(panel1, new MurkaSliderFloat(),
                                    &TESTER,
                                    {0, 1, "slider 1"},
                                    {20, 220, 220, 35});
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(10);
    
    ofSetColor(255, 0, 0);
    
    auto time = ofGetElapsedTimef();
    
//    panel1->shape.position = {100 + 50 * sin(time * 5), 50};
    
    
    b1->tParams->b = sin(time * 10) * 100 + 100;
    
    

    murka.drawCycle();
    
    if (b1->getResults() == true) ofLog() << "button 1 true!";
    if (b2->getResults() == true) ofLog() << "button 2 true!";
    
//    ofLog() << *(b1->castResults(b1->resultsInternal));

    
        ///////////////// Immediate mode
        /*
        murka.beginDrawingInView(&murka);
        ofLog() << " 1 - context counter: " << murka.currentContext.getImCounter();
        MurkaBlankPanel::Parameters p = {350, 50, 260, "500"};
        MurkaBlankPanel::imDraw(murka, {"panel2", true}, {350, 50, 260, 500});
        ofLog() << " 1.5 - context counter: " << murka.currentContext.getImCounter();

    
        murka.beginDrawingInLatestView();
        MurkaSliderFloat::imDraw(murka, &TESTER, {"slider 2"}, {20, 120, 220, 35});
        MurkaSliderFloat::imDraw(murka, &TESTER2, {"slider 3"}, {20, 220, 220, 35});
        MurkaSliderFloat::imDraw(murka, &TESTER, {"slider 4"}, {20, 320, 220, 35});
        MurkaSliderFloat::imDraw(murka, &TESTER2, {"slider 5"}, {20, 420, 220, 35});
*/
//        MurkaViewInterface<MurkaSliderFloat>::Parameters pp;
//        MurkaSliderFloat::imDrawST2(murka.currentContext, &TESTER2, pp, {20, 420, 220, 35});
    
//        imDraw<MurkaSliderFloat>({"slider 6"});
//
    murka.beginDrawingInView(&murka);
    drawWidget<MurkaBlankPanel>(murka, {"panel6", true}, {750, 550, 260, 500});
    murka.beginDrawingInLatestView();
    drawWidget<MurkaSliderFloat>(murka, &TESTER, {"slider 8"}, {20, 120, 220, 50});
    
    murka.beginDrawingInView(&murka);
    drawWidget<MurkaSliderFloat>(murka, &TESTER, {"slider 9"}, {20, 240, 220, 50});

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
