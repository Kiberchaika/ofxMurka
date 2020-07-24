#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    m.setupFonts("Roboto-Regular.ttf", 12,
                 "Roboto-Regular.ttf", 20,
                 "Roboto-Regular.ttf", 12);
    
    m.setRenderer(ofGetGLRenderer().get());
    
//    m.setupRenderer(ofGLRenderer* r);
//    m.setupRenderer(ofGetGLRenderer());
    
     
     
    // Test...
    
    double time = ofGetElapsedTimef();
    
    int overlapTestCount = 100;
    double testOverlap = 0;
    
    for (int i = 0; i < overlapTestCount; i++) {
        vector<MurkaShape> testShapes;
        
        objects.clear();

        mosaicLayout1.restart();
        
        for (int i = 0; i < 35; i++) {
            objects.push_back(MurkaPoint(300 + ofRandom(15),
                                         300 + ofRandom(15)));
            MurkaShape t = {objects.back(), {ofRandom(35), ofRandom(30)}};
            
            testShapes.push_back(mosaicLayout1.findBetterPlaceWithDepth(t, 20));
        }
        
        testOverlap += getOverlapFactor(testShapes);
    }
    
    testOverlap /= double(overlapTestCount);
    
    ofLog() << ";;;;;;;;;;;;;;;;;;;;;;;;";
    ofLog() << "    test result: " << testOverlap;
    ofLog() << "    time : " <<  ofGetElapsedTimef() - time;
    ofLog() << ";;;;;;;;;;;;;;;;;;;;;;;;";

    
    time = ofGetElapsedTimef();
    
    for (int i = 0; i < overlapTestCount; i++) {
        vector<MurkaShape> testShapes;
        
        objects.clear();

        mosaicLayout3.restart();
        
        for (int i = 0; i < 35; i++) {
            objects.push_back(MurkaPoint(300 + ofRandom(15),
                                         300 + ofRandom(15)));
            MurkaShape t = {objects.back(), {ofRandom(35), ofRandom(30)}};
            
            testShapes.push_back(mosaicLayout3.fit(t, 25, 5, 3));
        }
        
        testOverlap += getOverlapFactor(testShapes);
    }
    
    testOverlap /= double(overlapTestCount);
    
    ofLog() << ";;;;;;;;;;;;;;;;;;;;;;;;";
    ofLog() << "    test 2 result: " << testOverlap;
    ofLog() << "    time : " << ofGetElapsedTimef() - time;
    ofLog() << ";;;;;;;;;;;;;;;;;;;;;;;;";
    
     
     
    objects.clear();
    for (int i = 0; i < 100; i++) {
         objects.push_back(MurkaPoint(0 + ofRandom(75),
                                      0 + ofRandom(75)));
    }
      
     

     

    /*
    mosaicLayout2.findBetterPlaceWithDepth({100, 100, 30, 30});
    mosaicLayout2.findBetterPlaceWithDepth({100, 100, 30, 30});
    mosaicLayout2.restart();

    mosaicLayout2.findBetterPlaceWithDepth({100, 100, 30, 30});
    mosaicLayout2.findBetterPlaceWithDepth({100, 100, 30, 30});
    mosaicLayout2.restart();
     */


