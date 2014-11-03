#pragma once
#include "ofMain.h"
enum edgeMode{
    WRAP,
    CLAMP
};

enum displayMode{
    RECT,
    CIRCLE,
    CIRCLE_WEIGHT
};

enum colorMode{
    INPUT,
    SPEED,
    ACCELERATION,
    FORCE
};

class ofxParticle {
    
public:
    ofxParticle(float w, float h);
    ofxParticle();

    void update();
    void display();
    void steer(ofxParticle point, int attract);
    void setPoint();
    void setPoint(float x, float y);

    void setColorMode(colorMode color);
    void setEdgeMode(edgeMode mode);
    void setDisplayMode(displayMode mode);
    ofPoint clamp(ofPoint point);
    
    ofPoint loc, vel, acc;
    float speed;
    float maxspeed;
    float maxforce;
    float weight;
    float force;
    float width, height;
    
    colorMode currentColorMode = INPUT;
    edgeMode currentEdgeMode = CLAMP;
    displayMode currentDisplayMode = CIRCLE;
};