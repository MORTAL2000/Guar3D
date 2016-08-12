#include "RenderObject.h"

#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"
#include "../StandardUniforms/StandardUniforms.h"
#include "../RenderCamera/RenderCamera.h"
#include "../RenderLight/RenderLight.h"
#include "../Texture/Texture.h"
#include "../RenderTexture/RenderTexture.h"
#include "../ShaderProgram/ShaderProgram.h"
#include "../Model/Model.h"

//#include <iostream>
#include <string>
#include <memory>

using namespace guar;
using namespace GFX;

RenderObject::RenderObject() :
	m_Model(0),
	m_ShaderProgram(0),
	m_Position(),
	m_Rotation(),
	m_Scale(1.0f),
	m_TextureUniforms()
{}

RenderObject::RenderObject(Model* aModel, ShaderProgram* aShaderProgram) : 
	m_Model(aModel), 
	m_ShaderProgram(aShaderProgram),
	m_Position(0, 0, 0),
	m_Rotation(0, 0, 0),
	m_Scale(1.0f)
{}

void RenderObject::draw(RenderObserver& aCamera, std::vector<RenderLight> &aLights)
 {
    GFXuint shaderProgramHandle = m_ShaderProgram->getProgramHandle();

	glUseProgram(shaderProgramHandle);

	StandardUniforms::loadStandardUniforms(*this, &aCamera, aLights,m_TextureUniforms);
    m_ShaderProgram->draw();
    m_Model->draw(shaderProgramHandle);
     
 }

//std::string RenderObject::getShaderName(void)
//{
//	return m_ShaderProgram->getName();
//
//}

RenderObject::RenderObject(const RenderObject& aRenderObject)
{
	m_Model         = aRenderObject.m_Model;
	m_ShaderProgram = aRenderObject.m_ShaderProgram;
	m_Position      = aRenderObject.m_Position;
	m_Rotation      = aRenderObject.m_Rotation;
	m_Scale	        = aRenderObject.m_Scale;

}

ShaderProgram* RenderObject::getShaderProgram(void)
{
	return m_ShaderProgram;

}

void RenderObject::setTexture(const std::string &aUniformName, const std::string &aTextureName)
{
	m_TextureUniforms.insert(std::pair<std::string, std::weak_ptr<Texture>>(aUniformName, Graphics::getTexture(aTextureName)));

}

void RenderObject::setTexture(const std::string &aUniformName, Texture* aTexture)
{
	m_TextureUniforms.insert(std::pair<std::string, Texture*>(aUniformName, aTexture));


}