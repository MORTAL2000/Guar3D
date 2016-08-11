#ifndef GUAR_DEVELOPMENT_INTERFACE_H
#define GUAR_DEVELOPMENT_INTERFACE_H
/* 
 * Interface.h
 * a set of interfaces that allow engine systems to communicate to one another
 * without affecting the game programmer's interface to these systems.
 * 
*/
#include <string>
#include <memory>

namespace guar
{
	class Graphics;

	namespace Dev
	{
		class InternalInterface
		{
			friend Graphics;

			class Graphics
			{
			public:
				//static std::weak_ptr<GFX::SceneGraph> getScene(const std::string &aName);
				//static std::weak_ptr<GFX::SceneGraph> createScene(const std::string &aName);

			};

		};

	}

}

#endif