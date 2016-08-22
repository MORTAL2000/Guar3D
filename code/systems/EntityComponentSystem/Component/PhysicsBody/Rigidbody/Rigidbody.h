#ifndef GUAR_ECS_RIGIDBODY_H
#define GUAR_ECS_RIGIDBODY_H
/*
*
*
*/
#include "../PhysicsBody.h"

namespace guar
{
	namespace PHY { class RigidBody; }

	namespace ECS
	{
		class Transform;

		class Rigidbody : public PhysicsBody
		{
			float m_Mass;

			void init(void) override;

		public:
			void setMass(const float &aMass) { m_Mass = aMass; };
			
		};

	}

}


#endif