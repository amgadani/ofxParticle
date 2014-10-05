#pragma once
#include "ofMain.h"
enum edgeMode{
    WRAP,
    CLAMP
};

enum displayMode{
    RECT,
    CIRCLE
};

enum colorMode{
    INPUT,
    SPEED,
    ACCELERATION
};

class particle {
    
public:
    particle(float w, float h);
    void update();
    void display();
    void steer(ofPoint point, int attract);
    void setPoint();
    void setColorMode(colorMode color);
    void setEdgeMode(edgeMode mode);
    ofPoint clamp(ofPoint point);
    
    ofPoint loc, vel, acc;
    float speed;
    float maxspeed;
    float maxforce;
    float weight;
    float width, height;
    
    colorMode currentColorMode = INPUT;
    edgeMode currentEdgeMode = CLAMP;
};