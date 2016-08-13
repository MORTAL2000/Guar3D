#ifndef GUAR_DEVELOPMENT_SCENEGRAPH_H
#define GUAR_DEVELOPMENT_SCENEGRAPH_H

#include <string>

namespace guar
{
	namespace DEV
	{
		class SceneGraph
		{
			std::string m_Name;

		public:
			std::string getName(void) { return m_Name; }

			virtual void update() = 0;
			
			SceneGraph(const std::string &aName) : m_Name(aName) {}
			
		};

	}

}

#endif