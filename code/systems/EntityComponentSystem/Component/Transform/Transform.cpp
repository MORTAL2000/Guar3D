#include "Transform.h"

using namespace guar;
using namespace ECS;

void Transform::translate(const Math::Vector3 &aTranslation) 
{ 
	m_Position += aTranslation; 

}

void Transform::rotate(const Math::Vector3 &aRotation)
{
	m_Rotation += aRotation;

}