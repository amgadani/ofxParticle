#include "ofxParticle.h"
ofxParticle::ofxParticle() {
    width = ofGetWidth();
    height = ofGetHeight();
    
}
ofxParticle::ofxParticle(float w, float h) {
    width = w;
    height = h;
    
}
void ofxParticle::setPoint(float x,float y){
    loc = ofPoint(x, y);
    vel = ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    acc = ofPoint(0,0);
    speed = 1;
    weight = ofRandom(5, 10);
    maxspeed = 2.4;
    maxforce = 0.03;
    currentColorMode = ACCELERATION;
    currentDisplayMode = CIRCLE;
    currentEdgeMode = CLAMP;
}
void ofxParticle::setPoint(){
    loc = ofPoint(ofRandom(width), ofRandom(height));
    vel = ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    acc = ofPoint(0,0);
    speed = 1;
    weight = ofRandom(5, 10);
    maxspeed = 2.4;
    maxforce = 0.03;
    currentColorMode = ACCELERATION;
    currentDisplayMode = CIRCLE;
    currentEdgeMode = CLAMP;
    
}
void ofxParticle::display() {
    
    ofPushStyle();
    switch (currentColorMode) {
        case ACCELERATION: {
            ofVec3f color = vel.normalized();
            ofSetColor(color.x*255, color.y*255, 255);
            break; }
        case FORCE: {
            ofSetColor(force*100, 0, 0);
            break;
        }
        default:{
            break;         
        }
   
    }
    switch (currentDisplayMode) {
        case CIRCLE:
            ofCircle(loc, 2);
            break;
        case CIRCLE_WEIGHT:
            ofCircle(loc, weight);
            break;
        default:
            break;
    }
    ofPopStyle();
}
void ofxParticle::update() {
    vel = vel+acc;
    loc = loc+vel;
    loc = clamp(loc);
    
}
ofPoint ofxParticle::clamp(ofPoint pos) {
    if (currentEdgeMode == CLAMP) {
        if( pos.x > width ){
            pos.x = width;
            vel.x *= -1.0;
        }else if( pos.x < 0 ){
            pos.x = 0;
            vel.x *= -1.0;
        }
        if( pos.y > height ){
            pos.y = height;
            vel.y *= -1.0;
        }
        else if( pos.y < 0 ){
            pos.y = 0;
            vel.y *= -1.0;
        }
    } else if (currentEdgeMode == WRAP) {
        if(pos.x < 0) {
            pos.x = width;
        }
        if (pos.x > width) {
            pos.x = int(pos.x)%int(width);
        }
        if(pos.y < 0) {
            pos.y = height;
        }
        if(pos.y > height) {
            pos.y = int(pos.y)%int(height);
        }
    }
    return pos;
}
void ofxParticle::steer(ofxParticle target, int attract) {
    
    ofPoint steer;
    ofPoint direction = target.loc - loc;
    float d = direction.length();
    if (d  < 5) d = 5;
    direction.normalize();
    force = target.weight * weight/(d*d);
    direction = attract*direction*force;
    steer = direction-vel;
    steer.limit(maxforce);
    acc = steer;
}
void ofxParticle::setColorMode(colorMode color){
    currentColorMode = color;
}
void ofxParticle::setEdgeMode(edgeMode mode){
    currentEdgeMode = mode;
}
void ofxParticle::setDisplayMode(displayMode mode){
    currentDisplayMode = mode;
}

