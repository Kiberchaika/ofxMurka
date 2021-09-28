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
 
    
}

//--------------------------------------------------------------
void ofApp::createChildren(){

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    animationRestart();

	ofClear(10);


	auto time = ofGetElapsedTimef();


	// Initial drawing and setup & object-oriented mode

	m.setFont("Roboto-Regular.ttf", 12);



	m.begin();

    m.setColor(220, 220, 220, 255);
    m.setColor(220, A(hoveredLabel) * 220, A(hoveredLabel) * 220);
//    ofSetColor(220, A(hoveredLabel) * 220, A(hoveredLabel) * 220);
    
    /*
    drawWidget_NEW<Label>(m, { 50, 50, 300, 50 })
        .text("time passed: " + std::to_string(ofGetElapsedTimef()) + " ; hovered ? " + (hoveredLabel ? " yes " : " no "))
        .onHoverChange([&](Label& l) {
            hoveredLabel = l.isHovered;
        })
        .onClick([&](Label& l) {
            ofLog() << "clicked!";
        });
    */
    
    // 1. Унаследовать контекст от рендерера? Чтобы вызывать рендеринг из виджетов не обращаясь к указателю на рендер.  Вердикт: не вйыдет. Передавать указатель на рендер в internalDraw.
//      + вынести Renderer из наследников объекта Murka в отдельный объект, чтобы рисование внутри виджетов и в самой программе было устроено одинаково.
    // 2. Добавить такую же функцию draw контексту? Зачем?
    // 3. Решить с цветом. 255 или 1? 1.
    // 4. resetKeyboardFocus когда вьюшка пропала.
    
    // И ещё:
    // 5. Параметры у коллбэков внутри виджетов?

    m.draw<Label>({ 50, 50, 300, 50 })
        .text("time passed: " + std::to_string(ofGetElapsedTimef()) + " ; hovered ? " + (hoveredLabel ? " yes " : " no "))
        .onHoverChange([&](Label& l) {
            hoveredLabel = l.isHovered;
        })
        .onClick([&](Label& l) {
            ofLog() << "clicked!";
        })
        .onClickPosition([&](Label &l, MurkaPoint p) {
            ofLog() << "clicked! callback arguments: " << p.x << " ; " << p.y;
        });
    
    m.currentContext.commitDeferredView();
    
    

//    drawWidget_NEW<ReticleGrid>(m, { 50, 50, 200, 50 })
//        .setBackgroundColor(200, 0, 200)
//        .controlYPR(&ypr);
    
    
    auto ffont = m.getCurrentFont();

    // Commit deferred view calls the base class draw() instead of derived one. Fix this somehow.
 
 
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
