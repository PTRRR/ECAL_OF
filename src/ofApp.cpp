#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    int nmbrparticle = 500;
    for (int i = 0; i < nmbrparticle; i++) {
        
        Particle p = Particle();
        p.setup();
        particles.push_back(p);
//        particles[i].setup();
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0;i < particles.size() ; i++ ) {
        particles[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    for (int i = 0;i < particles.size() ; i++ ) {
        particles[i].draw();
        checkEdges( particles[i]);
    }
}

void ofApp::checkEdges(Particle &p){
    if (p.location.y > ofGetWindowHeight() || p.location.y < 0 ){
        p.velocity *= ofVec2f(1,-1);
    }
    
    else if(p.location.x > ofGetWindowWidth() || p.location.x < 0) {
        p.velocity *= ofVec2f(-1,1);
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
