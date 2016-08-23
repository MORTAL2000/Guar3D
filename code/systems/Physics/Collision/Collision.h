#ifndef GUAR_PHY_COLLISION_H
#define GUAR_PHY_COLLISION_H

//std inc
#include<memory>

namespace guar
{
	namespace ECS { class PhysicsBody; }

	namespace PHY
	{
		struct Collision
		{
			std::weak_ptr<ECS::PhysicsBody> physicsbody;

		};


	}

}

#endif