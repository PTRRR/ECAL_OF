#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    int nmbrparticle = 10000;
    for (int i = 0; i < nmbrparticle; i++) {
        
        Particle p = Particle();
        p.setup();
        particles.push_back(p);
    }
    
    repulsionPoint.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    
    for (int i = 0; i < 5; i++) {
        ofVec2f pointTemp = ofVec2f(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
        attractionPoints.push_back(pointTemp);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mouseAttractionPoint.set(ofGetMouseX(), ofGetMouseY());
    
    ofVec2f gravity = ofVec2f (0, 0);
    noiseCounter += 0.01;
    ofVec2f wind = ofVec2f ((ofNoise(noiseCounter)-0.5) * 10, 0);
    
    for (int i = 0;i < particles.size() ; i++ ) {
        Particle &pTemp = particles[i];
        
        pTemp.update();
        pTemp.applyForce(gravity);
        ofVec2f friction = ofVec2f (particles[i].acceleration);
        pTemp.applyForce(friction.normalize() * 2);
        pTemp.applyForce(wind);
        
        for (int i = 0; i < attractionPoints.size(); i++) {
            ofVec2f pointForce = attractionPoints[i] - pTemp.location;
            
            ofVec2f forceApplied = pointForce.normalize()*1;
            float dist = pointForce.length();
            
            pTemp.applyForce(forceApplied / dist);
        }
        
        ofVec2f pointForce = mouseAttractionPoint - pTemp.location;
        pTemp.applyForce(pointForce.normalize()*30);
        
        ofVec2f repulsionForce = pTemp.location - repulsionPoint;
        pTemp.applyForce(repulsionForce.normalize() * 30);
        
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
//    for (int i = 0; i < attractionPoints.size(); i++) {
//        ofSetColor(255, 0, 0);
//        ofCircle(attractionPoints[i], 10);
//    }
    ofSetColor(0);
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
        checkEdges(particles[i]);
    }
    
    ofSetColor(0, 0, 255);
    ofCircle(mouseAttractionPoint.x, mouseAttractionPoint.y, 2);
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
