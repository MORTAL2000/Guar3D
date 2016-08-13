#include "SceneGraph.h"

#include "../Component/Renderer/Renderer.h"
#include "../Component/Camera/Camera.h"
#include "../Component/Transform/Transform.h"
#include "../GameObject/GameObject.h"
#include <Graphics\Graphics.h>


//#include "../../Graphics/OpenGL/OpenGL.h"

using namespace guar;
using namespace ECS;

SceneGraph::SceneGraph() :
	m_Name("Unnamed Scene")

{}

SceneGraph::SceneGraph(const std::string &aSceneName) :
	m_Name(aSceneName),
	m_GraphicsScene(Graphics::createScene(aSceneName))

{}

void SceneGraph::addRootObject(std::shared_ptr<GameObject> aGameObject)
{ 
	m_RootObjects.push_back(aGameObject); 
	m_RootObjects.back()._Get()->m_SceneGraph = this;
	//m_RootObjects.back()._Get()->init();

}

void SceneGraph::update(void)
{
	for (int i = 0; i < m_RootObjects.size(); i++)
		m_RootObjects[i]._Get()->update();

}

std::weak_ptr<GameObject> SceneGraph::getRootObject(const std::string &aRootGameObjectName)
{
	for (int i = 0; i < m_RootObjects.size(); i++)
		if (m_RootObjects[i]._Get()->getName() == aRootGameObjectName)
			return std::weak_ptr<GameObject>(m_RootObjects[i]);

	return std::weak_ptr<GameObject>(m_RootObjects[0]);

}

//void SceneGraph::draw(void) //Think about draw path, this function's contents need refactoring
//{
	//for (int i = 0; i < m_Lights.size(); i++)
	//{
	//	m_Lights[i]._Get()->draw();
	//
	//	for (int j = 0; j < m_Renderers.size(); j++)
	//	{
	//		//	m_ForwardRenderers[j]._Get()->draw(m_Lights[i], m_Lights);
	//		m_Renderers[j]._Get()->draw(m_Lights[i], m_Lights);
	//
	//	}
	//	
	//
	//}
	//
	////glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//
	//for (int i = 0; i < m_Cameras.size(); i++)
	//{
	//	m_Cameras[i]._Get()->draw();
	//
	//	for (int j = 0; j < m_Renderers.size();)
	//		m_Renderers[j++]._Get()->draw(m_Cameras[i], m_Lights);
	//
	//}

//}

std::weak_ptr<GameObject> SceneGraph::createNewGameObject(const std::string &aName)
{
	std::shared_ptr<GameObject> gameObject(new GameObject(aName));

	gameObject._Get()->m_SceneGraph = this;

	//TODO: add mechanism for iterating the hierarchy

	m_RootObjects.push_back(gameObject);

	return std::weak_ptr<GameObject>(gameObject);

}