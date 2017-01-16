#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle( "Video synth" );
    ofSetWindowShape( 1280, 720 );
    ofSetFrameRate( 60 );
    ofBackground( ofColor::white );
    
    ofLoadImage( image, "collage.png" );
    //video.loadMovie( "flowing.mp4" );
    video.load( "x15.mp4" );
    video.play();
    video.setPosition(45.0);
    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );

    shader.load( "kaleido" );

    float l = video.getDuration();
    //cout << "video length: " << l << endl;
    skip = gui->skipSecs / l;

}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if ( camera.isInitialized() ) camera.update();
}

//--------------------------------------------------------------
void ofApp::stripePattern() {
    ofSetColor( gui->color );
    ofSetLineWidth( 1.0 );
    if ( gui->filled ) ofFill(); else ofNoFill();
    for (int i=-gui->countX; i<=gui->countX; i++) {
        ofPushMatrix();
        ofTranslate( i * gui->stepX, 0 );
        ofRotate( i * gui->twistX );
        
        ofTranslate( 0, gui->shiftY );
        ofRotate( gui->rotate );
        ofScale( gui->sizeX, gui->sizeY );
        if ( gui->type ) ofRect( -50, -50, 100, 100 );
        else ofTriangle( 0, 0, -50, 100, 50, 100 );
        
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::matrixPattern() {
    for (int y=-gui->countY; y<=gui->countY; y++) {
        ofPushMatrix();
        //---------------------
        if ( gui->countY > 0 ) {
            float scl = ofMap( y, -gui->countY, gui->countY, 1-gui->pinchY, 1 );
            ofScale( scl, scl );
        }
        ofTranslate( 0, y * gui->stepY );
        ofRotate( y * gui->twistY );
        stripePattern();
        //---------------------
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::draw2d() {
    ofBackground( gui->Background );
    //ofClear(0);
    
    //Image, video and camera
    ofDisableSmoothing();
    ofEnableBlendMode( OF_BLENDMODE_ADD );
    ofSetColor( 255, gui->imageAlpha );
    image.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    ofSetColor( 255, gui->videoAlpha );
    video.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    if ( camera.isInitialized() ) {
        ofSetColor( 255, gui->cameraAlpha );
        camera.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    }
    ofEnableAlphaBlending();
    ofEnableSmoothing();

    video.setVolume(gui->volume);

    if (gui->skipFwd) {
        float p = video.getPosition();
        video.setPosition(p+skip);
        gui->skipFwd = false;
    }

    if (gui->skipBack) {
        float p = video.getPosition();
        video.setPosition(p-skip);
        gui->skipBack = false;
    }
    
    //Matrix pattern
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    float Scl = pow( gui->Scale, 4.0f );
    ofScale( Scl, Scl );
    ofRotate( gui->Rotate );
    //----
    matrixPattern();
    //----
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    draw2d();
    fbo.end();
    ofSetColor( 255 );
    
    if ( gui->kenabled ) {
        shader.begin();
        shader.setUniform1i( "ksectors", gui->ksectors );
        shader.setUniform1f( "kangleRad", ofDegToRad(gui->kangle) );
        shader.setUniform2f( "kcenter", gui->kx*ofGetWidth(),
                            gui->ky*ofGetHeight() );
        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
                            0.5*ofGetHeight() );
    }
    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    if ( gui->kenabled ) shader.end();
    
    //if ( showGui ) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //if ( key == 'z' ) showGui = !showGui;
//    if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot.png" );
    if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot" + ofToString( ofRandom(1, 1000), 0) + ".png" );
    
//    if ( key == 's' ) {
//        ofFileDialogResult res;
//        res = ofSystemSaveDialog( "preset.xml", "Saving Preset");
//        if ( res.bSuccess ) gui.saveToFile( res.filePath );
//    }
//    if ( key == 'l' ) {
//        ofFileDialogResult res;
//        res = ofSystemLoadDialog( "Loading Preset" );
//        if ( res.bSuccess ) gui.loadFromFile( res.filePath );
//    }
    
    //Chapter 4
    
    if ( key == 'c' ) {
        camera.setDeviceID( 0 );
        camera.setDesiredFrameRate( 30 );
        camera.initGrabber( 1280, 720 );
    }
    
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
