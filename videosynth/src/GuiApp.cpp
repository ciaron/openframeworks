#include "GuiApp.h"

void GuiApp::setup(){

    gui = new ofxDatGui( 10, 10 ); //ofxDatGuiAnchor::TOP_LEFT

    gui->addLabel("PARAMETERS");
    gui->addSlider("countX", 0, 200, icountX);
    gui->getSlider("countX")->setPrecision(0);
    gui->addSlider("countY", 0, 50, icountY);
    gui->getSlider("countY")->setPrecision(0);

    gui->addSlider("stepX", 0, 200, istepX);
    gui->getSlider("stepX")->setPrecision(0);
    gui->addSlider("stepY", 0, 200, istepY);
    gui->getSlider("stepY")->setPrecision(0);

    gui->addSlider("twistX", -45, 45, itwistX);
    gui->addSlider("twistY", -30, 30, itwistY);

    gui->addSlider("pinchY", 0, 1, ipinchY);

    gui->addSlider("Scale", 0, 1.0, iScale);
    gui->addSlider("Rotate", -180, 180, iRotate);

    gui->addSlider("shiftY", -1000.0, 1000.0, ishiftY);
    gui->addSlider("rotate", -180, 180, irotate);

    gui->addSlider("sizeX", 0, 200, isizeX);
    gui->addSlider("sizeY", 0, 200, isizeY);

    gui->addToggle("filled",ifilled);
    gui->addToggle("type",itype);

    gui->addLabel("COLOR/ALPHA CONTROLS");

    gui->addSlider("Background", 0, 255, iBackground);
    gui->getSlider("Background")->setPrecision(0);

    gui->addSlider("imageAlpha", 0, 255, iimageAlpha);
    gui->addSlider("cameraAlpha", 0, 255, icameraAlpha);
    gui->addSlider("videoAlpha", 0, 255, ivideoAlpha);

    gui->addLabel("SHADER CONTROLS");

    gui->addToggle("kenabled", ikenabled);

    gui->addSlider("ksectors", 1, 64, iksectors);
    gui->getSlider("ksectors")->setPrecision(0);

    gui->addSlider("kangle", -180, 180, ikangle);
    gui->addSlider("kx", 0, 1, ikx);
    gui->addSlider("ky", 0, 1, iky);

    gui->addLabel("VIDEO CONTROLS");

    gui->addSlider("Volume", 0, 1, iVolume);
    gui->addButton("skipfwd");
    gui->addButton("skipback");

    gui->addFRM(1.0);

    gui->onButtonEvent(this, &GuiApp::onButtonEvent);
    gui->onSliderEvent(this, &GuiApp::onSliderEvent);
    //gui.setup( "Parameters", "settings.xml" );

}

void GuiApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
    cout << "onSliderEvent: " << e.target->getLabel() << " "; e.target->printValue();

    if (e.target->is("countX")) countX = e.value;
    if (e.target->is("countY")) countY = e.value;
    if (e.target->is("stepX")) stepX = e.value;
    if (e.target->is("stepY")) stepY = e.value;
    if (e.target->is("twistX")) twistX = e.value;
    if (e.target->is("twistY")) twistY = e.value;
    if (e.target->is("pinchY")) pinchY = e.value;
    if (e.target->is("Scale")) Scale = e.value;
    if (e.target->is("Rotate")) Rotate = e.value;
    if (e.target->is("Background")) Background = e.value;
    if (e.target->is("shiftY")) shiftY = e.value;
    if (e.target->is("rotate")) rotate = e.value;
    if (e.target->is("sizeX")) sizeX = e.value;
    if (e.target->is("sizeY")) sizeY = e.value;
    if (e.target->is("imageAlpha")) imageAlpha = e.value;
    if (e.target->is("cameraAlpha")) cameraAlpha = e.value;
    if (e.target->is("videoAlpha")) videoAlpha = e.value;
    if (e.target->is("ksectors")) ksectors = e.value;
    if (e.target->is("kangle")) kangle = e.value;
    if (e.target->is("kx")) kx = e.value;
    if (e.target->is("ky")) ky = e.value;
    if (e.target->is("volume")) volume = e.value;

}

void GuiApp::onButtonEvent(ofxDatGuiButtonEvent e) {

    cout << e.target->getName() << endl;
    string clicked = e.target->getName();

    if (clicked == "kenabled") {
        kenabled = !kenabled;
        cout << kenabled << endl;
    }

    if (clicked == "skipfwd") skipFwd = true;
    if (clicked == "skipback") skipBack = true;

    if (clicked == "filled") filled=!filled;
    if (clicked == "type") type=!type;

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
