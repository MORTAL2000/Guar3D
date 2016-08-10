#ifndef GUAR_GRAPHICS_GRAPHICS_H
#define GUAR_GRAPHICS_GRAPHICS_H

/*
 *  Graphics.h
 *  
 *  Responsible for graphical effects
 *  
*/
//Math inc
#include <Math/Vector2/Vector2.h>
//std inc
#include <string>

struct GLFWwindow;

namespace guar
{    
	namespace GFX { class Model         ; }
	namespace GFX { class ShaderProgram ; }
	namespace GFX { class Texture       ; }
	namespace GFX { class RenderTexture ; }

	class Graphics final
	{
	    friend class Engine;
	    Graphics() = delete; Graphics(const Graphics&) = delete;
		
		//Engine interface
	    static void init(GLFWwindow* aWindowHandle);
		static void update(void);
	
	public: 
		//game programmer interface
	    static GFX::Model*         getModel         (const std::string &aModelName   = "");
	    static GFX::ShaderProgram* getShaderProgram (const std::string &aModelName   = "");
	    static GFX::Texture*       getTexture       (const std::string &aTextureName = "");
	    static GFX::RenderTexture* getRenderTexture (const std::string &aTextureName = "");
	    static Math::Vector2       getWindowSize	(void)                                ;
	
	};

}

#endif