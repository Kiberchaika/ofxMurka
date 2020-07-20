#pragma once

#include "MurkaTypes.h"
#include "MurkaContext.h"
#include "MurkaView.h"
#include "MurkaInputEventsRegister.h"
#include "MurkaAssets.h"
#include "MurkaLinearLayoutGenerator.h"


class MosaicLayoutPureFunctional {
    ///
    
public:
    
    void restart() {
        debugShapes.clear();
    }
    
    
    std::vector<MurkaShape> debugShapes;
    
    bool upperThanAllFour(MurkaPoint input, MurkaPoint a, MurkaPoint b, MurkaPoint c, MurkaPoint d) {
        return ((input.y <= a.y) && (input.y <= b.y) && (input.y <= c.y) && (input.y <= d.y));
    }

    bool lowerThanAllFour(MurkaPoint input, MurkaPoint a, MurkaPoint b, MurkaPoint c, MurkaPoint d) {
        return ((input.y >= a.y) && (input.y >= b.y) && (input.y >= c.y) && (input.y >= d.y));
    }

    bool toTheLeftOfAllFour(MurkaPoint input, MurkaPoint a, MurkaPoint b, MurkaPoint c, MurkaPoint d) {
        return ((input.x <= a.x) && (input.x <= b.x) && (input.x <= c.x) && (input.x <= d.x));
    }

    bool toTheRightOfAllFour(MurkaPoint input, MurkaPoint a, MurkaPoint b, MurkaPoint c, MurkaPoint d) {
        return ((input.x >= a.x) && (input.x >= b.x) && (input.x >= c.x) && (input.x >= d.x));
    }

