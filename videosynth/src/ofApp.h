#pragma once

#include "ofMain.h"
#include "GuiApp.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void stripePattern();

    void matrixPattern();
    
    ofTexture image;
    ofVideoPlayer video;
    ofVideoGrabber camera;

    // percent skip fwd/back
    float skip;

    ofFbo fbo;
    void draw2d();
    
    ofShader shader;
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    shared_ptr<GuiApp> gui;

};
