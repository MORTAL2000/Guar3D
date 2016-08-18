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
	for (int i = 0; i < m_Objects.size(); i++)
		m_Objects[i]._Get()->prePhysicsStepSync();

	m_World._Get()->update();

	for (int i = 0; i < m_Objects.size(); i++)
		m_Objects[i]._Get()->postPhysicsStepSync();
	
}

std::weak_ptr<PhysicsObject> SceneGraph::createRigidBody(std::weak_ptr<ECS::Rigidbody> aECSRigidbody)
{
	m_Objects.push_back(std::shared_ptr<PhysicsObject>(new PhysicsObject(*m_World._Get(), aECSRigidbody)));
	return std::weak_ptr<PhysicsObject>(m_Objects.back());

}