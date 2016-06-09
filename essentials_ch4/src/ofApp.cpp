#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle( "Video synth" );
    ofSetWindowShape( 1280, 720 );
    ofSetFrameRate( 60 );
    ofBackground( ofColor::white );
    
    //Chapter 3
    
    gui.setup( "Parameters", "settings.xml" );

    gui.add( countX.setup( "countX", 50, 0, 200 ) );
    gui.add( stepX.setup( "stepX", 20, 0, 200 ) );
    gui.add( twistX.setup( "twistX", 5, -45, 45 ) );
    
    gui.add( countY.setup( "countY", 0, 0, 50) );
    gui.add( stepY.setup( "stepY", 20, 0, 200 ) );
    gui.add( twistY.setup( "twistY", 0, -30, 30 ) );
    gui.add( pinchY.setup( "pinchY", 0, 0, 1 ) );
    
    globalGroup.setup( "Global" );
    globalGroup.add( Scale.setup( "Scale", 1, 0.0, 1 ) );
    globalGroup.add( Rotate.setup( "Rotate", 0, -180, 180 ) );
	//globalGroup.add( Background.setup( "Background", 255, 0, 255 ) );		//white background (book's version)
	globalGroup.add( Background.setup( "Background", 0, 0, 255 ) );			//black background (is convenient for direct starting this example)
    gui.add( &globalGroup );
    
    primGroup.setup( "Primitive" );
    primGroup.add( shiftY.setup( "shiftY", 0.0, -1000.0, 1000.0 ) );
    primGroup.add( rotate.setup( "rotate", 0.0, -180.0, 180.0 ) );
    primGroup.add( size.setup( "size",
                              ofVec2f(6,6),
                              ofVec2f(0,0),
                              ofVec2f(20,20) ) );
    //color.setDefaultBackgroundColor( ofColor::gray );
    primGroup.add( color.setup( "color",
                               ofColor::black,
                               ofColor(0,0,0,0),
                               ofColor::white ) );
    primGroup.add( filled.setup( "filled", false ) );
    primGroup.add( type.setup( "type", false ) );
    gui.add( &primGroup );

    
    //Chapter 4
    
    ofLoadImage( image, "collage.png" );
    video.loadMovie( "flowing.mp4" );
    video.play();
    mixerGroup.setup( "Mixer" );
    mixerGroup.setHeaderBackgroundColor( ofColor::darkRed );
    mixerGroup.setBorderColor( ofColor::darkRed );
    
    mixerGroup.add( imageAlpha.setup( "image", 100,0,255 ) );
    mixerGroup.add( videoAlpha.setup( "video", 200,0,255 ) );
    mixerGroup.add( cameraAlpha.setup( "camera", 100,0,255 ) );
    
    shader.load( "kaleido" );
    mixerGroup.add( kenabled.setup( "kenabled", true ) );
    mixerGroup.add( ksectors.setup( "ksectors", 10, 1, 100 ) );
    mixerGroup.add( kangle.setup( "kangle", 0, -180, 180 ) );
    mixerGroup.add( kx.setup( "kx", 0.5, 0, 1 ) );
    mixerGroup.add( ky.setup( "ky", 0.5, 0, 1 ) );
    
    
    gui.minimizeAll();
    gui.add( &mixerGroup );
    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    
    //-----------
    gui.loadFromFile( "settings.xml" );
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::exit() {
    gui.saveToFile( "settings.xml" );
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if ( camera.isInitialized() ) camera.update();
}

//--------------------------------------------------------------
void ofApp::stripePattern() {
    ofSetColor( color );
    ofSetLineWidth( 1.0 );
    if ( filled ) ofFill(); else ofNoFill();
    for (int i=-countX; i<=countX; i++) {
        ofPushMatrix();
        ofTranslate( i * stepX, 0 );
        ofRotate( i * twistX );
        
        ofTranslate( 0, shiftY );
        ofRotate( rotate );
        ofScale( size->x, size->y );
        if ( type ) ofRect( -50, -50, 100, 100 );
        else ofTriangle( 0, 0, -50, 100, 50, 100 );
        
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::matrixPattern() {
    for (int y=-countY; y<=countY; y++) {
        ofPushMatrix();
        //---------------------
        if ( countY > 0 ) {
            float scl = ofMap( y, -countY, countY, 1-pinchY, 1 );
            ofScale( scl, scl );
        }
        ofTranslate( 0, y * stepY );
        ofRotate( y * twistY );
        stripePattern();
        //---------------------
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::draw2d() {
    ofBackground( Background );
    //ofClear(0);
    
    //Image, video and camera
    ofDisableSmoothing();
    ofEnableBlendMode( OF_BLENDMODE_ADD );
    ofSetColor( 255, imageAlpha );
    image.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    ofSetColor( 255, videoAlpha );
    video.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    if ( camera.isInitialized() ) {
        ofSetColor( 255, cameraAlpha );
        camera.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    }
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    //Matrix pattern
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    float Scl = pow( Scale, 4.0f );
    ofScale( Scl, Scl );
    ofRotate( Rotate );
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
    
    if ( kenabled ) {
        shader.begin();
        shader.setUniform1i( "ksectors", ksectors );
        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
                            ky*ofGetHeight() );
        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
                            0.5*ofGetHeight() );
    }
    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    if ( kenabled ) shader.end();
    
    if ( showGui ) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'z' ) showGui = !showGui;
//    if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot.png" );
    if ( key == OF_KEY_RETURN ) ofSaveScreen( "screenshot" + ofToString( ofRandom(1, 1000), 0) + ".png" );
    
    if ( key == 's' ) {
        ofFileDialogResult res;
        res = ofSystemSaveDialog( "preset.xml", "Saving Preset");
        if ( res.bSuccess ) gui.saveToFile( res.filePath );
    }
    if ( key == 'l' ) {
        ofFileDialogResult res;
        res = ofSystemLoadDialog( "Loading Preset" );
        if ( res.bSuccess ) gui.loadFromFile( res.filePath );
    }
    
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
