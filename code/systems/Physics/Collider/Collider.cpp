#include "Collider.h"

using namespace guar;
using namespace PHY;

void Collider::setLocalPosition(const Math::Vector3 &aLocalPosition)   { m_LocalPosition = aLocalPosition; }
void Collider::setLocalRotation(const Math::Quaternion &aLocalRotation){ m_LocalRotation = aLocalRotation; }

Math::Vector3                   Collider::getLocalPosition (void) { return m_LocalPosition; }
Math::Quaternion                Collider::getLocalRotation (void) { return m_LocalRotation; }
std::weak_ptr<btCollisionShape> Collider::getCollisionShape(void) {	return m_CollisionShape; }

Collider::Collider(const Math::Vector3 &aLocalPosition, const Math::Quaternion &aLocalRotation) :
	m_LocalPosition(aLocalPosition),
	m_LocalRotation(aLocalRotation)
{}