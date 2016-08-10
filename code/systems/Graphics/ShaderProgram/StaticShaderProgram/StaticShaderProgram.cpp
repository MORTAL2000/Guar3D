#include "StaticShaderProgram.h"

using namespace guar;
using namespace GFX;

StaticShaderProgram::StaticShaderProgram(const std::string &aName, const std::string &aVertexSource, const std::string &aFragmentSource)
{
	m_Name = aName;
    compileGraphicsProgram(aVertexSource,aFragmentSource);
    
}