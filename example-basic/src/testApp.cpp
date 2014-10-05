#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    ps = ofxParticleSystem(1000, ofGetWidth(), ofGetHeight(), CLAMP, FORCE, CIRCLE_WEIGHT);
    ps.setup();
    ofSetBackgroundColor(255, 255, 255, 255);
    target = ofxParticle(ofGetWidth(), ofGetHeight());
    target.setPoint();
}

//--------------------------------------------------------------
void testApp::update(){
    target.weight = ofGetFrameNum();
    target.loc =ofPoint(mouseX, mouseY);
    ps.steer(target, attract);
    ps.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    ps.display();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ps.reset();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    attract = -1;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    attract = 1;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}