    inline MurkaPoint getIntersectionVector(MurkaShape a, MurkaShape b) {
        
        MurkaPoint leftTopPointA = MurkaPoint(a.position.x,
                                              a.position.y);
        MurkaPoint bottomRightPointA = MurkaPoint(a.position.x + a.size.x,
                                                  a.position.y + a.size.y);
        MurkaPoint bottomLeftPointA = MurkaPoint(a.position.x,
                                                 a.position.y + a.size.y);
        MurkaPoint rightTopPointA = MurkaPoint(a.position.x + a.size.x,
                                               a.position.y);
        
        MurkaPoint bottomRightPointB = MurkaPoint(b.position.x + b.size.x,
                                                  b.position.y + b.size.y);

        MurkaPoint leftTopPointB = MurkaPoint(b.position.x, b.position.y);

        MurkaPoint rightTopPointB = MurkaPoint(b.position.x + b.size.x, b.position.y);

        MurkaPoint bottomLeftPointB = MurkaPoint(b.position.x, b.position.y + b.size.y);

        if (b.inside(leftTopPointA, 0)) {
            // return the difference between bottom right of shape B and left top
            return bottomRightPointB - leftTopPointA;
        }

        if (b.inside(bottomRightPointA, 0)) {
            // return the difference between top left of shape B and bottom right
            return leftTopPointB - bottomRightPointA;
        }

        if (b.inside(bottomLeftPointA, 0)) {
            // return the difference between bottom right of shape B and left top
            return rightTopPointB - bottomLeftPointA;
        }

        if (b.inside(rightTopPointA, 0)) {
            // return the difference between top left of shape B and bottom right
            return bottomLeftPointB - rightTopPointA;
        }
        
        if ((toTheLeftOfAllFour(leftTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (toTheLeftOfAllFour(bottomLeftPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (toTheRightOfAllFour(rightTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (toTheRightOfAllFour(bottomRightPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB))) {
            
//            ofLog() << "OBERLAP TYPE Z";
            
            float xComponent = 0;
            if (abs(bottomLeftPointA.x - bottomRightPointB.x) <
                abs(bottomRightPointA.x - bottomLeftPointB.x)) {
                // moving it to the right
                return {bottomLeftPointA.x - bottomRightPointB.x, 0};
            } else return {bottomRightPointA.x - bottomLeftPointB.x, 0};

        }

        if ((upperThanAllFour(leftTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (upperThanAllFour(rightTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (lowerThanAllFour(bottomLeftPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB)) &&
            (lowerThanAllFour(bottomRightPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB))) {
            
            if ((toTheLeftOfAllFour(leftTopPointB, bottomRightPointA, leftTopPointA, rightTopPointA, bottomLeftPointA)) &&
                (toTheLeftOfAllFour(bottomLeftPointB, bottomRightPointA, leftTopPointA, rightTopPointA, bottomLeftPointA)) &&
                (toTheRightOfAllFour(bottomRightPointB, bottomRightPointA, leftTopPointA, rightTopPointA, bottomLeftPointA)) &&
                (toTheRightOfAllFour(rightTopPointB, bottomRightPointA, leftTopPointA, rightTopPointA, bottomLeftPointA))) {
//                ofLog() << "A overlaps B by y, B overlaps A by x..";
                
                float yComponent = 0;
                if ((abs((bottomLeftPointB - leftTopPointB).length()) <
                     abs((leftTopPointA - bottomLeftPointB).length()))) {
                    yComponent = bottomLeftPointB.y - leftTopPointB.y;
                } else {
                    yComponent = leftTopPointA.y - bottomLeftPointB.y;
                }
                
//                ofLog() << "you sure left top point A is upper than all four of B? " << upperThanAllFour(leftTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB);
                
                return {0, yComponent};
            }
            
        };
        
        if (upperThanAllFour(leftTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB) &&
            lowerThanAllFour(bottomLeftPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB) &&
            toTheLeftOfAllFour(leftTopPointA, bottomRightPointB, bottomRightPointB, rightTopPointB, rightTopPointB) &&
            toTheRightOfAllFour(bottomRightPointA, bottomRightPointB, bottomRightPointB, rightTopPointB, rightTopPointB)) {
            
            return {bottomRightPointB.x - leftTopPointA.x, 0};
        }

        if (upperThanAllFour(leftTopPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB) &&
            lowerThanAllFour(bottomLeftPointA, bottomRightPointB, leftTopPointB, rightTopPointB, bottomLeftPointB) &&
            toTheRightOfAllFour(rightTopPointA, bottomLeftPointB, bottomLeftPointB, leftTopPointB, leftTopPointB) &&
            toTheLeftOfAllFour(leftTopPointA, bottomLeftPointB, bottomLeftPointB, leftTopPointB, leftTopPointB)) {
            
            return {bottomLeftPointB.x - rightTopPointA.x, 0};
        }

        return {0, 0};
    }
    
//        std::vector<MurkaShape> shapeOffers;
    
    MurkaShape latestBiggestIntersectionDebug;
    
    MurkaPoint getMaxOverlappingVector(MurkaShape input) {
        latestBiggestIntersectionDebug = {0, 0, 0, 0};
        
        bool badShape = false;
        double maxOverlap = 0;
        MurkaPoint maxOverlappingVector;
        for (auto i: debugShapes) {
            auto intersection = getIntersectionVector(input, i);
//            auto intersection2 = getIntersectionVector(i, input);
            
            MurkaPoint biggestIntersection = intersection * float(1);
            
            auto len = intersection.length();
            /*
            auto len = max(intersection.length(), intersection2.length());
            
            if (intersection.length() > intersection2.length()) {
                biggestIntersection = intersection;
                ofLog() << "picking 1...";
            } else {
                biggestIntersection = intersection2 * float(-1);
                ofLog() << "picking 2...";
            }
             */
            
//            ofLog() << "                    .x. " << len;
            if (len > 0) {
//                ofLog() << "                    .x. > 0... ";
                badShape = true;
                if (len > maxOverlap) {
//                    ofLog() << "                    .x. updates maxOverlap...";
                    maxOverlap = len;
                    maxOverlappingVector = biggestIntersection;
                    
                    latestBiggestIntersectionDebug = i;
                }
            }
        }
        
//        ofLog() << "returning " << maxOverlappingVector << " with length = " << maxOverlappingVector.length();
        return maxOverlappingVector;
    }
    
    MurkaShape findBetterPlace(MurkaShape input, MurkaShape avoidShape = {0, 0, 0, 0}) {

        auto maxOverlappingVector = getMaxOverlappingVector(input);
        bool badShape = (maxOverlappingVector.length() != 0);
        
        if (!badShape) {
//            ofLog() << "    > its good. maxOverlappingVector.length() = " << maxOverlappingVector.length();
            return input;
        }
//            else ofLog() << "         .. overlapping vector is " << maxOverlappingVector;
        
        MurkaShape offerY = {input.position.x, input.position.y + maxOverlappingVector.y,
                            input.size.x, input.size.y};
        MurkaShape offerX = {input.position.x + maxOverlappingVector.x, input.position.y,
                            input.size.x, input.size.y};

        
        
        if ((avoidShape == offerX) || (input == offerX)) {
//            ofLog() << "offerX (" << offerX.position << ") was bad, we were there before.";
            return offerY;
        }
        if ((avoidShape == offerY) || (input == offerY)) {
//            ofLog() << "offerY (" << offerY.position << ") was bad, we were there before.";
            return offerX;
        }
         
        
        /*
        if (avoidShape == offerX) {
            ofLog() << "    . found avoid shape in X";
            return offerY;
        }
        if (avoidShape == offerY) {
            ofLog() << "    . found avoid shape in Y";
            return offerX;
        }
         */
        
        /*
        auto offerXTest = getMaxOverlappingVector(offerX);
        auto offerYTest = getMaxOverlappingVector(offerY);
        
        
        if (offerXTest.length() != offerYTest.length()) {
            if (offerXTest.length() < offerYTest.length()) {
//                ofLog() << "        .. path X leads to lower length";
                return offerX;
            } else {
//                ofLog() << "        .. path Y leads to lower length";
                return offerY;
            }
        } else
         */
        {
            if (abs(maxOverlappingVector.x) > abs(maxOverlappingVector.y)) {
//                ofLog() << "        ..offer y is better, " << offerY.position;
                return offerY;
            } else {
//                ofLog() << "        ..offer x is better, " << offerX.position;
                return offerX;
            }
        }
    }
    
    vector<MurkaShape> debugPath;
    
    MurkaShape findBetterPlaceWithDepth(MurkaShape input, int depth = 2) {
//            ofLog() << ":::::::::::::::::::::::::::::::::::::::";
        debugPath.clear();
        
        bool equal = false;
        
        MurkaShape offer = input;
        MurkaShape previousOffer = offer;
        MurkaShape previousPreviousOffer;
        
        debugPath.push_back(offer);

        while (!(depth == 0)) {
            
            double preDist = (offer.position - input.position).length();
            
//                ofLog() << "   . asking to improve " << offer.position;
//                ofLog() << "   which had an overlap of " << getMaxOverlappingVector(offer);
            offer = findBetterPlace(offer, previousPreviousOffer);
            if (offer == previousOffer) {
//                    ofLog() << "found same...";
                debugShapes.push_back(offer);
                return offer;
            } else {
//                    ofLog() << "  ... " << depth << " increments from " << preDist << " to " << (offer.position - input.position).length();
            }
            
            debugPath.push_back(offer);
            
            depth--;
            previousPreviousOffer = previousOffer;
            previousOffer = offer;
        }
        
//            ofLog() << "started with " << input.position << " ended with " << offer.position;
        debugShapes.push_back(offer);

        return offer;
    }
};
