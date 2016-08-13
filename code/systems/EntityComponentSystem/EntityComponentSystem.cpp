#include "EntityComponentSystem.h"

//ECS inc
#include "ComponentTypeRegistry\ComponentTypeRegistry.h"
#include "SceneGraphCollection\SceneGraphCollection.h"
#include "SceneGraph\SceneGraph.h"
//Debug inc
#include <Debug\Debug.h>


using namespace guar;

//Data members
static ECS::SceneGraphCollection m_SceneGraphs;

void EntityComponentSystem::init(void)
{
	Debug::announce("Engine init: ECS initializing...");
	ECS::ComponentTypeRegistry::init();

}

void EntityComponentSystem::update(void)
{
	m_SceneGraphs.update();

}

std::weak_ptr<ECS::SceneGraph> EntityComponentSystem::createScene(const std::string &aName)
{
	return m_SceneGraphs.createScene(aName);


}

std::weak_ptr<ECS::SceneGraph> EntityComponentSystem::findScene(const std::string &aName)
{
	return m_SceneGraphs.find(aName);

}