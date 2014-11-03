#include "ofxParticleSystem.h"

ofxParticleSystem::ofxParticleSystem(){
    this->width = ofGetWidth();
    this->height = ofGetHeight();
    numParticles = 100;
    currentEdgeMode = CLAMP;
    currentColorMode = ACCELERATION;
    currentDisplayMode = CIRCLE;
    tree = new ofxTree(0, width, 0, height);
}

ofxParticleSystem::ofxParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color, displayMode mode){
    this->width = width;
    this->height = height;
    numParticles = numParts;
    currentEdgeMode = edge;
    currentColorMode = color;
    currentDisplayMode = mode;
    tree = new ofxTree(0, width, 0, height);
}
void ofxParticleSystem::setup() {
    particles.assign(numParticles, ofxParticle(width, height));
    for(int i = 0; i < particles.size(); i++) {
        particles[i].setPoint();
        particles[i].setColorMode(currentColorMode);
        particles[i].setEdgeMode(currentEdgeMode);
        particles[i].setDisplayMode(currentDisplayMode);

    }
    tree->addAll(particles);

}
void ofxParticleSystem::reset(){
    delete tree;
    tree = new ofxTree(0, width, 0, height);
    tree->addAll(particles);
}
void ofxParticleSystem::display(Boolean showTree){
    tree->draw(showTree);
    
}
void ofxParticleSystem::update() {
    tree->update();
    particles = tree->getParticles();
    delete tree;
    tree = new ofxTree(0, width, 0, height);
    tree->addAll(particles);
  
}
void ofxParticleSystem::steer(ofxParticle target, int attract){
    tree->steer(target, attract);
}

vector<ofxParticle> ofxParticleSystem::getParticles() {
    return tree->getParticles();
}