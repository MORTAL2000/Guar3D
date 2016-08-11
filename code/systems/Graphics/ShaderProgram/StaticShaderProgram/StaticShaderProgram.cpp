#include "StaticShaderProgram.h"

#include <Debug\Debug.h>

using namespace guar;
using namespace GFX;

StaticShaderProgram::StaticShaderProgram(const std::string &aName, const std::string &aVertexSource, const std::string &aFragmentSource)
{
	Debug::alert("Constructing static shaderprogram \"", aName, "\"\n");

	m_Name = aName;
    compileGraphicsProgram(aVertexSource,aFragmentSource);
    
}