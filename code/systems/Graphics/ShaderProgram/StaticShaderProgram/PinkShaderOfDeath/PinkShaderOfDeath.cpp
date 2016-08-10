#include "PinkShaderOfDeath.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;

staticShaders::PinkShaderOfDeath::PinkShaderOfDeath() : StaticShaderProgram::StaticShaderProgram("PinkShaderOfDeath",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void staticShaders::PinkShaderOfDeath::glDrawCalls(void)
{
    //glClearColor(0.0f,1.0f,0.0f,0.0f);
    
}

//
// Vertex GLSL
//
std::string staticShaders::PinkShaderOfDeath::vertexShaderGLSL(void)
{
    return

R"V0G0N(
        
    //VertIn
    attribute vec3 a_Position;
    
    //Uniforms
    uniform mat4 _MVP;
    
    void main ()                        
    {
        gl_Position = _MVP * vec4(a_Position,1.0);  
    
    }           

)V0G0N";
    
}

//
// Fragment GLSL
//
std::string staticShaders::PinkShaderOfDeath::fragmentShaderGLSL(void)
{
    return
    
R"V0G0N(

    void main()                            
    {                                      
        gl_FragColor = vec4(1,0.2,0.8,1);
    
    }

)V0G0N";
    
}
