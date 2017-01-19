// Author @patriciogv - 2015
// http://patriciogonzalezvivo.com

#ifdef GL_ES
precision mediump float;
#endif

//uniform vec2 u_resolution;
//uniform vec2 u_mouse;
//uniform float u_time;

//float rect(vec2 st, float startX, float startY, float width, float height){
//        return(step(startX,st.x) - step(startX + width, st.x)) * (step(startY, st.y) - step(startY + height, st.y));
//}

//void main() {

//    vec2 st = gl_FragCoord.xy/u_resolution.xy;
//    vec3 color = vec3(0.0);
    
//    // left

//    float start=0.0;
//    //float w=0.1;
//    float w = (1.+sin(u_time))/2.; // rescaled to 0.0 .. 1.0;
//    float l = 1.0-(step(start, st.x) - step(start+w,st.x));

//    float pct = l;

//    // bottom-left
//    //vec2 bl = step(vec2(0.1),st);
//    //float pct = bl.x * bl.y;

//    // top-right
//    // vec2 tr = step(vec2(0.1),1.0-st);
//    // pct *= tr.x * tr.y;


    
//    color = vec3(pct);

//    gl_FragColor = vec4(color, 1.0);


//}


uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

// Plot a line on Y using a value between 0.0-1.0
float plot(vec2 st, float pct) {

  return  smoothstep( pct-0.008, pct, st.y) -
          smoothstep( pct, pct+0.008, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    float v = st.x;
    //float v = step(u_mouse.x/u_resolution.x, st.x);

    vec3 color = vec3(v);

    // Plot a line
    float pct = plot(st,v);
    color = (1.0-pct)*color+pct*vec3(0.0,1.0,0.0);

    gl_FragColor = vec4(color,1.0);
}
