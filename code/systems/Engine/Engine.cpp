#include "Engine.h"

//library includes
#include "../Graphics/OpenGL/OpenGL.h"

//engine components
#include "../Graphics/Graphics.h"
#include <debug/Debug.h>
#include "../Graphics/ShaderProgram/ShaderProgram.h"
#include "../EntityComponentSystem/ComponentTypeRegistry/ComponentTypeRegistry.h"
#include <input/Input.h>
#include <EntityComponentSystem\EntityComponentSystem.h>
#include <Time/Time.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>

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
//ECS::SceneGraphCollection Engine::m_SceneGraphs;

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
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_Window) )
    {
		EntityComponentSystem::update();
		Graphics::update();
		glfwPollEvents();
		Time::update();
	
    }

    glfwTerminate();
    
}

void Engine::mainInit(void)
{
	
	Engine::init();
    Graphics::init(m_Window);
	EntityComponentSystem::init();
	Input::init(m_Window);
	Time::init();

	Debug::log(Debug::CYAN, "\n\n****\nEngine init: Sound initializing...\n****\n");

	Debug::log(Debug::GREEN, "\n\n****\nEngine init: Network initializing...\n****\n");

	Debug::log("\n\n****\nEngine init complete\n****\n");

}

void Engine::init(void)
{
	Debug::log("\n\n****\nEngine init: Libraries are initializing...\n****\n");
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
    printf("initializing extension loader \"GLEW\"\n");
    
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        
    }
    
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION)); 
    
}

/*
 * initGLFW
 * void
 * void
 * Initializes the GLFW Window, time & input library
 */
static void initGLFW(void)
{
    printf("GLFW initalization: ");
    //Try to init the lib
    if (!glfwInit())
    {
        printf("failed\n");
        return;
    
    }
    
    printf("done\n");
    
    //print lib info
    int major, minor, rev;
    glfwGetVersion(&major,&minor,&rev);
    printf("Library version: %i.%i rev %i\n\n",major,minor,rev);
    
}

//think about refactoring
void glfwSetFramebufferSizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight)
{
	glViewport(0, 0, aWidth, aHeight);

}

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
	glfwSetFramebufferSizeCallback(m_Window, glfwSetFramebufferSizeCallback);
    
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
		
	//if (key == GLFW_KEY_A && action == GLFW_PRESS)
	//	printf("A pressed\n");
        
    if (key == GLFW_KEY_GRAVE_ACCENT && action == GLFW_PRESS)
    {
        int n;
        std::cin >> n;
        
    }
	
}

guar::ECS::SceneGraph* Engine::createScene(const std::string &aName)
{ 
	return EntityComponentSystem::createScene(aName);

}
