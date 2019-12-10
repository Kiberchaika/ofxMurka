#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    m.setupFonts("Roboto-Regular.ttf", 12,
                 "Roboto-Regular.ttf", 20,
                 "CamingoCode-Regular.ttf", 12);
    
    // Dummy data
    
    // Tree view data
    
    for (int i = 0; i < 25; i++) {
        treeNodes.push_back(TreeNode());
        treeNodes.back().name = "node " + ofToString(ofRandom(255));
        if (ofRandom(100) > 90) {
            for (int j = 0; j < 5; j++) {
                treeNodes.back().childNodes.push_back(TreeNode());
                treeNodes.back().childNodes.back().name = "child node " + ofToString(ofRandom(255));
            }
        }
    }
    
    // Node view data
    
    for (int i = 0; i < 1; i++) {
        nodeViewNodes.push_back(NodeViewNode());
        nodeViewNodes.back().position = {150 * float(i), 100};
        nodeViewNodes.back().name = "node " + ofToString(ofRandom(200));
    }
    
    // Plotter view data
    
    for (int i = 0; i < 500; i++) {
        plotterElements.push_back(PlotterElement());
        plotterElements.back().position = {ofRandom(0, 500),
            ofRandom(0, 500)};
        plotterElements.back().color = {ofRandomuf(), ofRandomuf(), ofRandomuf()};
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    m.begin();
    
    drawWidget<TreeNodeView>(m, {treeNodes}, {0, 0, float(ofGetWidth() / 2.0), float(ofGetHeight() / 2.0)});
    drawWidget<NodeView>(m, {nodeViewNodes}, {float(ofGetWidth() / 2.0), 0, float(ofGetWidth() / 2.0), float(ofGetHeight() / 2.0)});
    drawWidget<PlotterView>(m, {plotterElements}, {float(ofGetWidth() / 2.0), float(ofGetHeight() / 2.0), float(ofGetWidth() / 2.0), float(ofGetHeight() / 2.0)});

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
