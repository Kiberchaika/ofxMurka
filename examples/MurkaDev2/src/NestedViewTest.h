#pragma once

#include "Murka.h"
#include "MurkaBasicWidgets.h"

using namespace murka;

class NestedViewTest : public MurkaViewInterface<NestedViewTest> {
public:
    NestedViewTest() {
        }
    
    MURKA_VIEW_DRAW_FUNCTION  {
        
        auto params = (Parameters*)parametersObject;
        NestedViewTest* thisWidget = (NestedViewTest*)thisWidgetObject;
        auto data = (std::vector<std::pair<float, float>>*)dataToControl;
        
        bool inside = context.isHovered();
        bool trueInside = context.isHovered() * !areInteractiveChildrenHovered(context);
        
        
        ofSetColor(200);
        int gridsize = 20;
        for (int i = 0; i < int(shape.size.x / gridsize) + 1; i++) {
            ofDrawLine(i * gridsize, 0, i * gridsize, shape.size.y);
        }
        for (int j = 0; j < int(shape.size.y / gridsize) + 1; j++) {
            ofDrawLine(0, j * gridsize, shape.size.x, j * gridsize);
        }
        
        layoutGenerator.setLayoutLineHeight(30);
        layoutGenerator.setLayoutStructure({0.5, {30, ALIGN_RIGHT}});
        
        drawWidget<Label>(context, {!inside? "Try hovering!" : "See??"});

        if (inside) {
            if (drawWidget<Button>(context, {"?"})) {
                ofLog() << "woah this works";
            }
        }

        if (drawWidget<Button>(context, {"Dynamic button 1"}, {100 * sin(ofGetElapsedTimef() * 3), 100 * sin(ofGetElapsedTimef() * 2), 150, 75})) {
            ofLog() << "woah this works";
        }

        if (drawWidget<Button>(context, {"Dynamic button 2"}, {100 * sin(ofGetElapsedTimef() * 3) + context.getSize().x - 100, 100 * sin(ofGetElapsedTimef() * 2) + context.getSize().y - 100, 150, 75})) {
            ofLog() << "woah this works";
        }

        if (trueInside) {
            context.addOverlay([&]() {
                drawWidget<Label>(context, {
                    ofToString(context.mousePosition.x, 0) + ":" + ofToString(context.mousePosition.y, 0),
                    {1., 1., 1.}, {0.,0.,0.,.5}},
                    {context.mousePosition.x / context.getUIScale(),
                     context.mousePosition.y / context.getUIScale() + 20 / context.getUIScale(),
                    75 * context.getUIScale(),
                    30 * context.getUIScale()});
            }, this);
        }
    };
    
    // Here go parameters and any parameter convenience constructors. You need to define something called Parameters, even if it's NULL.
    struct Parameters {
        float somevalue = 0.0;
        
        Parameters() {}
        Parameters(float someval) { somevalue = someval; } // a convenience initializer
    };
    
    // The results type, you also need to define it even if it's nothing.
    typedef bool Results;
    
    // The size that this widget wants if the layout generator asks for it.
    
    
    // The two functions needed for optional UI state saving. It's up to you
    // to use those.
//    std::vector<MurkaVar> saveInternalData(int indexX, int indexY) override { }
//    void loadInternalData(std::vector<MurkaVar>) override {}
    
    
    // Everything else in the class is for handling the internal state. It persist.
};