//    mosaicLayout1.thisFrameShapes.push_back({150, 200, 100, 400});
//    mosaicLayout1.thisFrameShapes.push_back({400, 200, 400, 100});
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(50);
    
    double time = ofGetElapsedTimef();
    
    debugShapesNew.resize(objects.size());
    
    animationRestart();
    
    mosaicLayout1.restart();
    mosaicLayout2.restart();
    mosaicLayout3.restart();
    
    distanceNorm = 0;
    
    bool debugShouldStopNext = false;
    
    m.begin();

    
        int index = 0;
        for (auto circle: objects) {
            
            auto circle2 = circle + MurkaPoint(ofGetMouseX(), ofGetMouseY());
            
            ofSetColor(200, 0, 0);
            ofDrawCircle(circle2.x, circle2.y, 3);
            std::string label = std::to_string(int(pow(index, 1)));
            auto w = m.paragraphFont->getStringBoundingBox(label, 0, 0).width + 10;
            
            MurkaShape inputLabelShape = {circle2.x - w / 2, circle2.y - 30, w, 30};
            MurkaShape improvedShape;
            
            if (!ofGetKeyPressed('1')) {
                mosaicLayout3.outerBounds.size = {static_cast<float>(ofGetWidth()), static_cast<float>(ofGetHeight())};
                improvedShape = mosaicLayout3.fit(inputLabelShape, currentDepth);
                
                distanceNorm += (inputLabelShape.position - improvedShape.position).length();
            } else {
                improvedShape = mosaicLayout1.findBetterPlaceWithDepth(inputLabelShape, currentDepth);
                
                distanceNorm += (inputLabelShape.position - improvedShape.position).length();
            }
            
            auto animation = A((ofGetMouseX() > 0) && (ofGetMouseY() > 0) && (ofGetMouseX() < ofGetWidth()) && (ofGetMouseY() < ofGetHeight()));
            
            animation = 1;
            
            MurkaShape drawingShape = {inputLabelShape.position.x * (1 - animation) + improvedShape.position.x * animation,
                inputLabelShape.position.y * (1 - animation) + improvedShape.position.y * animation,
                inputLabelShape.size.x * (1 - animation) + improvedShape.size.x * animation,
                inputLabelShape.size.y * (1 - animation) + improvedShape.size.y * animation
                };
            
            debugShapesNew[index] = drawingShape;
            
            if (drawingShape.inside(MurkaPoint(ofGetMouseX(), ofGetMouseY()))) {
                double overlapFactor = 0;
                int index2 = 0;
                for (auto second: debugShapesNew) {
                    if (second != drawingShape) {
                        auto oArea = overlapArea(drawingShape, second);
                        if (oArea > 0) {
                            overlapFactor += oArea;
                        }
                    }
                    
                    index2++;
                }
                
            }

            ofSetColor(150, 0, 0, 100);
            ofDrawLine(drawingShape.position.x,
                       drawingShape.position.y,
                       circle2.x,
                       circle2.y);
            ofDrawLine(drawingShape.position.x + drawingShape.size.x,
                       drawingShape.position.y,
                       circle2.x,
                       circle2.y);
            ofDrawLine(drawingShape.position.x + drawingShape.size.x,
                       drawingShape.position.y + drawingShape.size.y,
                       circle2.x,
                       circle2.y);
            ofDrawLine(drawingShape.position.x,
                       drawingShape.position.y + drawingShape.size.y,
                       circle2.x,
                       circle2.y);

            if (drawingShape.size.length() > 5) {
                ofSetColor(0, 120);
                ofDrawRectangle(drawingShape);
                drawWidget<Label>(m, {label}, drawingShape);
            }
            
            index++;
        }
     
         
        
        /*
        ofNoFill();
        ofSetColor(100, 200);
        for (auto shape: debugShapes) {
            ofDrawRectangle(shape);
        }
    
        MurkaShape myTargetShape = {ofGetMouseX() - 100, ofGetMouseY() - 50, 200, 75};
    
        ofFill();
        auto newShape = findBetterPlaceWithDepth(myTargetShape, currentDepth);
        ofDrawRectangle(newShape);
    
        if (shouldAddNextDebugShape) {
            shouldAddNextDebugShape = false;
            debugShapes.push_back(newShape);
        }
    
        ofNoFill();
        ofSetColor(0, 130, 20);
        ofDrawRectangle(myTargetShape);
         */

        /*
        if (debugPath.size() > 1) {
            ofLog() << "sss:::" << debugPath.size();
            for (int i = 0; i < debugPath.size() - 1; i++) {
                ofSetColor(255, 0, 255);
                ofDrawLine(debugPath[i].x(), debugPath[i].y(),
                           debugPath[i + 1].x(), debugPath[i + 1].y());
            }
        }
         */
  
        /*
        ofSetColor(0, 0, 100);
        auto intersectionVector = getMaxOverlappingVector(myTargetShape);
        MurkaPoint centroid = {myTargetShape.position.x + myTargetShape.size.x / 2,
                               myTargetShape.position.y + myTargetShape.size.y / 2};
        ofDrawLine(centroid.x + intersectionVector.x,
                   centroid.y,
                   centroid.x,
                   centroid.y);
        ofDrawLine(centroid.x,
                   centroid.y + intersectionVector.y,
                   centroid.x,
                   centroid.y);
         
        ofSetColor(200, 50, 50);
        ofDrawRectangle(latestBiggestIntersectionDebug);
         */
        
//        ofLog() << myTargetShape.intersectsWithRectangle(shape1);
    
        drawWidget<Label>(m, {"current depth:" + std::to_string(currentDepth)}, {50, 50, 150, 30});
        drawWidget<Label>(m, {"drawing now:" + std::to_string(drawingNow)}, {50, 80, 150, 30});

        double overlapFactor = getOverlapFactor(debugShapesNew);
        drawWidget<Label>(m, {"overlap factor:" + std::to_string(overlapFactor)}, {50, 110, 150, 30});
        drawWidget<Label>(m, {"distance norm:" + std::to_string(distanceNorm)}, {50, 130, 150, 30});
        drawWidget<Label>(m, {"x: " + std::to_string(ofGetMouseX()) + " ; y:" + std::to_string(ofGetMouseY())}, {50, 170, 150, 30});

    m.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'k') {
        auto size = objects.size();
        objects.clear();
        for (int i = 0; i < size; i++) {
            objects.push_back(MurkaPoint(0 + ofRandom(5),
                                         0 + ofRandom(5)));
        }
    }
    if (key == 'j') {
        objects.clear();
        for (int i = 0; i < 400; i++) {
            objects.push_back(MurkaPoint(ofRandom(ofGetWidth()),
                                        ofRandom(ofGetHeight())));
        }
    }
    if (key == OF_KEY_UP) currentDepth ++;
    if (key == OF_KEY_DOWN) currentDepth --;
    if (key == OF_KEY_LEFT) drawingNow --;
    if (key == OF_KEY_RIGHT) drawingNow ++;
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
    shouldAddNextDebugShape = true;
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
