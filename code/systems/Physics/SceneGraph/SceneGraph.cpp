#include "SceneGraph.h"
//ecs inc
#include <EntityComponentSystem\GameObject\GameObject.h>
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

#include<Debug\Debug.h>
bool SceneGraph::rayCast(const Math::Vector3 &aOrigin, const Math::Vector3 &aDirection, const float &aDistance, PHY::Collision &ioRaycastInfo)
{
	Math::Vector3 toVec = aOrigin;
	toVec += (aDirection * aDistance);

	return rayCast(aOrigin, toVec, ioRaycastInfo);

}

bool SceneGraph::rayCast(const Math::Vector3 &aFromVector, const Math::Vector3 &aToVector, PHY::Collision &ioRaycastInfo)
{
	//calculate from and to vectors
	btVector3 fromVector(aFromVector.x, aFromVector.y, aFromVector.z); //(aOrigin.x, aOrigin.y, aOrigin.z);
	btVector3 toVector(aToVector.x, aToVector.y, aToVector.z);

	//create the callback structure
	btCollisionWorld::ClosestRayResultCallback rayCallback(fromVector, toVector);

	m_World._Get()->getDynamicsWorld()._Get()->rayTest(fromVector, toVector, rayCallback); //World->rayTest(Start, End, RayCallback);

	//write info to the io arg if there was a hit
	if (rayCallback.hasHit())
	{
		ioRaycastInfo.physicsbody = ((PHY::PhysicsObject*)rayCallback.m_collisionObject->getUserPointer())->getECSPhysicsBody();
		return true;

	}

	return false;

}