#include "GameObject.h"

//ecs inc
#include "../SceneGraph/SceneGraph.h"
#include "../Component/Transform/Transform.h"
#include "../Component/Renderer/Renderer.h"
#include "../Component/Light/Light.h"
#include "../Component/Camera/Camera.h"

//engine inc
#include <Engine/Engine.h>

//debug inc
#include <debug\Debug.h>

//gfx inc
#include <Graphics\SceneGraph\SceneGraph.h>
#include <Graphics\RenderObject\RenderObject.h>
#include <Graphics\RenderLight\RenderLight.h>
#include <Graphics\RenderCamera\RenderCamera.h>



using namespace guar;
using namespace ECS;

GameObject::GameObject() : 
	GameObject("Unnamed GameObject")
{}

GameObject::GameObject(const std::string &aName) :
	m_Name(aName)
{}


GameObject::~GameObject()
{
	Debug::log("Gameobject ", getName(), " has been destroyed\n");

}

void GameObject::init(void)
{
	//Init components
	for (int i = 0; i < m_Components.size(); i++)
		m_Components[i]->init();

}

void GameObject::update(void)
{
	//Update components
	for (int i = 0; i < m_Components.size(); i++)
		if (m_Components[i]->isReady())
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



std::weak_ptr<Renderer> GameObject::initARenderer(std::weak_ptr<Renderer> aRenderer)
{
	aRenderer._Get()->m_RenderObject = m_SceneGraph._Get()->m_GraphicsScene._Get()->createRenderObject();
	return aRenderer;

}

std::weak_ptr<Light> GameObject::initALight(std::weak_ptr<Light> aLight)
{
	aLight._Get()->m_RenderLight = m_SceneGraph._Get()->m_GraphicsScene._Get()->createRenderLight();
	return aLight;

}

std::weak_ptr<Camera> GameObject::initACamera(std::weak_ptr<Camera> aCamera)
{
	aCamera._Get()->m_RenderCamera = m_SceneGraph._Get()->m_GraphicsScene._Get()->createRenderCamera();
	return aCamera;

}