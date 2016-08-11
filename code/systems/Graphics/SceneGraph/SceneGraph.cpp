#include "SceneGraph.h"

#include "../RenderLight/RenderLight.h"
#include "../RenderObject/RenderObject.h"
#include "../RenderCamera/RenderCamera.h"

using namespace guar;
using namespace GFX;

SceneGraph::SceneGraph(const std::string &aName) :
	m_Name(aName)
{}

void SceneGraph::update(void)
{
	//THIS IS A HACK REMOVE
	std::vector<RenderLight> lights;
	

	//Render from the lights
	for (int i = 0; i < m_Lights.size(); i++)
	{
		m_Lights[i]._Get()->draw();
	
		for (int j = 0; j < m_Objects.size(); j++)
			m_Objects[j]._Get()->draw(*m_Lights[i]._Get(), lights);

	}

	//THIS IS A HACK REMOVE
	for (int i = 0; i < m_Lights.size(); i++)
		lights.push_back(*m_Lights[i]._Get());
	
	//Render from the cameras
	for (int i = 0; i < m_Cameras.size(); i++)
	{
		m_Cameras[i]._Get()->draw();

		for (int j = 0; j < m_Objects.size();)
			m_Objects[j++]._Get()->draw(*m_Cameras[i]._Get(), lights);

	}

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

std::weak_ptr<class RenderLight > SceneGraph::createRenderLight(void)
{//std::weak_ptr<Renderer>(std::dynamic_pointer_cast<Renderer>(m_Components.back()));
	m_Lights.push_back(std::shared_ptr<RenderLight>(new RenderLight()));
	return std::weak_ptr<RenderLight>(std::dynamic_pointer_cast<RenderLight>(m_Lights.back()));

}

std::weak_ptr<class RenderCamera> SceneGraph::createRenderCamera(void)
{
	m_Cameras.push_back(std::shared_ptr<RenderCamera>(new RenderCamera()));
	return std::weak_ptr<RenderCamera>(std::dynamic_pointer_cast<RenderCamera>(m_Cameras.back()));

}

std::weak_ptr<class RenderObject> SceneGraph::createRenderObject(void)
{
	m_Objects.push_back(std::shared_ptr<RenderObject>(new RenderObject()));
	return std::weak_ptr<RenderObject>(std::dynamic_pointer_cast<RenderObject>(m_Objects.back()));

}