#include "ofApp.h"

//----- my init function for selecting transforms  ---//
void ofApp::init() {
  count = 0;

  // initialise array of hit counts;
  points.resize(wh);
  std::fill(points.begin(), points.end(), 0);

  complex<double> zn = (0.0, 0.0);
  complex<double> z = (ofRandom(min, max), ofRandom(min, max));

  // see http://openframeworks.cc/ofBook/chapters/how_of_works.html
  pixels.allocate(width, height, OF_IMAGE_COLOR_ALPHA);
  pixels.set(0);

  tex.allocate(width, height, GL_RGBA);

  size_t size = 6;
  transforms.clear();

  // create/initialise transforms.
  for (int i=0; i<nt; i++) {

    complex<double> a(ofRandom(m1, m2), ofRandom(m1, m2));
    complex<double> b(ofRandom(m3, m4), ofRandom(m3, m4));
    complex<double> c(ofRandom(m1, m2), ofRandom(m1, m2));
    complex<double> d(ofRandom(m3, m4), ofRandom(m3, m4));

    //cout << a << "," << b << endl;
    //cout << c << "," << d << endl;

    vector<complex<double>> t;

    t.push_back(a);
    t.push_back(b);
    t.push_back(c);
    t.push_back(d);

    transforms.push_back(t);

  }


}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    width = ofGetWidth();
    height = ofGetHeight();
    wh = width * height;

    init();
}

int ofApp::chooseTransform(int n){
  //return (int)ofRandom(0,n);

  float r = ofRandom(1.0);

  if (r<probs[0]) {
      return 0;
  } else if (r<probs[1]) {
      return 1;
  } else if (r<probs[2]) {
      return 2;
  } else if (r<probs[3]) {
      return 3;
  } else if (r<probs[4]) {
      return 4;
  } else if (r<probs[5]) {
      return 5;
  }

}

//--------------------------------------------------------------
void ofApp::update(){

  for (int i=0; i<np; i++) {

      int tn = chooseTransform(nt);

      vector<complex<double>> tr = transforms[tn];
      //cout << tr[0] << endl;

      complex<double> a = tr[0];
      complex<double> b = tr[1];
      complex<double> c = tr[2];
      complex<double> d = tr[3];

      zn = (a*z+b) / (c*z+d);

      // store points, if inside view
      X = (int)ofMap(zn.real(), min, max, 0, width-1);
      Y = (int)ofMap(zn.imag(), min, max, 0, height-1);

      if (X>0 && X<width && Y>0 && Y<height) {
        points[Y*width+X] += 1;
      }

      z=zn;
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofEnableAlphaBlending();
  ofBlendMode(OF_BLENDMODE_ADD);

  //ofBackground(0);
  for (int n=0; n<width*height; n++){
      if (points[n] > 0) {
          //pixels.setColor(n*4, ofColor(255,255,255, (int)(ofRandom(0,255))));
          float c = 255*log(points[n])/log(np);
          pixels.setColor(n*4, ofColor(c,c,c));

    }
  }

  tex.loadData(pixels);
  tex.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){

        std::time_t result = std::time(nullptr);
        //std::cout << std::asctime(std::localtime(&result))
        //          << result << " seconds since the Epoch\n";
        std::localtime(&result);

        /*uint64_t ts = ofGetElapsedTimeMillis(); */
        stringstream ss;
        //ss << ts;
        ss << result;
        std::string tss = std::string(12 - ss.str().length(), '0') + ss.str();
        //cout << ss.str() << ", " << tss << endl;

        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("img-" + tss + ".png");

    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // reset the gubbins
    init();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

