#ifndef GUAR_ECS_TRANSFORM_H
#define GUAR_ECS_TRANSFORM_H
/*
 * Transform.h
 *
*/

//projinc
#include "../Component.h"

//mathinc
#include <Math/Vector3/Vector3.h>
#include <Math/Quaternion/Quaternion.h>

namespace guar
{
	namespace ECS
	{
		class Transform : public Component
		{
			Math::Vector3    m_Position, m_Scale;
			Math::Quaternion m_Rotation;

		public:
			Math::Vector3    getPosition(void) { return m_Position; }
			Math::Quaternion getRotation(void) { return m_Rotation; }
			Math::Vector3    getScale   (void) { return m_Scale;    }
			Math::Vector3    getEulerAngles(void);

			void setPosition(const Math::Vector3    &aPosition) { m_Position = aPosition; }
			void setRotation(const Math::Quaternion &aRotation) { m_Rotation = aRotation; }
			void setRotation(const Math::Vector3    &aEulerAngles);
			void setScale   (const Math::Vector3    &aScale   ) { m_Scale    = aScale;    }

			void translate(const Math::Vector3 &aTranslation);
			void rotate   (const Math::Vector3 &aRotation   );
			//void translate(const float &aX = 0, const float &aY =0, const float &aZ =0);

			Math::Vector3 getForwardVector(void);

		};	

	}

}

#endif