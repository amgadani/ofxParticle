#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    ps = ParticleSystem(1000, ofGetWidth(), ofGetHeight(), CLAMP, ACCELERATION);
    ps.setup();
    ofSetBackgroundColor(255, 255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){
    //ps.steer(ofPoint(mouseX, mouseY), attract);
    vector<particle> &parts = ps.getParticles();
    for(int i = 0; i<parts.size(); i++) {
        parts[i].steer(ofPoint(mouseX, mouseY), attract);
    }
    
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