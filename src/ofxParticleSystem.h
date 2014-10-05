#pragma once

#include "ofMain.h"
#include "ofxParticle.h"

class ofxParticleSystem {
public:
    ofxParticleSystem();

    ofxParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color);
    void setup();
    void reset();
    void display();
    void update();
    void steer(ofPoint target, int attract);
    vector<ofxParticle> & getParticles();
    
    
    edgeMode currentEdgeMode;
    colorMode currentColorMode;
    int numParticles;
    
    float width, height;
    vector<ofxParticle> particles;
};