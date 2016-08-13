#ifndef GUAR_DEVELOPMENT_SCENEGRAPHCOLLECTION_H
#define GUAR_DEVELOPMENT_SCENEGRAPHCOLLECTION_H

//dev inc
#include "SceneGraph.h"
//std inc
#include <type_traits>
#include <memory>
#include <vector>

namespace guar
{
	namespace DEV
	{
		template<class SceneGraphType>
		class SceneGraphCollection
		{
			static_assert(std::is_base_of<SceneGraph, SceneGraphType>::value == true, "SceneType must derive from DEV::SceneGraph");

			std::vector<std::shared_ptr<SceneGraphType>> m_Vector;

		public:
			std::weak_ptr<SceneGraphType> find(const std::string &aSceneGraphName)
			{
				for (int i = 0; i < m_Vector.size(); i++)
					if (m_Vector[i]._Get()->getName() == aSceneGraphName)
						return std::weak_ptr<SceneGraphType>(m_Vector[i]);

			}

			std::weak_ptr<SceneGraphType> createScene(const std::string &aName)
			{
				m_Vector.push_back(std::shared_ptr<SceneGraphType>(new SceneGraphType(aName)));
				return std::weak_ptr<SceneGraphType>(m_Vector.back());

			}
						
			void update(void)
			{
				for (int i = 0; i < m_Vector.size(); i++)
					m_Vector[i]._Get()->update();

			}


		};

	}

}

#endif