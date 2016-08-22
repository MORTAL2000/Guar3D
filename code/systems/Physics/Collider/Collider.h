#ifndef GUAR_PHY_COLLIDER_H
#define GUAR_PHY_COLLIDER_H

//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Quaternion\Quaternion.h>
//std inc
#include <memory>

class btCollisionShape;

namespace guar
{
	namespace PHY
	{
		class Collider
		{
		protected:
			Math::Vector3                     m_LocalPosition  ;
			Math::Quaternion                  m_LocalRotation  ;
			std::shared_ptr<btCollisionShape> m_CollisionShape ;

		public:
			void setLocalPosition   (const Math::Vector3    &aLocalPosition);
			void setLocalRotation   (const Math::Quaternion &aLocalRotation);

			Math::Vector3                   getLocalPosition (void);
			Math::Quaternion                getLocalRotation (void);
			std::weak_ptr<btCollisionShape> getCollisionShape(void);
			
			Collider(const Math::Vector3 &aLocalPosition, const Math::Quaternion &aLocalRotation);

		};

	}

}

#endif