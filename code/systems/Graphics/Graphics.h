#ifndef GUAR_GRAPHICS_GRAPHICS_H
#define GUAR_GRAPHICS_GRAPHICS_H

/*
 *  Graphics.h
 *  
 *  Responsible for graphical effects
 *  
*/
//Dev inc
#include <Development\System.h>
//Math inc
#include <Math/Vector2/Vector2.h>
//std inc
#include <string>
#include <memory>

struct GLFWwindow;
namespace guar { namespace GFX { class Model;         } }
namespace guar { namespace GFX { class ShaderProgram; } }
namespace guar { namespace GFX { class Texture;       } }
namespace guar { namespace GFX { class RenderTexture; } }
namespace guar { namespace GFX { class SceneGraph;    } }
namespace guar { namespace ECS { class SceneGraph;    } }

namespace guar
{   
	class Graphics final
	{
	    friend class Engine;
		friend ECS::SceneGraph;
	    Graphics() = delete; Graphics(const Graphics&) = delete;

		//Engine interface
	    static void init(GLFWwindow* aWindowHandle);
		static void update(void);
		static void terminate(void);

		//Scenegraph interface
		static std::weak_ptr<GFX::SceneGraph> getScene    (const std::string &aName);
		static std::weak_ptr<GFX::SceneGraph> createScene (const std::string &aName);

		//Graphics specific
		static void renderThreadDrawLoop(void);

	public: 
		//game programmer interface
	    static std::weak_ptr<GFX::Model        > getModel         (const std::string &aModelName   = "");
	    static std::weak_ptr<GFX::ShaderProgram> getShaderProgram (const std::string &aModelName   = "");
	    static std::weak_ptr<GFX::Texture      > getTexture       (const std::string &aTextureName = "");
	    static std::weak_ptr<GFX::RenderTexture> getRenderTexture (const std::string &aTextureName = "");
	    static Math::Vector2                     getWindowSize	  (void)                                ;
		
		static std::weak_ptr<GFX::ShaderProgram> loadShaderFromFile  (const std::string &aFileName     );
		static std::weak_ptr<GFX::ShaderProgram> loadShaderFromSource(const std::string &aFileName     );
		static void                              loadShaderDirectory (const std::string &aDirectoryName);

	};

}

#endif