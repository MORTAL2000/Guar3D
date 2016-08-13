#ifndef GUAR_ECS_SCENEGRAPH_H
#define GUAR_ECS_SCENEGRAPH_H
/*
 * SceneGraph.h
 * 
*/
//dev inc
#include <Development\SceneGraph.h>

//stdinc
#include <vector>
#include <string>
#include <iostream>
#include <memory>

namespace guar
{
	namespace GFX { class SceneGraph; }

	namespace ECS
	{
		class GameObject;
		class Renderer;
		class Camera;
		class Light;

		class SceneGraph : public DEV::SceneGraph
		{
			friend GameObject;

			std::string m_Name;

			std::weak_ptr<GFX::SceneGraph> m_GraphicsScene;

			std::vector<std::shared_ptr<GameObject>> m_RootObjects;
			std::vector<std::weak_ptr<Renderer>>     m_Renderers;
			std::vector<std::weak_ptr<Camera>>       m_Cameras;
			std::vector<std::weak_ptr<Light>>        m_Lights;
			
		public:
			std::string getName(void) { return m_Name; }
			std::weak_ptr<GFX::SceneGraph> getGraphicsScene() { return m_GraphicsScene; }

			std::weak_ptr<GameObject> getRootObject(const std::string &aRootGameObjectName);
			GameObject findGameObject(std::string aGameObjectName);

			void addRootObject(std::shared_ptr<GameObject> aGameObject);

			std::weak_ptr<GameObject> createNewGameObject(const std::string &aName ="Unnamed");
			

			void update();
			//void draw();

			SceneGraph();
			SceneGraph(const std::string &aSceneName);

		};

	}

}

#endif