#ifndef GUAR_PHY_BOXCOLLIDER_H
#define GUAR_PHY_BOXCOLLIDER_H

//phy inc
#include "../Collider.h"
//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Quaternion\Quaternion.h>

namespace guar
{
	namespace PHY
	{
		class BoxCollider : public PHY::Collider
		{
			Math::Vector3 m_Size;

		public:
			//Math::Vector3 getSize(void) { return m_Size; }

			BoxCollider(Math::Vector3 aSize, Math::Vector3 aLocalPosition = Math::Vector3::Zero, Math::Quaternion aLocalRotation = Math::Quaternion::Identity);

		};

	}

}

#endif