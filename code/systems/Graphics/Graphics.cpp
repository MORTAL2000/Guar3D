#include "Graphics.h"

//project includes
#include "ShaderProgram/ShaderProgram.h"
#include "Model/Model.h"
//Debug inc
#include <Debug\Debug.h>
//GFX inc
#include "OpenGL/OpenGL.h"
#include "OpenGL/OpenGLHelper.h"
#include "GraphicsObjectCollection/ModelCollection/ModelCollection.h"
#include "GraphicsObjectCollection/ShaderProgramCollection/ShaderProgramCollection.h"
#include "GraphicsObjectCollection/TextureCollection/TextureCollection.h"
#include "GraphicsObjectCollection/RenderTextureCollection/RenderTextureCollection.h"
//stdlib includes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

using namespace guar;
using namespace GFX;

//Data members
static GFX::ShaderProgramCollection m_ShaderPrograms;
static GFX::TextureCollection       m_Textures;
static GFX::ModelCollection         m_Models;
static GFX::RenderTextureCollection m_RenderTextures;
static Math::Vector2                m_WindowSize(800,800);
static GLFWwindow*					m_Window;

//forward decs
void windowSizeCallback(GLFWwindow* aWindowHandle, int aX, int aY);

void Graphics::init(GLFWwindow* aWindowHandle)
{
	m_Window = aWindowHandle;

	Debug::log("\n\n****\nEngine init: Graphics initializing...\n****\n");
    printf("Graphics::Graphics()\n");
	GLHelp::Diagnostics::clearGLErrors();
    
    //Load static defaults
	m_ShaderPrograms.init();
	m_Textures.init();	    
	m_RenderTextures.init();
	m_Models.init();        
    
    //Load dynamic autos
	m_ShaderPrograms.loadDirectory("../Shaders");
	m_Textures.loadDirectory("../Textures");
	m_Models.loadDirectory("../Models");

	
	glfwSetWindowSizeCallback(aWindowHandle, windowSizeCallback);
	glfwSetWindowSize(aWindowHandle, m_WindowSize.x, m_WindowSize.y);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

}

void windowSizeCallback(GLFWwindow* aWindowHandle, int aX, int aY)
{
	m_WindowSize.x = aX;
	m_WindowSize.y = aY;

}

void Graphics::update(void)
{
	glfwSwapBuffers(m_Window);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

GFX::Model*         Graphics::getModel         (const std::string &aModelName)   { return m_Models.find(aModelName);           }
GFX::ShaderProgram* Graphics::getShaderProgram (const std::string &aModelName)   { return m_ShaderPrograms.find(aModelName);   }
GFX::Texture*       Graphics::getTexture       (const std::string &aTextureName) { return m_Textures.find(aTextureName);       }
GFX::RenderTexture* Graphics::getRenderTexture (const std::string &aTextureName) { return m_RenderTextures.find(aTextureName); }
Math::Vector2       Graphics::getWindowSize    (void)                            { return m_WindowSize;                        }