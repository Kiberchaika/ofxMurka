#include "MurkaTypes.h"
#include "MurkaContext.h"
#include "MurkaView.h"
#include "MurkaInputEventsRegister.h"
#include "MurkaAssets.h"
#include "MurkaLinearLayoutGenerator.h"

using namespace murka;

class AnimationExampleWidget : public MurkaViewInterface<AnimationExampleWidget>{
public:
    MURKA_VIEW_DRAW_FUNCTION  {

        auto params = (Parameters*)parametersObject;
        auto results = (Results*)resultObject;
        bool inside = context.isHovered() * !areInteractiveChildrenHovered(context) * hasMouseFocus(context);

        int numSections = 5;
        float sectionWidth = context.getSize().x / float(numSections);
        for (int i = 0; i < numSections; i++) {
            ofRectangle section = {i * sectionWidth, 0, sectionWidth, context.getSize().y};
            bool sectionInside = section.inside(context.mousePosition.x, context.mousePosition.y);
            ofSetColor(ofColor::fromHsb((255 / numSections) * i, 200, 200), A(!inside || sectionInside)   * 255);
            ofDrawRectangle(A(section.x * (!sectionInside)),
                            A(section.y),
                            A(section.width * !inside + ((context.getSize().x) * sectionInside)),
                            A(section.height));
        }
    };
    
    // Here go parameters and any parameter convenience constructors. You need to define something called Parameters, even if it's NULL.
    struct Parameters {
        Parameters() {}
    };

    // The results type, you also need to define it even if it's nothing.
    typedef bool Results;
};
