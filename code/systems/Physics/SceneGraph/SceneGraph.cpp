#include "SceneGraph.h"
//phy inc
#include "../PhysicsWorld/PhysicsWorld.h"
#include "../PhysicsObject/PhysicsObject.h"

using namespace guar;
using namespace PHY;

SceneGraph::SceneGraph(const std::string &aName) : DEV::SceneGraph(aName),
	m_World(new PhysicsWorld),
	m_Objects()
{
	
}

void SceneGraph::update(void)
{
	m_World._Get()->update();

	//for (int i = 0; i < m_Objects.size(); i++)
	//	m_Objects[i]._Get()->update();

}

std::weak_ptr<PhysicsObject> SceneGraph::createRigidBody(void)
{
	m_Objects.push_back(std::shared_ptr<PhysicsObject>(new PhysicsObject(*m_World._Get())));
	return std::weak_ptr<PhysicsObject>(m_Objects.back());

}