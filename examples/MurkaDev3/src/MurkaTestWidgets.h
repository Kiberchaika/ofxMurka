#pragma once

#include "ofxMurka.h"

using namespace murka;

class RadioButtonGroup : public MurkaViewInterface<RadioButtonGroup> {
	bool isWantsClicks;

public:
	RadioButtonGroup() {
    }

    MURKA_VIEW_DRAW_FUNCTION {

        auto params = (Parameters*)parametersObject;
        RadioButtonGroup* thisWidget = (RadioButtonGroup*)thisWidgetObject;

        int* data = (int*)dataToControl;

        bool inside = context.isHovered() * !areChildrenHovered(context);

        isWantsClicks = false;

        auto font = context.getCurrentFont();

		context.pointerToRenderer->pushStyle();
        for (size_t i = 0; i < params->labels.size(); i++) {
			float offsetY = i * params->elementSize;

            bool active = false;
            if (inside) {
                MurkaShape shape;
                shape.position.x = 0;
                shape.position.y = offsetY;
                shape.size.x = params->elementSize;
                shape.size.y = params->elementSize;

                if (shape.inside(context.mousePosition)) {
                    active = true;
                    if (context.mouseDown) *data = i;
                }

            }
            if (active) isWantsClicks = true;

			context.pointerToRenderer->enableFill();
            if (*data == i) {
				context.pointerToRenderer->setColor(105);
            }
            else if (active) {
				context.pointerToRenderer->setColor(15);
            }
            else {
				context.pointerToRenderer->setColor(10);
            }
			context.pointerToRenderer->drawRectangle(1, 1 + offsetY, params->elementSize - 2, params->elementSize - 2);
			context.pointerToRenderer->setColor(255);
            font->drawString(params->labels[i], params->elementSize + 5, params->elementSize/2 - font->getLineHeight() / 2 + offsetY);
        }
		context.pointerToRenderer->popStyle();

        // Your drawing and interaction code goes here.
        // Don't forget that all of this executes at each frame for each
        // widget that is drawn on screen.
    };

	// Here go parameters and any parameter convenience constructors. You need to define something called Parameters, even if it's NULL.
	struct Parameters {
		vector<string> labels;
		float elementSize;

		Parameters() {}
		Parameters(vector<string> labels, float elementSize = 25) {
			this->labels = labels; this->elementSize = elementSize;
		} // a convenience initializer
	};

	// The results type, you also need to define it even if it's nothing.
	typedef bool Results;

	bool wantsClicks() {
		return isWantsClicks;
	}

	// The size that this widget wants if the layout generator asks for it.


	// The two functions needed for optional UI state saving. It's up to you
	// to use those.
	// std::vector<MurkaVar> saveInternalData(int indexX, int indexY) override { }
	// void loadInternalData(std::vector<MurkaVar>) override {}


	// Everything else in the class is for handling the internal state. It persist.
};

