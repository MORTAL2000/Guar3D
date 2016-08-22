#include "SceneGraph.h"
//phy inc
#include "../PhysicsWorld/PhysicsWorld.h"
#include "../PhysicsObject/PhysicsObject.h"
#include "../PhysicsObject/RigidBody/RigidBody.h"
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>

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

std::weak_ptr<PHY::RigidBody> SceneGraph::createRigidBody(std::weak_ptr<ECS::Rigidbody> aECSRigidbody,std::vector<std::weak_ptr<PHY::Collider>> &aColliders, const float &aMass)
{
	m_Objects.push_back(std::shared_ptr<PHY::PhysicsObject>(new PHY::RigidBody(*m_World._Get(), aColliders, aECSRigidbody, aMass)));
	return std::weak_ptr<RigidBody>(std::dynamic_pointer_cast<RigidBody>(m_Objects.back()));


}