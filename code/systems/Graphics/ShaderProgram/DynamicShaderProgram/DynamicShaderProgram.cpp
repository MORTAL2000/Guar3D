#include "DynamicShaderProgram.h"

//stdlib includes
#include <stdio.h>
#include <stdexcept>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include <debug\Debug.h>

using namespace guar;
using namespace GFX;

DynamicShaderProgram::DynamicShaderProgram(const std::string &aFileName) : ShaderProgram()
{
	Debug::alert("Loading dynamic shaderprogram from file\"", aFileName, "\"\n");
    
	m_ShaderDrawCallCallInterpreter = 0;
    m_Name = aFileName;
    
    m_ShaderDrawCallCallInterpreter = new ShaderDrawCallInterpreter();
    
    std::string drawCode, vertexCode, fragmentCode;
    
    processShaderSourceFile(aFileName, drawCode, vertexCode, fragmentCode);
    parseDrawCode(drawCode);
    compileGraphicsProgram(vertexCode, fragmentCode);
    

    Debug::log("ShaderProgram::ShaderProgram : ", m_ShaderDrawCallCallInterpreter, "\n");
    
}

void DynamicShaderProgram::glDrawCalls()
{
    m_ShaderDrawCallCallInterpreter->call();
    
}

DynamicShaderProgram::DynamicShaderProgram(const DynamicShaderProgram& b)
{
    Debug::log(m_ShaderDrawCallCallInterpreter, ", ", b.m_ShaderDrawCallCallInterpreter, "\n");
    
    //Allocate the memory first
    m_ShaderDrawCallCallInterpreter = new ShaderDrawCallInterpreter();
    *m_ShaderDrawCallCallInterpreter = *b.m_ShaderDrawCallCallInterpreter;
    
    Debug::log(m_ShaderDrawCallCallInterpreter, ", ", b.m_ShaderDrawCallCallInterpreter, "\n");
    Debug::log("ShaderProgram::ShaderProgram(const ShaderProgram& b)\n");
    
}


void DynamicShaderProgram::parseDrawCode(const std::string &aDrawCode)
{
    printf("Checking draw code's Lua syntax... ");
    
    //printf("\n**LUAFILE**\n%s\n\n",aDrawCode.c_str());
    
    try
    {
        m_ShaderDrawCallCallInterpreter->loadLuaSourceFromString(aDrawCode);//.loadLuaSourceFromFile("../scripts/script.lua");
    
    }
    catch (const std::runtime_error &e)
    {
         Debug::log("Lua error!\n");
         Debug::log(e.what());
         return;
        
    }
    
    Debug::log("Lua is good!\n");
    
    try
    {
        m_ShaderDrawCallCallInterpreter->call();
    
    }
    catch (const std::runtime_error &e)
    {
        Debug::log(e.what());
        return;
    }
    
    //tset(m_ShaderDrawCallInterpreter);
    
}