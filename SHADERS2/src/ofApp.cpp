#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    light.setup();
    light.setPosition(-100, 200,0);
    ofEnableDepthTest();

    sphereMaterial.setDiffuseColor(ofFloatColor::red);
    sphereMaterial.setShininess(0.02);

    shader.load("shader");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofLight();
    ofSetColor(1.0, 0.5, 0.0);

    //Enable the shader
    shader.begin();
cam.begin();
 sphereMaterial.begin();
    ofPushMatrix();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawSphere(100.0);
    ofPopMatrix();
 sphereMaterial.end();
cam.end();

    shader.end();   //Disable the shader
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
