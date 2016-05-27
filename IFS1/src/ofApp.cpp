#include "ofApp.h"

std::string uint64_to_string( uint64_t value ) {
    std::ostringstream os;
    os << value;
    return os.str();
}

//----- my init function for selecting transforms  ---//
void ofApp::init() {
  count = 0;

  //x=0.0; y=0.0;
  x = ofRandom(min, max);
  y = ofRandom(min, max);

  // initialise array of hit counts;
  points.resize(wh);
  std::fill(points.begin(), points.end(), 0);

  // set random start point
  ix = ofRandom(min, max);
  iy = ofRandom(min, max);

  // see http://openframeworks.cc/ofBook/chapters/how_of_works.html
  pixels.allocate(width, height, OF_IMAGE_COLOR_ALPHA);
  pixels.set(0);

  tex.allocate(width, height, GL_RGBA);

  size_t size = 6;
  transforms.clear();

  // create/initialise transforms.
  for (int i=0; i<nt; i++){

    vector<float> t;
//    float theta = ofRandom(PI);

    for (int j=0; j<size-2; ++j) {
        float r1 = ofRandom(min, max);
        //if (ofRandom(1.0) < 0.5) r1 = -r1;
        t.push_back(r1);
    }

    for (int j=size-2; j<size; ++j) {
        float r2 = ofRandom(min/1.05, max/1.05);
        //if (ofRandom(1.0) < 0.5) r2 = -r2;
        t.push_back(r2);
    }

    //t[1] = 0.0;
    t[2] = -1.0*t[1];

    t[0] = t[4];
    //t[1] = -1.0*t[3];

    //t[4] = t[5];

    /*
    cout << theta*RAD_TO_DEG << ", " << sin(theta) << ", " << cos(theta) << endl;
    t.push_back(cos(theta));
    t.push_back(-sin(theta));

    t.push_back(sin(theta));
    t.push_back(cos(theta));

    t.push_back(ofRandom(-0.5, 0.5));
    t.push_back(ofRandom(-0.5, 0.5));
*/

    // cout << t[0] << ", " << t[1] << ", " << t[2] << ", " << t[3] << ", " << t[4] << ", " << t[5] << ", " << endl;
    transforms.push_back(t);

  }

/*{
  // SIERPINSKI
  transforms.clear();
  vector<float> t;

  t.push_back(0.5);
  t.push_back(0.0);

  t.push_back(0.0);
  t.push_back(0.5);

  t.push_back(0.0);
  t.push_back(0.0);

  transforms.push_back(t);

  t.clear();

  t.push_back(0.5);
  t.push_back(0.0);

  t.push_back(0.0);
  t.push_back(0.5);

  t.push_back(0.25);
  t.push_back(0.0);

  transforms.push_back(t);

  t.clear();

  t.push_back(0.5);
  t.push_back(0.0);

  t.push_back(0.0);
  t.push_back(0.5);

  t.push_back(0.0);
  t.push_back(0.25);

  transforms.push_back(t);
}*/
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

      //int tn = (int)ofRandom(0,nt);
      int tn = chooseTransform(nt);

      vector<float> tr = transforms[tn];

      double  (*fp1)(double);
      double  (*fp2)(double);

      fp1 = sin;
      fp2 = cos;

      x = fp1(ix*tr[0] + iy*tr[1] + tr[4]);
      y = fp2(ix*tr[2] + iy*tr[3] + tr[5]);

//            if (x<min) x=max;
//            if (X>max) X=min;
//            if (Y<min) Y=max;
//            if (X<max) Y=min;

//      x = ix*tr[0] + iy*tr[1] + tr[2];
//      y = ix*tr[3] + iy*tr[4] + tr[5];

 //     ofPoint xy = ofPoint(x,y);

      // store points, if inside view
      X = (int)ofMap(x, min, max, 20, width-21, true);   // clamp
      Y = (int)ofMap(y, min, max, 20, height-21, true);  // clamp

      //if (X>20 && X<width-20 && Y>20 && Y<height-20) {
        points[Y*width+X] += 1;
      //}

//      if (X<20) X==width-20;
//      if (X>(width-20)) X==20;
//      if (Y<20) Y==height-20;
//      if (X<20) Y==20;

//      points[Y*width+X] += 1;

      ix=x;
      iy=y;
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

        // via: https://forum.openframeworks.cc/t/solved-saving-as-pdf-or-png-off-screen-drawing/9724/2
        //fbo.readToPixels(pix);
        //ofSaveImage(pix, "testimage.png", OF_IMAGE_QUALITY_BEST);

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
    cout << "resetting" << endl;
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

