#include "BoxCollider.h"

//implementation inc
#include <Bullet\btBulletCollisionCommon.h>

using namespace guar;
using namespace PHY;

BoxCollider::BoxCollider(Math::Vector3 aSize, Math::Vector3 aLocalPosition, Math::Quaternion aLocalRotation) :
	Collider(aLocalPosition,aLocalRotation),
	m_Size(aSize)
{
	m_CollisionShape = std::shared_ptr<btCollisionShape>(new btBoxShape(btVector3(aSize.x*0.5f, aSize.y*0.5f, aSize.z*0.5f)));

}