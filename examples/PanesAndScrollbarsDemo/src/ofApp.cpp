#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	m.setRenderer(ofGetGLRenderer().get());
	m.setupFonts("Roboto-Regular.ttf", 12,
                 "Roboto-Regular.ttf", 20,
                 "Roboto-Regular.ttf", 12,
				 false);
    

    panes[0] = PaneInfo();
    panes[0].position = 0.5;
    panes[1] = PaneInfo();
    panes[1].position = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(50);
    
    double time = ofGetElapsedTimef();
    
	m.begin();

	Pane::Parameters paneParameters;
	paneParameters.firstPanelDraw = [&](MurkaContext& c) {

		drawWidget<Pane>(c, &(panes[1].position),
			{ [&](MurkaContext& g) {
			g.renderer->setColor(0, 90, 90);
			g.renderer->drawRectangle(10, 10, g.getSize().x - 20, g.getSize().y - 20);
			drawWidget<TestSurface>(g, {}, {0, 0, g.getSize().x, g.getSize().y});
			},
			[&](MurkaContext& g) {
			g.renderer->setColor(90, 0, 110);

			g.renderer->pushStyle();
			g.renderer->disableFill();
			g.renderer->drawRectangle(30, 30, g.getSize().x - 60, g.getSize().y - 60);
			g.renderer->drawLine(0, 0, g.getSize().x, g.getSize().y);
			g.renderer->popStyle();

			drawWidget<TestSurface>(g, {}, {0, 0, g.getSize().x, g.getSize().y});
			},
			2 }, { 0, 0, c.getSize().x, c.getSize().y });
	};
	paneParameters.secondPanelDraw = [&](MurkaContext& c) {
		c.renderer->setColor(50, 90, 50);
		c.renderer->drawRectangle(10 + 10 * sin(time),
			10 + 10 * sin(time),
			c.getSize().x - 20 + 10 * sin(time),
			c.getSize().y - 20 + 10 * sin(time));

		drawWidget<TestSurface>(c, {}, { 0, 0, c.getSize().x, c.getSize().y });
	};
	paneParameters.kind = 1;

	drawWidget<Pane>(m, &(panes[0].position), paneParameters, { 0, 0, ofGetWidth(),ofGetHeight() });



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
