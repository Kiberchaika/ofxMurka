#pragma once

#include "ofMain.h"
#include "ofxLiveApp.h"
#include "ofxMurka.h"


class ofApp : public ofxLiveApp {

	public:
		void setup();
		void update();
		void draw();

		void reinit() override;

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

		MurkaWidgetButton b = { "ok", // label
		[]() {
			ofLog() << "alright, clicked on it...";
		}, // button press callback
		{100, 100, 75, 25} // shape on screen
		};

		MurkaWidgetTypeInt m1;
		MurkaWidgetTypeFloat m2;
};
