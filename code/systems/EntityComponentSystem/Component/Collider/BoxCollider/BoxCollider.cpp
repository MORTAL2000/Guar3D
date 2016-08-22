#include "BoxCollider.h"
//implementation inc
#include <Bullet\btBulletCollisionCommon.h>
//phy inc
#include <Physics\Collider\BoxCollider\BoxCollider.h>

using namespace guar;
using namespace ECS;

void BoxCollider::init(void)
{
	m_Collider = std::shared_ptr<PHY::Collider>(new PHY::BoxCollider
	(
		m_Size
	
	));

}

void BoxCollider::setSize(const Math::Vector3 &aSize)
{
	m_Size = aSize;

}