#pragma once

#include "Murka.h"
#include "MurkaBasicWidgets.h"

using namespace murka;

class NestedViewTest : public MurkaViewInterface<NestedViewTest> {
public:
    NestedViewTest() {
        draw = [&](void* dataToControl,
                   void* parametersObject,
                   void* thisWidgetObject,
                   MurkaContext & context,
                   void* resultObject)  {
            
            auto params = (Parameters*)parametersObject;
            NestedViewTest* thisWidget = (NestedViewTest*)thisWidgetObject;
            auto data = (std::vector<std::pair<float, float>>*)dataToControl;
            
            bool inside = context.isHovered();
            bool trueInside = context.isHovered() * !areChildrenHovered(context);
            
            
            ofSetColor(200);
            int gridsize = 20;
            for (int i = 0; i < int(shape.size.x / gridsize) + 1; i++) {
                ofDrawLine(i * gridsize, 0, i * gridsize, shape.size.y);
            }
            for (int j = 0; j < int(shape.size.y / gridsize) + 1; j++) {
                ofDrawLine(0, j * gridsize, shape.size.x, j * gridsize);
            }
            
            layoutGenerator.setLayoutStructure({0.5, {30, ALIGN_RIGHT}});
            
            context.transformTheRenderBackFromThisContextShape();
            drawWidget<Label>(context, {!inside? "Try hovering!" : "See??"});

            if (inside) {
                if (drawWidget<Button>(context, {"?"})) {
                    ofLog() << "woah this works";
                }
            }

            context.transformTheRenderIntoThisContextShape();
        };
    }
    
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
