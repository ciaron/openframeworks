#include "ofApp.h"

/*
 * From FLAME paper (DRAVES): catalog of variations
 *
  r = sqrt(x^2 + y^2)
  θ = arctan(x/y)
  φ = arctan(y/x)

(a, b, c, d, e, f ) are considered to be the affine transform coefficients for a
variation, and are used in dependent variations. Ω is a random variable that is
either 0 or π. Λ is a random variable that is either -1 or 1. Ψ is a random variable
uniformally distributed on the interval [0, 1]. The ’trunc’ function returns the
integer part of a floating-point value.

φ - phi
Ψ - psi
Λ - lambda

 */

// SINUSOIDAL - variation 1
ofPoint sinusoidal(ofPoint xy) {

    return ofPoint(sin(xy.x), sin(xy.y));
}

// SPHERICAL - variation 2
ofPoint spherical(ofPoint xy) {
    float factor = 2.0;
    double x = xy.x;
    double y = xy.y;
    double r2 = (x*x + y*y);
    return ofPoint(x/r2/factor, y/r2/factor);

}

// SWIRL - variation 3
ofPoint swirl(ofPoint xy) {
    double x = xy.x;
    double y = xy.y;
    double r2 = (x*x + y*y);
    return ofPoint(x*(sin(r2)) - y*cos(r2), y = x*(cos(r2)) + y*sin(r2));

}

// HORSESHOE - variation 4
ofPoint horseshoe(ofPoint xy) {
    double x = xy.x;
    double y = xy.y;
    double r = sqrt(x*x + y*y);
    return ofPoint(((x-y)*(x+y)) / r, (2*x*y) / r);

}

// BENT - variation 14
ofPoint bent(ofPoint xy) {
    double x = xy.x;
    double y = xy.y;

    if (x>=0.0 && y>=0.0) {
        return ofPoint(x,y);

    } else if (x<0.0 && y>=0.0) {
        return ofPoint(2*x, y);

    } else if (x>=0.0 && y<0.0) {
        return ofPoint(x, y/2.);

    } else if (x<0.0 && y<0.0) {
        return ofPoint(2*x, y/2.);

    }

}

// POLAR - variation 5
ofPoint polar(ofPoint xy) {
    double x = xy.x;
    double y = xy.y;
    double r = sqrt(x*x + y*y);
    double theta = atan2(x, y);
    return ofPoint(theta/PI, r-1);

}
