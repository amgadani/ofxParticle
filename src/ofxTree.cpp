#include "ofxTree.h"

ofxTree::ofxTree() {
    numParticles = 0;
    hasChildren = false;
    minX = 0;
    maxX = 0;
    minY = 0;
    maxY = 0;
    
}
ofxTree::ofxTree(float min_x, float max_x, float min_y, float max_y) {
    numParticles = 0;
    hasChildren = false;
    minX = min_x;
    maxX = max_x;
    minY = min_y;
    maxY = max_y;
    findMidpoints();
}
ofxTree::~ofxTree() {
    if(hasChildren) {
    delete northwest;
    delete northeast;
    delete southwest;
    delete southeast;
    }
}
void ofxTree::findMidpoints() {
    midX = (minX + maxX)/2;
    midY = (minY + maxY)/2;
}

void ofxTree::add(ofxParticle& particle) {
  //  cout << particle.loc << "\n";
    if (hasChildren) {
  //      cout << "has children \n";
        if (particle.loc.x < midX) {
            if (particle.loc.y < midY) {
                northwest->add(particle);
            } else {
                southwest->add(particle);
            }
        } else {
            if (particle.loc.y < midY) {
                northeast->add(particle);
            } else {
                southeast->add(particle);
            }
        }
    } else {
        //cout << "no children\n";
        //particles.push_back(particle);
        if (particles.size() < 1) {
    //        cout << "size < 1\n";
            particles.push_back(particle);
        } else {
    //        cout << "do i get here? \n";
            northwest = new ofxTree(minX, midX, minY, midY);
            northeast = new ofxTree(midX, maxX, minY, midY);
            southwest = new ofxTree(minX, midX, midY, maxY);
            southeast = new ofxTree(midX, maxX, midY, maxY);
            hasChildren = true;
            for (int i = 0 ; i < particles.size(); i++) {
                add(particles[i]);
            }
            particles.clear();
            add(particle);
        }
    }
    
   // cout << "i should stop here \n\n";
    
}

void ofxTree::addAll(vector<ofxParticle> parts) {
    for (int i = 0; i < parts.size(); i++) {
        add(parts[i]);
    }
}
void ofxTree::draw(Boolean showTree) {
    ofSetColor(ofRandom(255),0,ofRandom(255));
    ofNoFill();
    for (int i = 0; i < particles.size(); i++) {
        particles[i].display();
    }

    if (showTree) {
        ofRect(minX, minY, maxX - minX, maxY - minY);
    }
    if(hasChildren) {
        northwest->draw(showTree);
        northeast->draw(showTree);
        southwest->draw(showTree);
        southeast->draw(showTree);
    }
}

void ofxTree::steer(ofxParticle target, int attract) {
    for (int i = 0; i < particles.size(); i++) {
        particles[i].steer(target, attract);
    }
    if(hasChildren) {
        northwest->steer(target, attract);
        northeast->steer(target, attract);
        southwest->steer(target, attract);
        southeast->steer(target, attract);
    }
}

void ofxTree::update(){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].update();
    }
    if(hasChildren) {
        northwest->update();
        northeast->update();
        southwest->update();
        southeast->update();
    }
}
vector<ofxParticle> ofxTree::getParticles() {
    vector<ofxParticle> parts = particles;
   // cout << parts.size() << "\n-";
    if(hasChildren) {
        vector<ofxParticle> nw = northwest->getParticles();
        vector<ofxParticle> sw = southwest->getParticles();
        vector<ofxParticle> ne = northeast->getParticles();
        vector<ofxParticle> se = southeast->getParticles();
      /*  cout << "northwest: "<< nw.size() << " ";
        cout << "northeast: "<< ne.size() << "\n";
        cout << "southwest: "<< sw.size() << " ";
        cout << "southeast: "<< se.size() << "\n\n";
*/
        parts.insert(parts.end(), nw.begin(), nw.end());
        parts.insert(parts.end(), sw.begin(), sw.end());
        parts.insert(parts.end(), ne.begin(), ne.end());
        parts.insert(parts.end(), se.begin(), se.end());
    }
    return parts;

 //   cout << parts.size() << "\n";
}
