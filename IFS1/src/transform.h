#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "ofMain.h"

class Transform
{

public:
    Transform(double _min, double _max);

    void setup(double _a, double _b, double _c, double _d, double _e, double _f);

    //vector<double> params;

    ofParameterGroup transformParams;
    ofParameter<double> a;
    ofParameter<double> b;
    ofParameter<double> c;
    ofParameter<double> d;
    ofParameter<double> e;
    ofParameter<double> f;

//    void set(vector<double> _params);
//    vector<double> get();

};

#endif // TRANSFORM_H
