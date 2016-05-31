#include "transform.h"

Transform::Transform(double _min, double _max) {

}

void Transform::setup(double _a, double _b, double _c, double _d, double _e, double _f) {
    transformParams.setName("Transform controls");
    transformParams.add(a.set("a", _a, -2.0, 2.0));
    transformParams.add(b.set("b", _b, -2.0, 2.0));
    transformParams.add(c.set("c", _c, -2.0, 2.0));
    transformParams.add(d.set("d", _d, -2.0, 2.0));
    transformParams.add(e.set("e", _e, -2.0, 2.0));
    transformParams.add(f.set("f", _f, -2.0, 2.0));

    //a.addListener();??

}

