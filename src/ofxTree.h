
#include "ofxParticle.h"

class ofxTree {
    
    public :

    ofxTree();
    ofxTree(float min_x, float max_x, float min_y, float max_y);
    ~ofxTree();
    void findMidpoints();
    void draw(Boolean showTree);
    void add(ofxParticle& particle);
    void addAll(vector<ofxParticle> particles);
    void steer(ofxParticle target, int attract);
    void update();
    vector<ofxParticle> getParticles();

    int numParticles;
    float minX, minY, maxX, maxY;
    float midX, midY;
    Boolean hasChildren;
    vector<ofxParticle> particles;
    ofxTree *northwest, *northeast, *southeast, *southwest;
    
};