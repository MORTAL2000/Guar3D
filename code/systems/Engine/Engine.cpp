#include "Engine.h"
//gfx inc
#include <Graphics/OpenGL/OpenGL.h>
#include <Graphics/Graphics.h>
#include <Graphics/ShaderProgram/ShaderProgram.h>
//input inc
#include <Input/Input.h>
//ECS inc
#include <EntityComponentSystem/ComponentTypeRegistry/ComponentTypeRegistry.h>
#include <EntityComponentSystem\EntityComponentSystem.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
//Debug inc
#include <debug/Debug.h>
//Time inc
#include <Time/Time.h>
//Development inc
#include <Development\Guar3DASCII.h>
//stdlib
#include <stdio.h>
#include <iostream>

using namespace guar;

//static forward decs
static void keyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void initContext(void);
static void initGLFW(void);
static void initGLEW(void);

//static data
static GLFWwindow* m_Window = 0;

/*  
 * mainLoop
 *  void
 *  void
 *  application loop
 * 
 */


void Engine::mainLoop()
{
	try
	{
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(m_Window))
		{
			EntityComponentSystem::update();
			//Graphics::update();
			Time::update();
			glfwPollEvents();

		}

	}

	catch (std::runtime_error& e)
	{
		Debug::error(e.what());

	}

	Engine::terminate();

    
}

void Engine::terminate(void)
{
	Graphics::terminate();

	glfwTerminate();

	std::terminate; //Kills all threads

}

void Engine::mainInit(void)
{
	Engine::init();
    Graphics::init(m_Window);
	EntityComponentSystem::init();
	Input::init(m_Window);
	Time::init();
	Debug::init();

	Debug::announce("Engine init: Sound initializing...");
	Debug::announce("Engine init: Network initializing...");
	Debug::success("\n\n\nEngine init complete, passing control to the game!\n\n\n\n");

}

void Engine::init(void)
{
	Debug::log(Dev::c_EngineAsciiName, "a 3D game engine.\n", "Build date: ", __DATE__);
	Debug::announce("Engine init: Libraries are initializing...");

	m_Window = 0;

	initGLFW();
	initContext();
	initGLEW();

	glfwSetKeyCallback(m_Window, keyEventCallback);
	

}

// =========================== //
// Static function definitions //
// =========================== //
/*  
 * Init GLEW extension loader library
 * 
 */
static void initGLEW(void)
{
    Debug::log("initializing extension loader \"GLEW\"\n");
    
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        Debug::error("Error: ", glewGetErrorString(err),"\n");
        
    }
    
    Debug::success("Glew init complete: Using GLEW ", glewGetString(GLEW_VERSION), "\n");
    
}

/*
 * initGLFW
 * void
 * void
 * Initializes the GLFW Window, time & input library
 */
static void initGLFW(void)
{
    Debug::log("GLFW initalization: ");
    //Try to init the lib
    if (!glfwInit())
    {
        Debug::error("failed\n");
        return;
    
    }
    
    Debug::success("done\n");
    
    //print lib info
    int major, minor, rev;
    glfwGetVersion(&major,&minor,&rev);
    printf("Library version: %i.%i rev %i\n\n",major,minor,rev);
    
}

//think about refactoring
//void glfwSetFramebufferSizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight)
//{
//	glViewport(0, 0, aWidth, aHeight);
//
//}

/*
 * initContext
 * void
 * void
 * Initializes the GLFW Window and the OpenGL context
 */
static void initContext(void)
{
    printf("GL and window initalization: ");
    
    m_Window = glfwCreateWindow(800, 800, "GL", NULL, NULL);
    if (!m_Window)
    {
        printf("failed\n");
        glfwTerminate();
        return;
	
    }
    
     /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);
	
    glfwSetWindowPos(m_Window, 250, 75);
    glClearColor(0.0f,0.0f,1.0f,0.0f);
    
    //print gl info
    int major, minor;
    glGetIntegerv(GL_MAJOR_VERSION,&major);
    glGetIntegerv(GL_MINOR_VERSION,&minor);
    printf("GL version: %i.%i\n",major,minor);
	printf("GLSL version: %s\n",glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("GL version: %s\n",glGetString(GL_VERSION));
	printf("Vendor: %s\n"     ,glGetString(GL_VENDOR) );
	printf("Renderer: %s\n"  ,glGetString(GL_RENDER) );

	//
	//glfwSetFramebufferSizeCallback(m_Window, glfwSetFramebufferSizeCallback);
    
}



/*
 * keyEventCallback
 * GLFWwindow*, int, int, int, int
 * void
 * test input func, TODO: refactor
 */
static void keyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
	
}

guar::ECS::SceneGraph* Engine::createScene(const std::string &aName)
{ 
	return EntityComponentSystem::createScene(aName);

}
