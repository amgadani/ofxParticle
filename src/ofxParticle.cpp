#include "ofxParticle.h"

ofxParticle::ofxParticle(float w, float h) {
    width = w;
    height = h;
    
}
void ofxParticle::setPoint(){
    loc = ofPoint(ofRandom(width), ofRandom(height));
    vel = ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    acc = ofPoint(0,0);
    speed = 1;
    weight = ofRandom(50, 150);
    maxspeed = 2.4;
    maxforce = 0.03;
}
void ofxParticle::display() {
    
    ofPushStyle();
    if(currentColorMode == ACCELERATION) {
        ofVec3f color = acc.normalized();
        ofSetColor(color.x*255, color.y*255, 255);
    }
    ofCircle(loc, 2);
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
void ofxParticle::steer(ofPoint target, int attract) {
    
    ofPoint steer;
    ofPoint desired = target - loc;
    float d = desired.length();
    desired.normalize();
    desired = attract*desired*maxspeed;
    steer = desired-vel;
    steer.limit(maxforce);
    acc = steer;
}
void ofxParticle::setColorMode(colorMode color){
    currentColorMode = color;
}
void ofxParticle::setEdgeMode(edgeMode mode){
    currentEdgeMode = mode;
}


