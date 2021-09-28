#pragma once

#include "ofMain.h"
//#include "ofxLiveApp.h"
#include "ofxMurka.h"

#include "Label.h"

#include "NestedViewTest.h"
#include "MurkaTestWidgets.h"

using namespace murka;

 
class ofApp : public ofBaseApp, public MurkaAnimator { // ofxLiveApp

	public:
		void setup();
		void update();
		void draw();

		//void reinit() override;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void createChildren();
		
		Murka m;
    
        bool hoveredLabel = false;
/*
        Button b;
    
		MurkaViewHandler<RadioButtonGroup>*  rb;
        MurkaViewHandler<Button>*  b1;
        MurkaViewHandler<Button>*  b2;
        MurkaViewHandler<SliderFloat>*  slider1;
        MurkaViewHandler<BlankPanel>* panel1;
        MurkaViewHandler<TextField>* textField1;
        MurkaViewHandler<Header>* header1;
        MurkaViewHandler<Label>* label1;
 */
    
    float screenScale = 1.0;
    
    float TESTER, TESTER2;

	int radioRata = -1;
    std::vector<float> testArray = {0, 0.3, 0.7, 3};
    std::string testString = "This is a text field!";
    std::string doubleClickAndCommentTestString = "";
    bool testBool = false;
    
    double numberEditorTest = 2000;
    
    bool booleanTest = true;
    
    std::vector<std::pair<float, float>> pointsTest;
};
