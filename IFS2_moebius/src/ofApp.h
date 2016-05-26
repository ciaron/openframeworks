#pragma once

#include "ofMain.h"

#include <complex.h>
//complex<double> a, b, c, d;
//vector<complex<double>> tr;
//vector<complex<double>[]> transforms;

class ofApp : public ofBaseApp{

    int wh; // resolution, i.e. width*height;
    //double x, y, ix, iy;
    int X, Y;
    double min = -1.0;
    double max = 1.0;

    double m1 = -1.0;
    double m2 =  1.0;
    double m3 = -1.0;
    double m4 =  1.0;

    int count;
    int nt = 5; // num transforms
    int np = 200000; // num points

    int width, height;

    vector<vector<complex<double>>> transforms;
    vector<int> points;  // 'hit count' for pixels

    complex<double> z, zn;
    //complex<double> a, b, c, d;

    ofPixels pixels;
    ofTexture tex;

    // for screenshots
    ofImage img;

    //float probs[6] = {1.0/6, 2.0/6, 3.0/6, 4.0/6, 5.0/6, 6.0/6};
    float probs[5] = {0.2, 0.4, 0.6, 0.8, 1.0};
//    float probs[4] = {0.25, 0.5, 0.75, 1.0};
    //float probs[3] = {0.33, 0.66, 1.0};
    //float probs[2] = {0.5, 1.0};
    //float probs[1] = {1.0};

	public:
        void init();

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
        int chooseTransform(int n);
		
};
