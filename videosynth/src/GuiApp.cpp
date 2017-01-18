#include "GuiApp.h"

void GuiApp::setup(){

    gui = new ofxDatGui( 10, 10 ); //ofxDatGuiAnchor::TOP_LEFT

    ofxDatGuiSlider* countXsl = gui->addSlider("countX", 0, 200, 50);
    gui->getSlider("countX")->setPrecision(0);

    ofxDatGuiSlider* stepXsl = gui->addSlider("stepX", 0, 200, 20);
    gui->getSlider("stepX")->setPrecision(0);

    ofxDatGuiSlider* twistXsl = gui->addSlider("twistX", -45, 45, 5);

    ofxDatGuiSlider* countYsl = gui->addSlider("countY", 0, 50, 0);
    gui->getSlider("countY")->setPrecision(0);

    ofxDatGuiSlider* stepYsl = gui->addSlider("stepY", 0, 200, 20);
    gui->getSlider("stepY")->setPrecision(0);

    ofxDatGuiSlider* twistYsl = gui->addSlider("twistY", -30, 30, 0);
    ofxDatGuiSlider* pinchYsl = gui->addSlider("pinchY", 0, 1, 0);

    ofxDatGuiSlider* Scalesl = gui->addSlider("Scale", 0, 1.0, 1);
    ofxDatGuiSlider* Rotatesl = gui->addSlider("Rotate", -180, 180, 0);
    ofxDatGuiSlider* Backgroundsl = gui->addSlider("Background", 0, 255, 0);
    ofxDatGuiSlider* shiftYsl = gui->addSlider("shiftY", -1000.0, 1000.0, 0);
    ofxDatGuiSlider* rotatesl = gui->addSlider("rotate", -180, 180, 0);

    ofxDatGuiSlider* sizeXsl = gui->addSlider("size(x)", 0, 20, 0.5);
    ofxDatGuiSlider* sizeYsl = gui->addSlider("size(y)", 0, 20, 0.5);

    ofxDatGuiSlider* imageAlphasl = gui->addSlider("imageAlpha", 0, 255, 100);
    ofxDatGuiSlider* cameraAlphasl = gui->addSlider("cameraAlpha", 0, 255, 200);
    ofxDatGuiSlider* videoAlphasl = gui->addSlider("videoAlpha", 0, 255, 100);

    ofxDatGuiSlider* ksectorssl = gui->addSlider("ksectors", 1, 100, 10);
    gui->getSlider("ksectors")->setPrecision(0);

    ofxDatGuiSlider* kanglesl = gui->addSlider("kangle", -180, 180, 0);
    ofxDatGuiSlider* kxsl = gui->addSlider("kx", 0, 1, 0.5);
    ofxDatGuiSlider* kysl = gui->addSlider("ky", 0, 1, 0.5);

    ofxDatGuiSlider* volumesl = gui->addSlider("Volume", 0, 1, 0.25);

    ofxDatGuiToggle* kenabledTgl = gui->addToggle("kenabled", false);

    ofxDatGuiButton* skipfwdBtn = gui->addButton("skipfwd");
    ofxDatGuiButton* skipbackBtn = gui->addButton("skipback");

//    gui->getButton("kenabled")->onButtonEvent(this, &GuiApp::onButtonEvent);

    gui->onButtonEvent(this, &GuiApp::onButtonEvent);

    //gui.setup( "Parameters", "settings.xml" );

    countXsl->bind(countX);
    stepXsl->bind(stepX);
    twistXsl->bind(twistX);
    countYsl->bind(countY);
    stepYsl->bind(stepY);
    twistYsl->bind(twistY);
    pinchYsl->bind(pinchY);
    Scalesl->bind(Scale);
    Rotatesl->bind(Rotate);
    Backgroundsl->bind(Background);
    shiftYsl->bind(shiftY);
    rotatesl->bind(rotate);
    ksectorssl->bind(ksectors);
    kanglesl->bind(kangle);
    kxsl->bind(kx);
    kysl->bind(ky);
    sizeXsl->bind(sizeX);
    sizeYsl->bind(sizeY);
    imageAlphasl->bind(imageAlpha);
    cameraAlphasl->bind(cameraAlpha);
    videoAlphasl->bind(videoAlpha);
    volumesl->bind(volume);

}

void GuiApp::onButtonEvent(ofxDatGuiButtonEvent e) {

    cout << e.target->getName() << endl;
    string clicked = e.target->getName();

    if (clicked == "kenabled") {
        kenabled = !kenabled;
        cout << kenabled << endl;
    }

    if (clicked == "skipfwd") {
        skipFwd = true;
        cout << "skip fwd" << endl;
    }

    if (clicked == "skipback") {
        skipBack = true;
        cout << "skip back" << endl;
    }
}

void GuiApp::skipFwdPressed(){
    skipFwd=true;
}

void GuiApp::skipBackPressed(){
    skipBack=true;
}

void GuiApp::update(){

}

void GuiApp::draw(){
    //gui.draw();
}

//--------------------------------------------------------------
void GuiApp::exit() {
    //gui.saveToFile( "settings.xml" );
}
