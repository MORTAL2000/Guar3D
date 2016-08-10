#include "Input.h"

//Debug inc
#include <Debug\Debug.h>
//dep inc
#include <GLFW\glfw3.h>

using namespace guar;

GLFWwindow* Input::m_Window = 0;

bool Input::getKeyDown(const Key::KeyCode &aKeyCode)
{
	return glfwGetKey(m_Window, aKeyCode);

}

void Input::init(GLFWwindow* aWindow)
{
	Debug::log("\n\n****\nEngine init: Input initializing...\n****\n");

	m_Window = aWindow;

}