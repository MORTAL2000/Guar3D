#include "ShaderProgramCollection.h"
//gfx inc
#include "../../ShaderProgram/DynamicShaderProgram/DynamicShaderProgram.h"
#include "../../ShaderProgram/StaticShaderProgram/StaticShaderProgram.h"
#include "../../ShaderProgram/StaticShaderProgram/PinkShaderOfDeath/PinkShaderOfDeath.h"
#include "../../ShaderProgram/StaticShaderProgram/AlphaCutOff/AlphaCutOff.h"
#include "../../ShaderProgram/StaticShaderProgram/Skybox/Skybox.h"
#include "../../ShaderProgram/StaticShaderProgram/Opaque/Opaque.h"
#include "../../ShaderProgram/StaticShaderProgram/RenderTextureColorDisplay/RenderTextureColorDisplay.h"
#include "../../ShaderProgram/StaticShaderProgram/RenderTextureDepthDisplay/RenderTextureDepthDisplay.h"
//std inc
#include <memory>

using namespace guar;
using namespace GFX;

ShaderProgramCollection::ShaderProgramCollection()
{
	m_FileTypes.push_back(".shader");

}

template<class T>
void ShaderProgramCollection::loadStaticShader()
{
	try
	{
		std::shared_ptr<StaticShaderProgram> object = std::shared_ptr<StaticShaderProgram>(new T());
		m_Vector.push_back(object);

	}

	catch (std::runtime_error& e)
	{
		std::cout << e.what() << "\n";

	}

}

void ShaderProgramCollection::init(void)
{
	loadStaticShader<staticShaders::PinkShaderOfDeath>();
    loadStaticShader<staticShaders::AlphaCutOff>();
	loadStaticShader<staticShaders::Skybox>();
	loadStaticShader<staticShaders::Opaque>();
	loadStaticShader<staticShaders::RenderTextureColorDisplay>();
	loadStaticShader<staticShaders::RenderTextureDepthDisplay>();
    
}
