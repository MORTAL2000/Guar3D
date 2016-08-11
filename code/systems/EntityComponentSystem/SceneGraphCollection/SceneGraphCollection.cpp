#include "SceneGraphCollection.h"

#include "../SceneGraph/SceneGraph.h"

using namespace guar;
using namespace ECS;

SceneGraph* SceneGraphCollection::find(const std::string &aSceneGraphName)
{
	for (int i = 0; i < m_Vector.size(); i++)
		if (m_Vector[i].getName() == aSceneGraphName)
			return &m_Vector[i];

}

void SceneGraphCollection::update(void)
{
	for (int i = 0; i < m_Vector.size(); i++)
		m_Vector[i].update();

}

SceneGraph* SceneGraphCollection::createScene(const std::string &aName)
{
	m_Vector.push_back(ECS::SceneGraph(aName));
	return &m_Vector.back();

}