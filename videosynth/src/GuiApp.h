#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void exit();

//    ofParameterGroup parameters;
//    ofParameter<float> radius;
//    ofParameter<ofColor> color;
//    ofxPanel gui;

    ofxPanel gui;
    ofxIntSlider countX;
    ofxFloatSlider stepX;
    ofxFloatSlider twistX;

    ofxGuiGroup globalGroup;
    ofxFloatSlider Scale;
    ofxFloatSlider Rotate;
    ofxFloatSlider Background;

    ofxGuiGroup primGroup;
    ofxFloatSlider shiftY, rotate;
    ofxVec2Slider size;
    ofxColorSlider color;
    ofxToggle filled, type;

    ofxIntSlider countY;
    ofxFloatSlider stepY, twistY, pinchY;

    ofxGuiGroup mixerGroup;
    ofxFloatSlider imageAlpha, videoAlpha, cameraAlpha;

    ofxToggle kenabled;
    ofxIntSlider ksectors;
    ofxFloatSlider kangle, kx, ky;

};
