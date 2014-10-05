#pragma once

#include "ofMain.h"
#include "particle.h"

class ParticleSystem {
public:
    ParticleSystem();

    ParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color);
    void setup();
    void reset();
    void display();
    void update();
    void steer(ofPoint target, int attract);
    vector<particle> & getParticles();
    
    
    edgeMode currentEdgeMode;
    colorMode currentColorMode;
    int numParticles;
    
    float width, height;
    vector<particle> particles;
};