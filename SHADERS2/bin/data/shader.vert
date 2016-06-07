#version 130
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform mat4 uModelViewMatrix;
uniform mat4 uModelViewProjectionMatrix;
uniform mat3 uNormalMatrix;

in vec4 aVertex;
in vec4 aNormal;
in vec4 aColor;

out vec4 vColor;
out vec3 vMCposition;
out float vLightIntensity;

const vec3 LIGHTPOS = vec3( 3., 5., 10. );

void main( )
{
         vec3 transNorm  = normalize( uNormalMatrix * aNormal );
         vec3 ECposition = vec3( uModelViewMatrix * aVertex );
         vLightIntensity = dot(normalize(LIGHTPOS - ECposition), transNorm);
         vLightIntensity = abs( vLightIntensity );
         vColor = aColor;
         vMCposition = aVertex.xyz;
         gl_Position = uModelViewProjectionMatrix * aVertex;
}
