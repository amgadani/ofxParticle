#pragma once

#include "ofMain.h"
#include "ofxParticle.h"
#include "ofxTree.h"
class ofxParticleSystem {
public:
    ofxParticleSystem();

    ofxParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color, displayMode mode);
    void setup();
    void reset();
    void display(Boolean showTree);
    void update();
    void steer(ofxParticle target, int attract);
    vector<ofxParticle> getParticles();
    
    
    edgeMode currentEdgeMode;
    colorMode currentColorMode;
    displayMode currentDisplayMode;
    int numParticles;
    
    float width, height;
    ofxTree* tree;

    vector<ofxParticle> particles;
};