#pragma once

#include "MSAFluid.h"
#include "ParticleSystem.h"
#include "ofMain.h"

#define USE_GUI


#ifdef USE_TUIO
#include "ofxTuio.h"
#define tuioCursorSpeedMult				0.5	// the iphone screen is so small, easy to rack up huge velocities! need to scale down
#define tuioStationaryForce				0.001f	// force exerted when cursor is stationary
#endif

// comment this line out if you don't wanna use TUIO
// you will need ofxTUIO & ofxOsc
//#define USE_TUIO

// comment this line out if you don't wanna use the GUI
// you will need ofxSimpleGuiToo, ofxMSAInteractiveObject & ofxXmlSettings
// if you don't use the GUI, you won't be able to see the fluid parameters
#ifdef USE_GUI
#include "ofxSimpleGuiToo.h"
#endif

class ofApp : public ofBaseApp{

	public:

		void fadeToColor(float r, float g, float b, float speed);
		void addToFluid(ofVec2f pos, ofVec2f vel, bool addColor, bool addForce);

		float                   colorMult;
		float                   velocityMult;
		int                     fluidCellsX;
		bool                    resizeFluid;
		bool                    drawFluid;
		bool                    drawParticles;

		msa::fluid::Solver      fluidSolver;
		msa::fluid::DrawerGl	fluidDrawer;

		ParticleSystem          particleSystem;

		ofVec2f                 pMouse;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		#ifdef USE_TUIO
			ofxTuioClient tuioClient;
		#endif
};