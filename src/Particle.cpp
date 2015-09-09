//
//  Particle.cpp
//  ecal_particles_system
//
//  Created by Elise Migraine on 09.09.15.
//
//

#include "Particle.h"

void Particle::setup(){
    
    float x= ofRandom(ofGetWindowWidth());
    float y= ofRandom(ofGetWindowHeight());
    location.set(x, y);
    velocity.set(ofRandom(5),ofRandom(5));
    
    
}
void Particle::update(){
    
}

void Particle::draw(){
    
    ofSetColor(0);
    location = location + velocity;
    ofCircle(location.x, location.y, 2);
    
}
