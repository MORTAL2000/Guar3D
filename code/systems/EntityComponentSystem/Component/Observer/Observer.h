#ifndef GUAR_ENTITYCOMPONENTSYSTEM_OBSERVER_H
#define GUAR_ENTITYCOMPONENTSYSTEM_OBSERVER_H

#include "../Component.h"

namespace guar
{
	namespace GFX { class RenderObserver; }

	namespace ECS
	{
		class Observer : public Component //try privatizing
		{
		protected:
			virtual void draw(void) = 0;

		public:
			virtual GFX::RenderObserver* getRenderObserver(void) = 0;

		};

	}

}

#endif