#pragma once

#include "ofMain.h"
#include "ofxMurka.h"
#include "MurkaSurface.h"

using namespace murka;

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
		
    Murka m;
    
    struct TreeNode {
        vector<TreeNode> childNodes;
        string name;
    };
    
    vector<TreeNode> treeNodes;
    
    class TreeNodeView: public MurkaViewInterface<TreeNodeView>, public MurkaSurface {
    public:
        TreeNodeView() {
            draw = [&](void* dataToControl,
                       void* parametersObject,
                       void* thisWidgetObject,
                       const MurkaContext & context,
                       void* resultObject)  {

                           auto params = (Parameters*)parametersObject;
                           TreeNodeView* thisWidget = (TreeNodeView*)thisWidgetObject;

                           bool inside = context.isHovered() * !areChildrenHovered(context);
                           wasInsideLastFrame = inside;

                           // Your drawing and interaction code goes here.
                           // Don't forget that all of this executes at each frame for each
                           // widget that is drawn on screen.
                            
                           surfaceUpdate(context);
                
                           ofSetColor(255);
                           drawDebugGrid();
                           auto font = context.getMonospaceFont();
                           font->drawString("tree node view, nodes: " + ofToString(params->treeNodes.size()), 0, 20);


                           panLimits = {0, 0, 0, 500};
                       };
        }
        
        void pointerDownCallback() override {
                ofLog() << "clickd from child";
        }
        
        
        struct Parameters {
            vector<TreeNode> treeNodes;
        };
        
        // Surface callbacks
        
        virtual bool isAnythingSelected() override {
            return selectedItems.size() == 0;
        };
        
        virtual bool scrollwheelShouldZoom() override {
            return false;
        }
        
        virtual bool scrollwheelShouldPan() override {
            return true;
        }

        vector<int> selectedItems;
        
        bool wasInsideLastFrame = false;
    };
    
    /////////////
    
    struct NodeViewNode {
        string name;
        MurkaPoint position = {0, 0}, size = {100, 100};
        vector<int> connections;
    };
    
    vector<NodeViewNode> nodeViewNodes;
    
    class NodeView: public MurkaViewInterface<NodeView>, public MurkaSurface {
    public:
        
        NodeView() {
            draw = [&](void* dataToControl,
                       void* parametersObject,
                       void* thisWidgetObject,
                       const MurkaContext & context,
                       void* resultObject)  {

                           auto params = (Parameters*)parametersObject;
                           NodeView* thisWidget = (NodeView*)thisWidgetObject;
                
                           bool inside = context.isHovered() * !areChildrenHovered(context);
                           wasInsideLastFrame = inside;

                           auto transformedPointer = getTransformedPointerPosition(context.mousePosition);

                            
                           surfaceUpdate(context);
                
                           ofSetColor(255);
                           drawDebugGrid();
                            ofPushMatrix();
                                ofTranslate(-panOffset.x, -panOffset.y);
                                ofScale(scale);

                                int index = 0;
                                wasHoveringNodeLastFrame = false;
                                for (auto node: params->nodeViewNodes) {
                                    bool insideNode = MurkaShape(node.position.x,
                                                                 node.position.y,
                                                                 node.size.x,
                                                                 node.size.y)
                                                        .inside(transformedPointer);
                                    
                                    if (insideNode) {
                                        wasHoveringNodeLastFrame = true;
                                        nodeThatHoveredLastFramesIndex = index;
                                        hoveredNodeInternalOffset = transformedPointer - MurkaPoint(node.position.x, node.position.y);
                                        hoveredNodePosition = {node.position.x, node.position.y};
                                    }
                                    
                                    ofSetColor(100 + 70 * insideNode);
                                    ofFill();
                                    ofDrawRectangle(node.position.x,
                                                    node.position.y,
                                                    node.size.x,
                                                    node.size.y);
                                    ofSetColor(200);
                                    ofNoFill();
                                    ofDrawRectangle(node.position.x,
                                                    node.position.y,
                                                    node.size.x,
                                                    node.size.y);
                                    
                                    ofFill();
                                    
                                    index ++;
                                }
                
                            ofPopMatrix();
                           auto font = context.getMonospaceFont();
                           font->drawString("node view, nodes: " + ofToString(params->nodeViewNodes.size()), 0, 20);

                            if (draggingANodeNow.draggingNodeNow) {
                                params->nodeViewNodes[draggingANodeNow.index].position = draggingANodeNow.nodeStartingPosition - draggingData.widgetSpaceDelta / scale;
                                auto pp = params->nodeViewNodes[draggingANodeNow.index].position;
                            }

                           lastFrameDataPointer = &(params->nodeViewNodes);


                       };
        }
        
        void pointerDownCallback() override {
                ofLog() << "clickd from child";
        }
        
        
        struct Parameters {
            vector<NodeViewNode> & nodeViewNodes;
        };
        
        vector<NodeViewNode>* lastFrameDataPointer;
        
        // Surface callbacks
        
        virtual void dragUpdate(DragContext & c) override {
        }
        
        struct {
            bool draggingNodeNow = false;
            int index = 0;
            MurkaPoint internalOffset = {0, 0};
            MurkaPoint nodeStartingPosition = {0, 0};
        } draggingANodeNow;
        
        virtual void pointerUpCallback() override {
            if (draggingANodeNow.draggingNodeNow) {
                draggingANodeNow.draggingNodeNow = false;
            }
        }

        virtual bool clickShouldStartPanning() override {
            if (wasHoveringNodeLastFrame) {
                ofLog() << "starting node dragging...";
                draggingANodeNow.draggingNodeNow = true;
                draggingANodeNow.index = nodeThatHoveredLastFramesIndex;
                draggingANodeNow.nodeStartingPosition = hoveredNodePosition;
                
            } else {
                ofLog() << "pan started...";
                return true; // starting pan
            }
        }
        
        virtual bool scrollwheelShouldZoom() override {
            if (!ofGetKeyPressed(OF_KEY_CONTROL)) // don't zoom with scrollwheel if control pressed
                return true;
            else return false;
        }
        
        virtual bool scrollwheelShouldPan() override {
            if (ofGetKeyPressed(OF_KEY_CONTROL)) // don't pan with scrollwheel if ctrl pressed
                return false;
            else return true;
        }
        
        virtual bool isAnythingSelected() override {
            return selectedItems.size() == 0;
        };
        
        vector<int> selectedItems;
        bool wasInsideLastFrame = false;
        bool wasHoveringNodeLastFrame = false;
        int nodeThatHoveredLastFramesIndex = 0;
        MurkaPoint hoveredNodeInternalOffset = {0, 0};
        MurkaPoint hoveredNodePosition = {0, 0};
    };
    
    ///////////////////////////
    
    struct PlotterElement {
        MurkaPoint position = {0, 0};
        MurkaColor color = {0, 0, 0};
        
        PlotterElement() {}
    };
    
    vector<PlotterElement> plotterElements;
    
    class PlotterView: public MurkaViewInterface<PlotterView>, public MurkaSurface {
    public:
        PlotterView() {
            draw = [&](void* dataToControl,
                       void* parametersObject,
                       void* thisWidgetObject,
                       const MurkaContext & context,
                       void* resultObject)  {

                           auto params = (Parameters*)parametersObject;
                           PlotterView* thisWidget = (PlotterView*)thisWidgetObject;

                           bool inside = context.isHovered() * !areChildrenHovered(context);
                           wasInsideLastFrame = inside;
                
                           auto transformedPointer = getTransformedPointerPosition(context.mousePosition);

                           surfaceUpdate(context);
                
                           ofSetColor(255);
                           drawDebugGrid();
                
                            ofPushMatrix();
                                ofTranslate(-panOffset.x, -panOffset.y);
                                ofScale(scale);
                                for (auto element: params->plotterElements) {
                                    
                                    bool insideElement =
                                        MurkaShape(element.position.x  - 10,
                                                   element.position.y  - 10,
                                                   20, 20)
                                                .inside(transformedPointer);
                                    
                                    if (insideElement) {
                                        ofSetColor(element.color * 255);
                                        ofDrawCircle(element.position.x, element.position.y, 15);
                                    } else {
                                        ofSetColor(element.color * 100, 100);
                                        ofDrawCircle(element.position.x, element.position.y, 15);
                                    }
                                }
                            ofPopMatrix();
                
                           auto font = context.getMonospaceFont();
                           font->drawString("plotter view, elements: " + ofToString(params->plotterElements.size()), 0, 20);


                       };
        }
        
        void pointerDownCallback() override {
                ofLog() << "clickd from child";
        }
        
        
        struct Parameters {
            vector<PlotterElement> plotterElements;
        };
        
        // Surface callbacks
        
        virtual bool clickShouldStartPanning() override {
            ofLog() << "pan started...";
            return true; // always pan on click
        }
        
        virtual bool scrollwheelShouldZoom() override {
            if (ofGetKeyPressed(OF_KEY_SHIFT))
                return true;
            else return false;
        }
        
        virtual bool scrollwheelShouldPan() override {
            if (ofGetKeyPressed(OF_KEY_SHIFT))
                return false;
            else return true;
        }
        virtual bool isAnythingSelected() override {
            return selectedItems.size() == 0;
        };
        
        vector<int> selectedItems;
        
        bool wasInsideLastFrame = false;

    };
};
