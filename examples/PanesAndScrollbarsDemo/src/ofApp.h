#pragma once

#include "ofMain.h"
#include "ofxMurka.h"
#include "Pane.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
	
    ////////
    
    struct PaneInfo {
        int kind = 0; // 0 = off
                      // 1 = horizontal
                      // 2 = vertical
                      
        double position = 0.5;
        
        // 4 indices of where to look for more internal panes in the map while we draw them
        int internalPane1Index = 0;
        int internalPane2Index = 0;
    };
    
    std::map<int, PaneInfo> panes;
    
    
    Murka m;
};
