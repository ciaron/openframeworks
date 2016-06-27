#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableColors();
    mesh.enableIndices();

    sphere.setRadius( 200 );

    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 120 );
    // the light highlight of the material //
    material.setSpecularColor(ofColor(255, 255, 255, 255));

    vertices0 = sphere.getMesh().getVertices();
}

//--------------------------------------------------------------
void ofApp::update(){

    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);

    // see openFrameworks Essentials
    float deformFreq=0.01 * mouseX;
    vector<ofPoint> &vertices = sphere.getMesh().getVertices();
    for (int i=0; i<vertices.size(); i++) {
        ofPoint v = vertices0[i];
        v.normalize();
        float sx = sin( v.x * deformFreq );
        float sy = sin( v.y * deformFreq );
        float sz = sin( v.z * deformFreq );
        v.x += sy * sz * 1;
        v.y += sx * sz * 1;
        v.z += sx * sy * 1;
        v *= 200;
        vertices[i] = v;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(ofColor(0));
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);

    ofEnableDepthTest();

    ofEnableLighting();
    pointLight.enable();

    sphere.setPosition(ofGetWidth()*.2, ofGetHeight()*.75, 0);
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);

    //mesh = sphere.getMesh();

    // get all the faces from the icoSphere, handy when you want to copy
    // individual vertices or tweak them a little ;)
    //vector<ofMeshFace> triangles = sphere.getMesh().getUniqueFaces();

    // now draw
    ofPushMatrix();

    ofTranslate(ofGetWidth()/3, -ofGetHeight()/3);
    //sphere.draw();
    sphere.drawWireframe();

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //mesh.drawWireframe();





//    int numVerts = mesh.getNumVertices();

//    for (int a=0; a<numVerts; ++a) {
//        ofVec3f verta = mesh.getVertex(a);

//        for (int b=a+1; b<numVerts; ++b) {
//            ofVec3f vertb = mesh.getVertex(b);
//            float distance = verta.distance(vertb);

//            if (distance <= 10) {
//                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
//                // connected to form a line
//                mesh.addIndex(a);
//                mesh.addIndex(b);
//            }
//        }
//    }


    ofPopMatrix();

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
