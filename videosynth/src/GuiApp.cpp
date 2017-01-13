#include "GuiApp.h"
//#include "ofxDatGui.h"

void GuiApp::setup(){

    gui = new ofxDatGui( 10, 10 ); //ofxDatGuiAnchor::TOP_LEFT

    ofxDatGuiSlider* countXsl = gui->addSlider("countX", 0, 200, 50);
    gui->getSlider("countX")->setPrecision(0);

    ofxDatGuiSlider* stepXsl = gui->addSlider("stepX", 0, 200, 20);
    ofxDatGuiSlider* twistXsl = gui->addSlider("twistX", -45, 45, 5);

    ofxDatGuiSlider* countYsl = gui->addSlider("countY", 0, 50, 0);
    ofxDatGuiSlider* stepYsl = gui->addSlider("stepY", 0, 200, 20);
    ofxDatGuiSlider* twistYsl = gui->addSlider("twistY", -30, 30, 0);
    ofxDatGuiSlider* pinchYsl = gui->addSlider("pinchY", 0, 1, 0);

    ofxDatGuiSlider* Scalesl = gui->addSlider("Scale", 0, 1.0, 1);
    ofxDatGuiSlider* Rotatesl = gui->addSlider("Rotate", -180, 180, 0);
    ofxDatGuiSlider* Backgroundsl = gui->addSlider("Background", 0, 255, 0);
    ofxDatGuiSlider* shiftYsl = gui->addSlider("shiftY", -1000.0, 1000.0, 0);
    ofxDatGuiSlider* rotatesl = gui->addSlider("rotate", -180, 180, 0);

    ofxDatGuiSlider* sizeXsl = gui->addSlider("size(x)", 0, 20, 10);
    ofxDatGuiSlider* sizeYsl = gui->addSlider("size(y)", 0, 20, 10);
    //    ofxFloatSlider imageAlpha;
    //    ofxFloatSlider cameraAlpha;
    //    ofxFloatSlider videoAlpha;
    ofxDatGuiSlider* imageAlphasl = gui->addSlider("imageAlpha", 0, 255, 100);
    ofxDatGuiSlider* cameraAlphasl = gui->addSlider("cameraAlpha", 0, 255, 200);
    ofxDatGuiSlider* videoAlphasl = gui->addSlider("videoAlpha", 0, 255, 100);

    ofxDatGuiSlider* ksectorssl = gui->addSlider("ksectors", 1, 100, 10);
    ofxDatGuiSlider* kanglesl = gui->addSlider("kangle", -180, 180, 0);
    ofxDatGuiSlider* kxsl = gui->addSlider("kx", 0, 1, 0.5);
    ofxDatGuiSlider* kysl = gui->addSlider("ky", 0, 1, 0.5);

    //gui.setup( "Parameters", "settings.xml" );

    //gui.add( countXsl.setup( "countX", 50, 0, 200 ) );
    countXsl->bind(countX);

    //gui.add( stepXsl.setup( "stepX", 20, 0, 200 ) );
    stepXsl->bind(stepX);

    //gui.add( twistXsl.setup( "twistX", 5, -45, 45 ) );
    twistXsl->bind(twistX);

    //gui.add( countY.setup( "countY", 0, 0, 50) );
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

//    gui.add( stepY.setup( "stepY", 20, 0, 200 ) );
//    gui.add( twistY.setup( "twistY", 0, -30, 30 ) );
    //gui.add( pinchY.setup( "pinchY", 0, 0, 1 ) );

//    globalGroup.setup( "Global" );
//    globalGroup.add( Scale.setup( "Scale", 1, 0.0, 1 ) );
//    globalGroup.add( Rotate.setup( "Rotate", 0, -180, 180 ) );
//    //globalGroup.add( Background.setup( "Background", 255, 0, 255 ) );		//white background (book's version)
//    globalGroup.add( Background.setup( "Background", 0, 0, 255 ) );			//black background (is convenient for direct starting this example)
//    gui.add( &globalGroup );

//    primGroup.setup( "Primitive" );
//    primGroup.add( shiftY.setup( "shiftY", 0.0, -1000.0, 1000.0 ) );
//    primGroup.add( rotate.setup( "rotate", 0.0, -180.0, 180.0 ) );
//    primGroup.add( size.setup( "size",
//                              ofVec2f(6,6),
//                              ofVec2f(0,0),
//                              ofVec2f(20,20) ) );
//    //color.setDefaultBackgroundColor( ofColor::gray );
//    primGroup.add( color.setup( "color",
//                               ofColor::black,
//                               ofColor(0,0,0,0),
//                               ofColor::white ) );
//    primGroup.add( filled.setup( "filled", false ) );
//    primGroup.add( type.setup( "type", false ) );
//    gui.add( &primGroup );

//    mixerGroup.setup( "Mixer" );
//    mixerGroup.setHeaderBackgroundColor( ofColor::darkRed );
//    mixerGroup.setBorderColor( ofColor::darkRed );

//    mixerGroup.add( imageAlpha.setup( "image", 100,0,255 ) );
//    mixerGroup.add( videoAlpha.setup( "video", 200,0,255 ) );
//    mixerGroup.add( cameraAlpha.setup( "camera", 100,0,255 ) );

//    mixerGroup.add( kenabled.setup( "kenabled", true ) );
//    mixerGroup.add( ksectors.setup( "ksectors", 10, 1, 100 ) );
//    mixerGroup.add( kangle.setup( "kangle", 0, -180, 180 ) );
//    mixerGroup.add( kx.setup( "kx", 0.5, 0, 1 ) );
//    mixerGroup.add( ky.setup( "ky", 0.5, 0, 1 ) );

//    // video volume control
//    mixerGroup.add( volume.setup( "volume", 0.5, 0, 1 ) );

//    //video skip fwd/back

//    string s1 = string("Skip +") + to_string(skipSecs) + string("s");
//    string s2 = string("Skip -") + to_string(skipSecs) + string("s");

//    mixerGroup.add( skipfwd.setup( "Skip +5s" , 50,20) );
//    mixerGroup.add( skipback.setup( "Skip -5s" , 50, 20) );

//    skipfwd.addListener(this, &GuiApp::skipFwdPressed);
//    skipback.addListener(this, &GuiApp::skipBackPressed);

    //gui.minimizeAll();
    //gui.add( &mixerGroup );

    //gui.loadFromFile( "settings.xml" );

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
