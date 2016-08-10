#include "GameObject.h"

//projinc
#include "../Component/Renderer/Renderer.h"
#include "../Component/Transform/Transform.h"

#include "../../Engine/Engine.h"

#include <debug\Debug.h>

using namespace guar;
using namespace ECS;

GameObject::GameObject() : 
	GameObject
	(
		"Unnamed GameObject"
	
	)

{}

GameObject::GameObject(const std::string &aName) :
	m_Name(aName)

{
	//m_SceneGraph = &Engine::m_SceneGraph; //absurd hack TODO: COMPLETELY FIX GAMEOBJECT INSTANTIATION

}


GameObject::~GameObject()
{
	Debug::log("Gameobject ", getName(), " has been destroyed\n");

}

void GameObject::update(void)
{
	//Update components
	for (int i = 0; i < m_Components.size(); i++)
		m_Components[i]->update();

	//Update children
	for (int i = 0; i < m_Children.size(); i++)
		m_Children[i]->update();

}

GameObject::GameObject(const GameObject &aGameObject)
{
	m_Name = aGameObject.m_Name;
	
	for (int i = 0; i < aGameObject.m_Components.size(); i++)
	{
		m_Components.push_back(aGameObject.m_Components[i]);
		m_Components[i]->m_GameObject = this;//Engine::m_SceneGraph.getRootObject("The Player");

	}

}

//GameObject* GameObject::newChild(void)
//{
//	//GameObject* newChild;// = new GameObject();
//	//m_Children.push_back(std::make_unique<GameObject>(newChild));
//	//return newChild;
//
//}

void GameObject::becomeChild(std::unique_ptr<GameObject> aGameObject)
{
	m_Children.push_back(std::move(aGameObject));

}

//void GameObject::init(void)
//{
//	for(int i = 0; i < m_C)
//
//}