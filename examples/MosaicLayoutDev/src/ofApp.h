#pragma once

#include "ofMain.h"
#include "ofxMurka.h"

#include "MosaicLayoutPureFunctional.h"
#include "MosaicLayoutStateful.h"

class ofApp : public ofBaseApp, public MurkaAnimator {

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
	
    Murka m;
    
    std::vector<MurkaShape> debugShapesNew;
    std::vector<MurkaPoint> objects;
    bool shouldAddNextDebugShape = false;

    int currentDepth = 40;
    int drawingNow = 400;
    

    MosaicLayoutPureFunctional mosaicLayout1;
    MosaicLayoutStateful mosaicLayout2;
    MosaicLayout mosaicLayout3;
    
    double distanceNorm = 0;
    
    double getOverlapFactor(vector<MurkaShape> shapes) {
        double sumOverlapArea = 0;
        double sumArea = 0;
        for (auto &i: shapes) {
            for (auto &j: shapes) {
                if (i != j) {
                    sumOverlapArea += overlapArea(i, j);
                }
            }
            sumArea += i.size.x * i.size.y;
        }
        
        return sumOverlapArea / sumArea;
    }

    
    float overlapArea(MurkaShape s1, MurkaShape s2) {
     
        double left = max(s1.position.x, s2.position.x);
        double right = min(s1.position.x + s1.size.x, s2.position.x + s2.size.x);
        double bottom = min(s1.position.y + s1.size.y, s2.position.y + s2.size.y);
        double top = max(s1.position.y, s2.position.y);

        if ((left < right) && (top < bottom)) {
            return (right - left) * (bottom - top);
        } else return 0;
    }
};
