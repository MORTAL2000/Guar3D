#ifndef GUAR_ECS_RENDERER_H
#define GUAR_ECS_RENDERER_H
/*
 * Renderer.h
 *
*/
//ecsinc
#include "../Component.h"
//gfxinc
#include "../../../Graphics/RenderObject/RenderObject.h"
//stdinc
#include <vector>
#include <memory.h>

namespace guar
{	
	class ShaderProgram;
	class RenderTexture;

	namespace ECS
	{
		class Transform;
		class Light;
		class SceneGraph;
		class Camera;
		class Observer;
		class GameObject;

		class Renderer final : public Component
		{
			friend guar::ECS::SceneGraph; //friend funcs may be more appropriate
			friend Camera;
			friend GameObject;
			
			//Data members
			std::weak_ptr<GFX::RenderObject> m_RenderObject;
			std::weak_ptr<Transform> m_Transform;
			
			//ECS interface
			virtual void init  (void) override;
			//virtual void start (void) override;
			virtual void update(void) override;
			
			//Scenegraph interface
			void draw(std::weak_ptr<Observer> aObserver, std::vector<std::weak_ptr<Light>> &aLights);

		public:
			//Model related
			void setModel        (const std::string &aModelName);
			
			//Shader related
			void setShaderProgram(const std::string &aModelName);
			
			void setTexture(const std::string &aUniformName, std::weak_ptr<GFX::Texture> aTexture);
			void setTexture(const std::string &aUniformName, const std::string &aTextureName);
			


		};

	}

}

#endif