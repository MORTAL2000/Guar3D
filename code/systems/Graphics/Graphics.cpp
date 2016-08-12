#include "Graphics.h"
//GFX inc
#include "ShaderProgram/ShaderProgram.h"
#include "Model/Model.h"
#include "OpenGL/OpenGL.h"
#include "OpenGL/OpenGLHelper.h"
#include "GraphicsObjectCollection/ModelCollection/ModelCollection.h"
#include "GraphicsObjectCollection/ShaderProgramCollection/ShaderProgramCollection.h"
#include "GraphicsObjectCollection/TextureCollection/TextureCollection.h"
#include "GraphicsObjectCollection/RenderTextureCollection/RenderTextureCollection.h"
#include "SceneGraphCollection\SceneGraphCollection.h"
#include "SceneGraph\SceneGraph.h"
//Debug inc
#include <Debug\Debug.h>
//stdlib includes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <thread>
#include <memory>

using namespace guar;
using namespace GFX;

//Data members
static GFX::SceneGraphCollection    s_SceneGraphCollection;
static GFX::ShaderProgramCollection s_ShaderPrograms;
static GFX::TextureCollection       s_Textures;
static GFX::ModelCollection         s_Models;
static GFX::RenderTextureCollection s_RenderTextures;
static Math::Vector2                s_WindowSize(800,800);
static GLFWwindow*					s_Window;
static std::thread                  s_RenderThread;
static bool                         s_RenderThreadIsAlive = true;

//forward decs
void windowSizeCallback(GLFWwindow* aWindowHandle, int aX, int aY);
void frameBufferResizeCallBack(GLFWwindow* aWindow, int aWidth, int aHeight);


void Graphics::renderThreadDrawLoop(void)
{
	glfwMakeContextCurrent(s_Window);

	while (s_RenderThreadIsAlive)
		Graphics::update(); 

}

void Graphics::init(GLFWwindow* aWindowHandle)
{
	s_Window = aWindowHandle;

	Debug::announce("Engine init: Graphics initializing...");
    printf("Graphics::Graphics()\n");
	GLHelp::Diagnostics::clearGLErrors();
    
    ////Load static defaults
	s_ShaderPrograms.init();
	s_Textures.init();
	s_RenderTextures.init();
	s_Models.init();

    //Load dynamic autos
	s_ShaderPrograms.loadDirectory ("../Shaders" );
	s_Textures.loadDirectory       ("../Textures");
	s_Models.loadDirectory         ("../Models"  );

	glfwSetWindowSizeCallback(aWindowHandle, windowSizeCallback);
	glfwSetWindowSize(aWindowHandle, s_WindowSize.x, s_WindowSize.y);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glfwSetFramebufferSizeCallback(s_Window, frameBufferResizeCallBack);

	//init thread
	glfwMakeContextCurrent(0); //relinquish control of context, graphics will pick this up
	s_RenderThread = std::thread(renderThreadDrawLoop);
	s_RenderThread.detach();

}

void windowSizeCallback(GLFWwindow* aWindowHandle, int aX, int aY)
{
	s_WindowSize.x = aX;
	s_WindowSize.y = aY;

}

void Graphics::update(void)
{
	s_SceneGraphCollection.update(); //draw scenes to backbuffer
	glfwSwapBuffers(s_Window); //swap buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear back buffer

}

std::weak_ptr<Model        > Graphics::getModel         (const std::string &aModelName)   { return s_Models.find(aModelName);           }
std::weak_ptr<ShaderProgram> Graphics::getShaderProgram (const std::string &aModelName)   { return s_ShaderPrograms.find(aModelName);   }
std::weak_ptr<Texture      > Graphics::getTexture       (const std::string &aTextureName) { return s_Textures.find(aTextureName);       }
std::weak_ptr<RenderTexture> Graphics::getRenderTexture (const std::string &aTextureName) { return s_RenderTextures.find(aTextureName); }
Math::Vector2                Graphics::getWindowSize    (void)                            { return s_WindowSize;                        }


std::weak_ptr<GFX::SceneGraph>  Graphics::getScene(const std::string &aName)
{
	return s_SceneGraphCollection.findScene(aName);

}

std::weak_ptr<GFX::SceneGraph> Graphics::createScene(const std::string &aName)
{
	return s_SceneGraphCollection.createScene(aName);

}


void frameBufferResizeCallBack(GLFWwindow* aWindow, int aWidth, int aHeight)
{
	s_WindowSize.x = aWidth;
	s_WindowSize.y = aHeight;

	//glViewport(0, 0, aWidth, aHeight);

}

void Graphics::terminate(void)
{
	s_RenderThreadIsAlive = false;

}