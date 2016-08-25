#include "Renderer.h"

////ecsinc
#include "../../GameObject/GameObject.h"
#include "../Transform/Transform.h"
#include "../Observer/Observer.h"
#include "../../SceneGraph/SceneGraph.h"
//gfxinc
#include "../../../Graphics/RenderObject/RenderObject.h"
#include "../../../Graphics/Graphics.h"
#include <Graphics\SceneGraph\SceneGraph.h>

#include <Debug\Debug.h>

using namespace guar;
using namespace ECS;
using namespace GFX;

void Renderer::init(void)
{
	//m_RenderObject = getGameObject()->getSceneGraph()._Get()->getGraphicsScene()._Get()->createRenderObject();
	
}

void Renderer::update(void)
{
	m_Transform = getGameObject()->findComponent<Transform>();

	m_RenderObject._Get()->setPosition(m_Transform._Get()->getPosition());// m_RenderObject.getPosition
	m_RenderObject._Get()->setRotation(m_Transform._Get()->getRotation());
	m_RenderObject._Get()->setScale   (m_Transform._Get()->getScale   ());
	
}

void Renderer::setModel(const std::string &aModelName)
{
	m_RenderObject._Get()->setModel(Graphics::getModel(aModelName));

}

void Renderer::setShaderProgram(const std::string &aModelName)
{
	m_RenderObject._Get()->setShaderProgram(Graphics::getShaderProgram(aModelName));


}

void Renderer::draw(std::weak_ptr<Observer> aObserver, std::vector<std::weak_ptr<Light>> &aLights)
{
	std::vector<RenderLight> lights;

	for (int i = 0; i < aLights.size(); i++)
		lights.push_back(*aLights[i]._Get()->m_RenderLight._Get());

	RenderObserver* observer = aObserver._Get()->getRenderObserver();

	m_RenderObject._Get()->draw(*observer, lights);

}

void Renderer::setTexture(const std::string &aUniformName, const std::string &aTextureName)
{
	m_RenderObject._Get()->setTexture(aUniformName, aTextureName);
	
}

void Renderer::setTexture(const std::string &aUniformName, std::weak_ptr<GFX::Texture> aTexture)
{
	m_RenderObject._Get()->setTexture(aUniformName, aTexture);

}