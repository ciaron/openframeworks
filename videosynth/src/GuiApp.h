#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class GuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void exit();

    void onButtonEvent(ofxDatGuiButtonEvent e);

    //ofxPanel gui;
    ofxDatGui* gui;

//    ofxColorSlider color;
    ofColor color = (0, 255, 0); // colorPicker?

//    ofxToggle filled,
//    ofxToggle type;

//    ofxToggle kenabled;

//    ofxButton skipfwd;
//    ofxButton skipback;

    void skipFwdPressed();
    void skipBackPressed();

    bool skipFwd=false;
    bool skipBack=false;

    int skipSecs = 5;

    int countX, countY;
    float stepX, stepY;
    float twistX, twistY;
    float pinchY;

    float Scale, Rotate, Background, shiftY, rotate;

    int ksectors;
    float kangle;
    float kx;
    float ky;

    int sizeX, sizeY;

    bool filled = false;
    bool type = false;

    bool kenabled = true;

    float imageAlpha;
    float cameraAlpha;
    float videoAlpha;

    float volume;
};
