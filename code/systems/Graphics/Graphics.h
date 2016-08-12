#ifndef GUAR_GRAPHICS_GRAPHICS_H
#define GUAR_GRAPHICS_GRAPHICS_H

/*
 *  Graphics.h
 *  
 *  Responsible for graphical effects
 *  
*/
//Dev
//#include <Abstract\Interface.h>
//Math inc
#include <Math/Vector2/Vector2.h>
//std inc
#include <string>
#include <memory>

struct GLFWwindow;

namespace guar
{    
	namespace GFX { class Model         ; }
	namespace GFX { class ShaderProgram ; }
	namespace GFX { class Texture       ; }
	namespace GFX { class RenderTexture ; }
	namespace GFX { class SceneGraph    ; }
	namespace ECS { class SceneGraph    ; }

	class Graphics final //: public Dev::InternalInterface::Graphics
	{
	    friend class Engine;
		friend ECS::SceneGraph;

	    Graphics() = delete; Graphics(const Graphics&) = delete;

		static void renderThreadDrawLoop(void);

		//Engine interface
	    static void init(GLFWwindow* aWindowHandle);
		static void update(void);
		static void terminate(void);
		
		//Graphics scenegraph
		static std::weak_ptr<GFX::SceneGraph> getScene   (const std::string &aName);
		static std::weak_ptr<GFX::SceneGraph> createScene(const std::string &aName);

	public: 
		//game programmer interface
	    static std::weak_ptr<GFX::Model        >getModel         (const std::string &aModelName   = "");
	    static std::weak_ptr<GFX::ShaderProgram>getShaderProgram (const std::string &aModelName   = "");
	    static std::weak_ptr<GFX::Texture      >getTexture       (const std::string &aTextureName = "");
	    static std::weak_ptr<GFX::RenderTexture>getRenderTexture (const std::string &aTextureName = "");
	    static Math::Vector2        getWindowSize	 (void)                                ;



	};

}

#endif