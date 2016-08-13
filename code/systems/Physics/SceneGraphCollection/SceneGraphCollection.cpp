#include "SceneGraphCollection.h"

//gfx inc
#include "../SceneGraph/SceneGraph.h"

using namespace guar;
using namespace PHY;

//void SceneGraphCollection::update(void)
//{
//	for (int i = 0; i < m_Scenes.size(); i++)
//		m_Scenes[i]._Get()->update();
//
//}
//
//std::weak_ptr<SceneGraph> SceneGraphCollection::createScene(const std::string &aName)
//{
//	m_Scenes.push_back(std::shared_ptr<SceneGraph>(new SceneGraph(aName)));
//	
//	return std::weak_ptr<SceneGraph>(m_Scenes.back());
//
//}
//
//std::weak_ptr<SceneGraph> SceneGraphCollection::findScene(const std::string &aName)
//{
//	for (int i = 0; i < m_Scenes.size(); i++)
//	{
//		if (m_Scenes[i]._Get()->getName() == aName)
//			return std::weak_ptr<SceneGraph>(m_Scenes[i]);
//
//		return std::weak_ptr<SceneGraph>();
//
//	}
//
//}