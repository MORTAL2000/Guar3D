#include "Rigidbody.h"
//ecs inc
#include "../../../GameObject/GameObject.h"
#include "../../../SceneGraph/SceneGraph.h"
#include "../../Transform/Transform.h"
#include "../../Collider/Collider.h"
//phy inc
#include <Physics\SceneGraph\SceneGraph.h>
#include <Physics\PhysicsObject\RigidBody\RigidBody.h>
#include <Physics\PhysicsWorld\PhysicsWorld.h>

using namespace guar;
using namespace ECS;

void Rigidbody::init(void)
{
	//get all colliders
	std::vector<std::weak_ptr<ECS::Collider>> ecscolliders = getGameObject()->findComponents<ECS::Collider>();
	std::vector<std::weak_ptr<PHY::Collider>> phycolliders;

	for (int i = 0; i < ecscolliders.size(); i++)
		phycolliders.push_back(ecscolliders[i]._Get()->getCollider());

	PhysicsBody::init(getGameObject()->getSceneGraph()._Get()->getPhysicsScene()._Get()->createRigidBody(getGameObject()->findComponent<Rigidbody>(), phycolliders,m_Mass));

}

