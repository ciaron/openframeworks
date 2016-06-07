#version 130
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

// these are for the programmable pipeline system
uniform mat4 modelViewProjectionMatrix;
in vec4 pos;

uniform float phase = 0.0;
uniform float distortAmount = 0.25;

void main()
{

    //Get original position of the vertex
    vec3 v = gl_Vertex.xyz;

    //Compute value of distortion for current vertex
    float distort = distortAmount * sin( phase + 0.015 * v.z );

    //Move the position
    v.x /= 1.0 + distort;
    v.y /= 1.0 + distort;
    v.z /= 1.0 + distort;
    //v.x *= distort;
    //v.y *= distort;
    //v.z *= distort;

    //Set output vertex position
    vec4 posHomog = vec4( v, 1.0 );
    gl_Position = gl_ModelViewProjectionMatrix * posHomog;

    //Set output texture coordinate and color in a standard way
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;

}
