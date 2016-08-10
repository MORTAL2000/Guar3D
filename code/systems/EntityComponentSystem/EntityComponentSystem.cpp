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
	Debug::log("\n\n****\nEngine init: ECS initializing...\n****\n");
	ECS::ComponentTypeRegistry::init();

}

void EntityComponentSystem::update(void)
{
	for (int i = 0; i < m_SceneGraphs.size(); i++)
	{
		m_SceneGraphs[i]->update();
		m_SceneGraphs[i]->draw();

	}

}

ECS::SceneGraph* EntityComponentSystem::createScene(const std::string &aName)
{
	m_SceneGraphs.push_back(ECS::SceneGraph(aName));
	return m_SceneGraphs.back();


}