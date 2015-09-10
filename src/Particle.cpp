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
    maxSpeed = 10;
    
    acceleration.set(0, 0);
    mass = ofRandom(30, 70);
    rayon = mass * 0.1;
}
void Particle::update(){
    if (velocity.length() < maxSpeed) {
        velocity += acceleration;
    }
    
    location = location + velocity;
    acceleration *= 0;
}

void Particle::draw(){
    
    ofSetColor(0);
    ofCircle(location.x, location.y, rayon);
    
}

void Particle::applyForce(ofVec2f force){
    acceleration = force/mass;
}























