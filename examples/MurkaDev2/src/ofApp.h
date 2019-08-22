#pragma once

#include "ofMain.h"
//#include "ofxLiveApp.h"
#include "ofxMurka.h"


class ofApp : public ofBaseApp {

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
		
		Murka murka;

        MurkaWidgetButton b;
    
        MurkaViewHandler<MurkaWidgetButton>*  b1;
        MurkaViewHandler<MurkaWidgetButton>*  b2;
        MurkaViewHandler<MurkaSliderFloat>*  slider1;
        MurkaViewHandler<MurkaBlankPanel>* panel1;
    
    
    float TESTER, TESTER2;

    std::vector<float> testArray = {0, 0.3, 0.7, 3};
    std::string testString = "test";
    bool testBool = false;
};
