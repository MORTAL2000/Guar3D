#include "SceneGraph.h"
//phy inc
#include "../PhysicsWorld/PhysicsWorld.h"
#include "../PhysicsObject/PhysicsObject.h"
#include "../PhysicsObject/RigidBody/RigidBody.h"
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>
//implementation inc
#include <Bullet\btBulletDynamicsCommon.h>

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

//btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3 Start, btVector3 End)
//{
//	//return btCollisionWorld()
//
//}

btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3 Start, btVector3 End);

PHY::Collision SceneGraph::rayCast(const Math::Vector3 &aOrigin, const Math::Vector3 &aDirection, const float &aDistance)
{
	PHY::Collision collision;

	//do stuff
	btVector3 fromVector(aOrigin.x, aOrigin.y, aOrigin.z);
	btVector3 toVector(aDirection.x, aDirection.y, aDirection.z);
	
	m_World._Get()->getDynamicsWorld()._Get()->rayTest(fromVector, toVector, RayCallback); //World->rayTest(Start, End, RayCallback);


	return collision;

}