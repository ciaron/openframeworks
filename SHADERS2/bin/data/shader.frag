#version 130
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable
 
void main()
{
    //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);

    gl_FragColor = gl_Color;
}
