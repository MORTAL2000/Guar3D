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

void SceneGraphCollection::push_back(const guar::ECS::SceneGraph &aScene)
{
	m_Vector.push_back(aScene);

}

int SceneGraphCollection::size(void) { return m_Vector.size(); }
SceneGraph* SceneGraphCollection::back(void) { return &m_Vector.back(); }
SceneGraph* SceneGraphCollection::operator[](const int &i) { return &m_Vector[i]; }