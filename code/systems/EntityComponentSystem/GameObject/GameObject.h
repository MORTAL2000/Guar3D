#ifndef GUAR_ECS_GAMEOBJECT_H
#define GUAR_ECS_GAMEOBJECT_H
/*
 * GameObject
 *
*/
//project includes
#include "../Component/Light/Light.h"
#include "../Component/Component.h"

//stdlib includes
#include <vector>
#include <type_traits>
#include <string>
#include <memory>

namespace guar
{
	namespace ECS
	{
		class Component;
		class SceneGraph;
		class GameObjectDeleter;
		class Light;
		class Renderer;
		class Camera;
		class Rigidbody;

		class GameObject final
		{
			friend SceneGraph;
			friend GameObject;

		private: //data members
			std::string                              m_Name;
			std::vector<std::shared_ptr<Component>>  m_Components; //ComponentCollection m_Components;
			std::vector<std::shared_ptr<GameObject>> m_Children;
			std::weak_ptr<SceneGraph>                m_SceneGraph;

			//void init(void);
			std::weak_ptr<Renderer> initARenderer(std::weak_ptr<Renderer>);
			std::weak_ptr<Light>    initALight   (std::weak_ptr<Light>);
			std::weak_ptr<Camera>   initACamera  (std::weak_ptr<Camera>);

		public: //Accessors
			std::string getName(void) {	return m_Name; }
			std::weak_ptr<SceneGraph> getSceneGraph(void) { return m_SceneGraph; }

			void setName(const std::string &aName) { m_Name = aName; }

			//ECS::Scenegraph interface
			void init(void);
			void update(void);

		public: //public interface
			void moveToScene(const std::string &aScene);
			void addToScene (const std::string &aScene);


			template<class T> std::weak_ptr<T> addComponent()
			{
				static_assert(std::is_base_of<Component, T>::value == true, "T is not derived from Component and therefore cannot be added to the Gameobject.");
				
				m_Components.push_back(std::make_shared<T>());
				m_Components.back()->m_GameObject = this;
				
				m_SceneGraph._Get()->m_ComponentInitCallbackList.push_back(std::tuple<Component*, std::function<void(void)>>(m_Components.back()._Get(), std::bind(&ECS::Component::init, m_Components.back()._Get())));

				if (std::is_same<T, Renderer>::value)
					m_SceneGraph._Get()->m_Renderers.push_back
					(
						initARenderer(std::dynamic_pointer_cast<Renderer>(m_Components.back()))

					);
				else if (std::is_same<T, Camera>::value)
					m_SceneGraph._Get()->m_Cameras.push_back
					(
						initACamera(std::dynamic_pointer_cast<Camera>(m_Components.back()))

					);
				else if (std::is_same<T, Light>::value)
					m_SceneGraph._Get()->m_Lights.push_back
					(
						initALight(std::dynamic_pointer_cast<Light>(m_Components.back()))
				
					);

				return std::weak_ptr<T>(std::dynamic_pointer_cast<T>(m_Components.back()));

			}

			template<class T> std::weak_ptr<T> findComponent()
			{
				static_assert(std::is_base_of<Component, T>::value == true, "T is not derived from Component and therefore will not be found in components.");

				for (int i = 0; i < m_Components.size(); i++)
					if (std::dynamic_pointer_cast<T>(m_Components[i]))
						return std::weak_ptr<T>(std::dynamic_pointer_cast<T>(m_Components[i]));

			}

			template<class T> std::vector<std::weak_ptr<T>> findComponents()
			{
				static_assert(std::is_base_of<Component, T>::value == true, "T is not derived from Component and therefore will not be found in components.");

				std::vector<std::weak_ptr<T>> componentVector;

				for (int i = 0; i < m_Components.size(); i++)
					if (std::dynamic_pointer_cast<T>(m_Components[i]))
						componentVector.push_back(std::weak_ptr<T>(std::dynamic_pointer_cast<T>(m_Components[i])));

				return componentVector;

			}

			

			void becomeChild(std::unique_ptr<GameObject> aGameObject);

		private: //ctors
			GameObject();
			GameObject(const std::string &aName);
			GameObject(const GameObject &aGameObject);
		public:
			~GameObject(); //this should be private i think

		};

	}

}

#endif