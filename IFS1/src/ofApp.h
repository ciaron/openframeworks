#pragma once

#include "ofMain.h"

//#include <complex.h>
//complex<double> a, b, c, d;
//vector<complex<double>> tr;
//vector<complex<double>[]> transforms;

class ofApp : public ofBaseApp{

    int wh; // resolution, i.e. width*height;
    double x, y, ix, iy;
    int X, Y;
    double min = -1.;
    double max = 1.;

    int count;
    const int nt = 4; // num transforms
    int np = 200000; // num points

    int width, height;

    vector<vector<float>> transforms;
    vector<int> points;  // 'hit count' for pixels

    ofPixels pixels;
    ofTexture tex;
    ofFbo fbo;

    // for screenshots
    ofImage img;

    //float probs[12] = {1.0/12, 2.0/12, 3.0/12, 4.0/12, 5.0/12, 6.0/12, 7.0/12, 8.0/12, 9.0/12, 10.0/12, 11.0/12, 12.0/12};
    //float probs[6] = {1.0/6, 2.0/6, 3.0/6, 4.0/6, 5.0/6, 6.0/6};
    //float probs[5] = {0.2, 0.4, 0.6, 0.8, 1.0};
    float probs[4] = {0.25, 0.5, 0.75, 1.0};
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
        string uint64_to_string( uint64_t value );
        int chooseTransform(int n);
		
};
