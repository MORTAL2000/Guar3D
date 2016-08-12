#include "Skybox.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;
using namespace staticShaders;

Skybox::Skybox() : StaticShaderProgram::StaticShaderProgram("Skybox",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void Skybox::glDrawCalls(void)
{

}

std::string Skybox::vertexShaderGLSL(void)
{
	return
		R"V0G0N(

#version 130

//***********
// Attributes
//***********
//VertIn
in vec3 a_Position;
    
//FragIn
out vec3 v_FragPosition;

//*********
// Uniforms
//*********
uniform mat4 _MVP;

//**************
// Vertex shader
//**************
void main()
{
	//A_POS
    gl_Position = _MVP * vec4((a_Position*3.0),1.0);

	//V_FRAGPOS
	v_FragPosition = a_Position;
                
}

)V0G0N";
    
}

std::string Skybox::fragmentShaderGLSL(void)
{
	return
		R"V0G0N(

//***********
// Attributes
//***********
//Frag in
in vec3 v_FragPosition ;
    
//*********
// Uniforms
//*********

//**********
// Constants
//**********
const vec4 spaceColor   = vec4(0.0000, 0.00000, 6.0, 6.0) ;
const vec4 horizonColor = vec4(0.3294, 0.92157, 1.0, 1.0) ;

//****************
// Fragment shader
//****************
void main()
{
	//normalize frag pos, pulling frags into a spherical surface around 0,0,0.
	//color according to height. 
	//abs creates symmetry around y=0.
	
	vec3 color = mix(horizonColor, spaceColor, abs(normalize(v_FragPosition).y));

    gl_FragColor = vec4(color,1);
	
}
    
)V0G0N";
    
}
