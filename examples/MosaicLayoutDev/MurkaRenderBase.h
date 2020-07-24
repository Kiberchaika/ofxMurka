#pragma once

#include "MurVbo.h"
#include "MurTexture.h"
#include "MurImage.h"
#include "MurkaTypes.h"

/*
 virtuals:
 
 void draw(const ofImage & image, float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh) const;
 void draw(const ofTexture & image, float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh) const;
 void draw(const ofVbo & vbo, GLuint drawMode, int first, int total) const;
 
 // transformations
 void pushView();
 void popView();

 // setup matrices and viewport (upto you to push and pop view before and after)
void viewport(ofRectangle viewport);
 void viewport(float x = 0, float y = 0, float width = -1, float height = -1, bool vflip=true);

 // rendering setup
 
 void setLineWidth(float lineWidth);
 void enableFill();
 void disableFill();
 void setLineSmoothing(bool smooth);
 void enableAntiAliasing();
 void disableAntiAliasing();
 void pushStyle();
 void popStyle();
 
 // color options
 void setColor(int r, int g, int b); // 0-255
 void setColor(int r, int g, int b, int a); // 0-255
 void setColor(const ofColor & color);
 void setColor(const ofColor & color, int _a);
 void setColor(int gray); // new set a color as grayscale with one argument

 void clear();
 void clear(float r, float g, float b, float a=0);
 void clear(float brightness, float a=0);

 */

class MurkaRenderBase: public MurkaAssets {
public:
    
    // Object drawing
    virtual void draw(const MurImage & image, float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh) const;
    virtual void draw(const MurTexture & image, float x, float y, float z, float w, float h, float sx, float sy, float sw, float sh) const;
    virtual void draw(const MurVbo & vbo, GLuint drawMode, int first, int total) const;
    
    // Textures binding
    virtual void bind(const ofTexture & texture, int location);
    virtual void unbind(const ofTexture & texture, int location);
    
    // transformations
    virtual void pushView();
    virtual void popView();

    // setup matrices and viewport (upto you to push and pop view before and after)
    virtual void viewport(MurkaShape viewport);
    virtual void viewport(float x = 0, float y = 0, float width = -1, float height = -1, bool vflip=true);

    // rendering setup
    virtual void setLineWidth(float lineWidth);
    virtual void enableFill();
    virtual void disableFill();
    virtual void setLineSmoothing(bool smooth);
    virtual void enableAntiAliasing();
    virtual void disableAntiAliasing();
    virtual void pushStyle();
    virtual void popStyle();
    
    // color options
    virtual void setColor(int r, int g, int b); // 0-255
    virtual void setColor(int r, int g, int b, int a); // 0-255
    virtual void setColor(const MurkaColor & color);
    virtual void setColor(const MurkaColor & color, int _a);
    virtual void setColor(int gray); // new set a color as grayscale with one argument

    virtual void clear();
    virtual void clear(float r, float g, float b, float a=0);
    virtual void clear(float brightness, float a=0);
};
