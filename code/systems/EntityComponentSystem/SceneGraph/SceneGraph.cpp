#include "SceneGraph.h"

#include "../Component/Renderer/Renderer.h"
#include "../Component/Camera/Camera.h"
#include "../Component/Transform/Transform.h"
#include "../GameObject/GameObject.h"
#include <Graphics\Graphics.h>
#include <Physics\Physics.h>
#include <Engine\Engine.h>


//#include "../../Graphics/OpenGL/OpenGL.h"

using namespace guar;
using namespace ECS;

SceneGraph::SceneGraph() :
	SceneGraph("Unnamed Scene")

{}

SceneGraph::SceneGraph(const std::string &aSceneName) :
	//m_DidInit(false),
	DEV::SceneGraph(aSceneName),
	m_GraphicsScene(Graphics::createScene(aSceneName)),
	m_PhysicsScene (Physics::createScene (aSceneName))

{}

void SceneGraph::addRootObject(std::shared_ptr<GameObject> aGameObject)
{ 
	m_RootObjects.push_back(aGameObject); 
	m_RootObjects.back()._Get()->m_SceneGraph = Engine::findScene(getName());

}

void SceneGraph::update(void)
{
	m_ComponentInitCallbackList.update();

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

std::weak_ptr<GameObject> SceneGraph::createNewGameObject(const std::string &aName)
{
	std::shared_ptr<GameObject> gameObject(new GameObject(aName));

	gameObject._Get()->m_SceneGraph = Engine::findScene(getName());

	//TODO: add mechanism for iterating the hierarchy

	m_RootObjects.push_back(gameObject);

	return std::weak_ptr<GameObject>(gameObject);

}

std::weak_ptr<GameObject> SceneGraph::findGameObject(std::string aGameObjectName)
{
	for (int i = 0; i < m_RootObjects.size(); i++)
	{
		if (m_RootObjects[i]._Get()->getName() == aGameObjectName)
		{
			return m_RootObjects[i];

		}

	}

	return std::weak_ptr<GameObject>();

}