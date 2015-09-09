#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    velocity.set(1,1);
    velocity *= 3;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    location = location + velocity;
    ofCircle(location.x, location.y, 20);
    checkEdges();
}

void ofApp::checkEdges(){
    if (location.y > ofGetWindowHeight() || location.y < 0 ){
        velocity *= ofVec2f(1,-1);
    }
    
    else if(location.x > ofGetWindowWidth() || location.x < 0) {
        velocity *= ofVec2f(-1,1);
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
