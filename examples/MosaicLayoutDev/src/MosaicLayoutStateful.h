#pragma once

#include "MurkaTypes.h"
#include "MurkaContext.h"
#include "MurkaView.h"
#include "MurkaInputEventsRegister.h"
#include "MurkaAssets.h"
#include "MurkaLinearLayoutGenerator.h"

class MosaicLayoutStateful {
        ///
        
    public:
        
        int counter = 0;
        
//        std::vector<MurkaShape> debugShapes;
        
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
                } else {
//                    ofLog() << "returning " << bottomRightPointA.x - bottomLeftPointB.x << " x";
                    return {bottomRightPointA.x - bottomLeftPointB.x, 0};
                }

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
        
        
        
        MurkaPoint getMaxOverlappingVector(MurkaShape input) {
            
            bool badShape = false;
            double maxOverlap = 0;
            MurkaPoint maxOverlappingVector;
            for (auto i: inputShapes) {
                auto intersection = getIntersectionVector(input, i.second);
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
                        
                    }
                }
            }
            
    //        ofLog() << "returning " << maxOverlappingVector << " with length = " << maxOverlappingVector.length();
            return maxOverlappingVector;
        }
        

        
        vector<MurkaShape> debugPath;
    
    
        map<int, MurkaShape> inputShapes;
        map<pair<int, int>, MurkaPoint> vectorToModify;
        map<int, int> shapeModifyCounter;
    
        void restart() {
//            debugShapes.clear();
            counter = 0;
            
            for (auto &v: vectorToModify) {
                v.second = MurkaPoint(0, 0);
            }
            
            // applying changes
            
            for (auto i: inputShapes) {
                for (auto j: inputShapes) {
                    auto intersection = getIntersectionVector(j.second, i.second);
                    
                    if ((intersection.length() > 20) && (j.first != i.first)) {
//                        ofLog() << i.second.position << " x " << j.second.position;
//                        ofLog() << i.first << " ; " << j.first << " inter = " << intersection;
                        std::pair<int, int> key = std::make_pair(min(i.first, j.first),
                                                                 max(i.first, j.first));
                        
                        if (vectorToModify[key].length() == 0) {
                            
                            vectorToModify[key] = {0, 0};
                            if ((std::get<0>(key) + shapeModifyCounter[std::get<0>(key)]) % 2) {
                                vectorToModify[key].y += intersection.y / 4;
                            } else {
                                vectorToModify[key].x += intersection.x / 4;
                            }
                            
                            
//                            ofLog() << "   updated the vector between " << std::get<0>(key) << " and " << std::get<1>(key) << " is " << vectorToModify[key];
                        }
                        
                    }
//                    vectorToModify[j.first] -= intersection / 4;
                }
            }
            
            for (auto &v: vectorToModify) {
                auto key = v.first;
//                ofLog() << "vector between " << std::get<0>(key) << " : " << inputShapes[std::get<0>(key)].position << " and " << std::get<1>(key)  << " : "  <<  inputShapes[std::get<1>(key)].position  << " is " << v.second << " aka " << vectorToModify[key];
                
                if (shapeModifyCounter[std::get<0>(key)] > -1000) {
                    inputShapes[std::get<0>(key)].position -= vectorToModify[key];
                    inputShapes[std::get<1>(key)].position += vectorToModify[key];
                    
                    shapeModifyCounter[std::get<0>(key)]--;
                }
            }
            /*
            int index = 0;
            for (auto i: inputShapes) {
                inputShapes[i.first].position += vectorToModify[i.first];
                
                ofLog() << index << " modified with " << vectorToModify[i.first];
                index++;
            }
             */
        }
        
        

        MurkaShape findBetterPlaceWithDepth(MurkaShape input, int depth = 5) {
            
            if (inputShapes.find(counter) == inputShapes.end()) {
                inputShapes[counter] = input;
                shapeModifyCounter[counter] = depth;
//                vectorToModify[counter] = {0, 0};
                
                counter++;
                
                ofLog() << "restarted a " << counter;
                
                return input;
            } /* else
            if (inputShapes[counter] != input) {
                inputShapes[counter] = input;
                vectorToModify[counter] = {0, 0};
                
                counter++;
                
                ofLog() << "restarted b " << counter;
                
                return input;
            }
               */
            
            // By now we've established that this particular box should affect others and be affected
            // and the user doesn't want it to move
            
            /*
            for (auto i: inputShapes) {
                auto intersection = getIntersectionVector(input, i.second);
//                ofLog() << ""
                
                MurkaPoint center1 = input.position + input.size / 2;
                MurkaPoint center2 = i.second.position + i.second.size / 2;
                
                vectorToModify[i.first] += (center1 - center2) / 40;
                
//                vectorToModify[counter] -= intersection / 400;
            }
             */
            counter++;

            return inputShapes[counter - 1];
            
        }
};
