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
    void onSliderEvent(ofxDatGuiSliderEvent e);
    void onColorPickerEvent(ofxDatGuiColorPickerEvent e);

    // Initial variables
    int icountX=12;
    int icountY=2;

    int istepX=20;
    int istepY=20;
    float itwistX=5;
    float itwistY=0;
    float ipinchY=0;
    int iBackground=0;
    float iScale=0.5;
    float iRotate=0;
    float ishiftY=0;
    float irotate=0;
    float isizeX=20;
    float isizeY=20;
    float iimageAlpha=0.0;
    float icameraAlpha=0.0;
    float ivideoAlpha=255.0;
    float ishapeAlpha=255.0;
    int iksectors=10;
    float ikangle=0;
    float iVolume=0.01;
    float ikx=0.5;
    float iky=0.5;

    bool ikenabled = true;
    bool ifilled = false;
    bool itype = false;

    // END initialisation

    ofxDatGui* gui;

//    ofxColorSlider color;
    ofColor color = ofColor(255, 0, 0); // colorPicker?

    bool skipFwd=false;
    bool skipBack=false;

    int skipSecs = 5;

    int countX=icountX;
    int countY=icountY;
    int stepX=istepX;
    int stepY=istepY;
    float twistX=itwistX;
    float twistY=itwistY;
    float pinchY=ipinchY;

    float Scale=iScale;
    float Rotate=iRotate;
    int Background=iBackground;
    float shiftY=ishiftY;
    float rotate=irotate;

    int ksectors=iksectors;
    float kangle=ikangle;
    float kx=ikx;
    float ky=iky;

    float sizeX=isizeX;
    float sizeY=isizeY;

    bool filled = ifilled;
    bool type = itype;

    bool kenabled = true;

    float imageAlpha=iimageAlpha;
    float cameraAlpha=icameraAlpha;
    float videoAlpha=ivideoAlpha;
    float shapeAlpha=ishapeAlpha;

    float volume=iVolume;
};
