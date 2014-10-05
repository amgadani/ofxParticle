#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(){
    this->width = ofGetWidth();
    this->height = ofGetHeight();
    numParticles = 100;
    currentEdgeMode = CLAMP;
    currentColorMode = ACCELERATION;
}

ParticleSystem::ParticleSystem(int numParts, int width, int height, edgeMode edge, colorMode color){
    this->width = width;
    this->height = height;
    numParticles = numParts;
    currentEdgeMode = edge;
    currentColorMode = color;
}
void ParticleSystem::setup() {
    particles.assign(numParticles, particle(width, height));
    for(int i = 0; i < particles.size(); i++) {
        particles[i].setPoint();
        particles[i].setColorMode(currentColorMode);
        particles[i].setEdgeMode(currentEdgeMode);
    }
}
void ParticleSystem::reset(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].setPoint();
    }
}
void ParticleSystem::display(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].display();
    }
}
void ParticleSystem::update() {
    for(int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }
}
void ParticleSystem::steer(ofPoint target, int attract){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].steer(target, attract);
    }
}

vector<particle> & ParticleSystem::getParticles() {
    return particles;
}