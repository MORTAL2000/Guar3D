#include "ShaderProgram.h"

//project includes
#include "../OpenGL/OpenGLHelper.h"

//implementation includes
#include <jsoncpp/includes/json/reader.h>//"../../../includes/jsoncpp/reader.h"
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"

//debug inc
#include <Debug\Debug.h>

//stdlib includes
#include <stdio.h>
#include <stdexcept>
//#include <iostream>
#include <fstream>
#include <sstream>

using namespace guar;
using namespace GFX;

//
//Static function forward declarations
//
//static void processShaderSourceFile(const std::string &aFileName, std::string &ioDrawCode, std::string &ioVertexCode, std::string &ioFragmentCode);
//
// Ctors
//
ShaderProgram::ShaderProgram() : m_ProgramHandle(0){}

void ShaderProgram::processShaderSourceFile(const std::string &aFileName, std::string &ioDrawCode, std::string &ioVertexCode, std::string &ioFragmentCode)
{
    //1 try to load the file
    printf("opening file \"%s\"\n",aFileName.c_str());
    std::ifstream fileStream(aFileName.c_str());
    
    if (!fileStream) //Throw file !exist error
        throw(std::runtime_error("The file \"" + aFileName + "\" does not exist!\n"));

    printf("file contents successfully opened...\n");
    
    //2 evaluate the file's JSON structure
    std::stringstream fileContents;
    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;
    
    Debug::log("Checking file's file structure... ");
    
    fileContents << fileStream.rdbuf();
    
    if (!reader.parse( fileContents, root )) //Throw JSON interpreter error
        throw(std::runtime_error(" JSON error in \"" + aFileName + "\": " + reader.getFormattedErrorMessages()));            

	Debug::log("JSON success!\n");
    
    //3 pass JSON items on for further processing
    //std::cout << root.get("Draw","asdf").asString();
    
    ioDrawCode = root.get("Draw","DRAW_CONTENT_MISSING_DO_FALLBACK?").asString();
    ioVertexCode = root.get("Vertex","DRAW_CONTENT_MISSING_DO_FALLBACK?").asString();
    ioFragmentCode = root.get("Fragment","DRAW_CONTENT_MISSING_DO_FALLBACK?").asString();
    
}

void ShaderProgram::compileGraphicsProgram(const std::string &aVertexCode, const std::string &aFragmentCode)
{
    const char* vertex_shader = aVertexCode.c_str();
    const char* fragment_shader = aFragmentCode.c_str();
    
	Debug::log("Compiling shader GLSL code\n");
    //std::cout << aVertexCode;
    
	Debug::log("Compiling vertex stage sourcecode\n");
    //run the glsl sources through the compiler, keep handle to both compiled shaders
    GLuint vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vs, 1, &vertex_shader, 0);
    glCompileShader (vs);
    GLHelp::Diagnostics::checkGLSLErrors(vs);
    
	Debug::log("Compiling fragment stage sourcecode\n");
    GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs, 1, &fragment_shader, 0);
    glCompileShader (fs);
	GLHelp::Diagnostics::checkGLSLErrors(fs);
    
	Debug::log("Linking graphics program\n");
    //create the program with the compiled vert and frag shaders
    m_ProgramHandle = glCreateProgram ();
    glAttachShader (m_ProgramHandle, vs);
    glAttachShader (m_ProgramHandle, fs);
    glLinkProgram (m_ProgramHandle);
    
    GLint status;
	glGetProgramiv(m_ProgramHandle, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) 
    {
        //print linker error
		int loglen;
		char logbuffer[1000];
		glGetProgramInfoLog(m_ProgramHandle, sizeof(logbuffer), &loglen, logbuffer);
		Debug::log("OpenGL Program Linker Error at ", logbuffer);
		throw(std::runtime_error("GLSL code could not be compiled!"));
    
    }
    else
    {
		Debug::log("Shader program successfully linked\n");
    
        GLint attributeCount = 0;
        glGetProgramiv(m_ProgramHandle, GL_ACTIVE_ATTRIBUTES, &attributeCount);
        
		Debug::log("handle number: ",(int)m_ProgramHandle, "\n");
		Debug::log("Active attributes: ", attributeCount, "\n");
		
    
    }
    
	GLHelp::Diagnostics::checkGLErrors();
    
}


//
// Interface
//
void ShaderProgram::draw(void)
{   
    
    
    //THIS IS THE SHADER
    //Lua processed graphics command stack
    {
        //HARDCODE DESTROY!!!
        //setup culling
        glEnable   (GL_DEPTH_TEST);
        glEnable   (GL_CULL_FACE);
        glDisable  (GL_CULL_FACE);
        glCullFace (GL_BACK);
        
        glDrawCalls();
        //m_ShaderDrawCallCallInterpreter->call();

    }
    
}