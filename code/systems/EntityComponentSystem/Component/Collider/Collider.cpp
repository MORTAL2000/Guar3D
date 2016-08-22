#include "Collider.h"

using namespace guar;
using namespace ECS;

std::weak_ptr<PHY::Collider> Collider::getCollider(void)
{
	return std::weak_ptr<PHY::Collider>(m_Collider);

}