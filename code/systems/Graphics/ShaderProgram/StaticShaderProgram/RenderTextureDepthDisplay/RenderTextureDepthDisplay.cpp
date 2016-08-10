#include "RenderTextureDepthDisplay.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;

staticShaders::RenderTextureDepthDisplay::RenderTextureDepthDisplay() : StaticShaderProgram::StaticShaderProgram("RenderTextureDepthDisplay",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void staticShaders::RenderTextureDepthDisplay::glDrawCalls(void)
{
	
}

//
// Vertex GLSL
//
std::string staticShaders::RenderTextureDepthDisplay::vertexShaderGLSL(void)
{
	return
		R"V0G0N(

#version 150

uniform mat4 _MVP;

in vec3 a_Position;
in vec2 a_UV;
in vec3 a_Normal;

out vec3 fragVert;
out vec2 fragTexCoord;
out vec3 fragNormal;

void main() 
{
    gl_Position = _MVP * vec4(a_Position, 1) ;
	
    // Pass some variables to the fragment shader
    fragTexCoord = a_UV       ;
    fragNormal   = a_Normal   ;
    fragVert     = a_Position ;
	
}

)V0G0N";
    
}

//
// Fragment GLSL
//
std::string staticShaders::RenderTextureDepthDisplay::fragmentShaderGLSL(void)
{
	return
		R"V0G0N(

#version 150

uniform mat4 _ModelMatrix;
uniform sampler2D _Texture;
uniform vec3 _Light1Position;
uniform mat4 _InverseTransposeModelMatrix;

uniform vec3 _CameraPosition;

//uniform struct Light 
//{
//   vec3 position;
//   vec3 intensities; //a.k.a the color of the light
//} light;

in vec2 fragTexCoord;
in vec3 fragNormal;
in vec3 fragVert;

out vec4 finalColor;

float LinearizeDepth(vec2 uv)
{
	uv.y = 1 + uv.y*-1;

	float n = -0.10; // camera z near
	float f = 200.0; // camera z far
	float z = texture2D(_Texture, uv).x;
	return (2.0 * n) / (f + n - z * (f - n));	

}

void main() 
{
	vec2 uv = fragTexCoord;

	finalColor = vec4(vec3(LinearizeDepth(uv)),1.0);
	
}

)V0G0N";
    
}
