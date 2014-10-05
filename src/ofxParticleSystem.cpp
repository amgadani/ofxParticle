#include "ofxParticleSystem.h"

ofxParticleSystem::ofxParticleSystem(){
    this->width = ofGetWidth();
    this->height = ofGetHeight();
    numParticles = 100;
    currentEdgeMode = CLAMP;
    currentColorMode = ACCELERATION;
    currentDisplayMode = CIRCLE;
}

ofxParticleSystem::ofxParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color, displayMode mode){
    this->width = width;
    this->height = height;
    numParticles = numParts;
    currentEdgeMode = edge;
    currentColorMode = color;
    currentDisplayMode = mode;
}
void ofxParticleSystem::setup() {
    particles.assign(numParticles, ofxParticle(width, height));
    for(int i = 0; i < particles.size(); i++) {
        particles[i].setPoint();
        particles[i].setColorMode(currentColorMode);
        particles[i].setEdgeMode(currentEdgeMode);
        particles[i].setDisplayMode(currentDisplayMode);

    }
}
void ofxParticleSystem::reset(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].setPoint();
    }
}
void ofxParticleSystem::display(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].display();
    }
}
void ofxParticleSystem::update() {
    for(int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }
}
void ofxParticleSystem::steer(ofxParticle target, int attract){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].steer(target, attract);
    }
}

vector<ofxParticle> & ofxParticleSystem::getParticles() {
    return particles;
}