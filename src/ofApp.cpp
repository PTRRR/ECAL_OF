#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    int nmbrparticle = 40;
    for (int i = 0; i < nmbrparticle; i++) {
        
        Particle p = Particle();
        p.setup();
        particles.push_back(p);
//        particles[i].setup();
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f gravity = ofVec2f (0, 2);
    noiseCounter += 0.01;
    ofVec2f wind = ofVec2f ((ofNoise(noiseCounter)-0.5) * 1000, 0);
    
    for (int i = 0;i < particles.size() ; i++ ) {
        particles[i].update();
        particles[i].applyForce(gravity);
        ofVec2f friction = ofVec2f (particles[i].acceleration);
        particles[i].applyForce(friction.normalize() * 2);
        particles[i].applyForce(wind);
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
        checkEdges(particles[i]);
    }
}

void ofApp::checkEdges(Particle &p){
    if (p.location.y > ofGetWindowHeight() ){
        p.location.y = ofGetWindowHeight();
        p.velocity *= ofVec2f(1,-1);
        p.applyForce(-p.velocity);
    }
    else if (p.location.y < 0){
        p.location.y = 0;
        p.velocity *= ofVec2f(1,-1);
        p.applyForce(-p.velocity);
    }
    else if(p.location.x > ofGetWindowWidth()) {
        p.location.x = ofGetWindowWidth();
        p.velocity *= ofVec2f(-1,1);
        p.applyForce(-p.velocity);
    }
    else if (p.location.x < 0){
        p.location.x = 0;
        p.velocity *= ofVec2f(-1,1);
        p.applyForce(-p.velocity);
    }
}











































//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
