// vertex shader

// the time value is passed into the shader by the OF app.
//uniform float time;

//#version 130

uniform float mouseRange;
uniform vec2 mousePos;
uniform vec4 mouseColor;

//in vec4 position;

void main(){

    // Part 1

    // the sine wave travels along the x-axis (across the screen),
    // so we use the x coordinate of each vertex for the calculation,
    // but we displace all the vertex along the y axis (up the screen)/

//    vec4 position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;

//    float displacementHeight = 100.0;
//    float displacementY = sin(time + (position.x / 100.0)) * displacementHeight;

//    vec4 modifiedPosition = position;
//    modifiedPosition.y += displacementY;
//    gl_Position = modifiedPosition;

    // Part 2
    // copy position so we can work with it.
    //vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    vec4 pos = gl_ModelViewProjectionMatrix * gl_Vertex;

    // direction vector from mouse position to vertex position.
    vec2 dir = pos.xy - mousePos;

    // distance between the mouse position and vertex position.
    float dist = distance(pos.xy, mousePos);

    // check vertex is within mouse range.
    if(dist > 0.0 && dist < mouseRange) {

        // normalise distance between 0 and 1.
        float distNorm = dist / mouseRange;

        // flip it so the closer we are the greater the repulsion.
        distNorm = 1.0 - distNorm;

        // make the direction vector magnitude fade out the further it gets from mouse position.
        dir *= distNorm;

        // add the direction vector to the vertex position.
        pos.x += dir.x;
        pos.y += dir.y;
    }

    // finally set the pos to be that actual position rendered
    gl_Position = pos;

}
