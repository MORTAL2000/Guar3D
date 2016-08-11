#include "Input.h"

//Debug inc
#include <Debug\Debug.h>
//dep inc
#include <GLFW\glfw3.h>

using namespace guar;

static GLFWwindow* s_Window = 0;

bool Input::getKeyDown(const Key::KeyCode &aKeyCode)
{
	return glfwGetKey(s_Window, aKeyCode);

}

void Input::init(GLFWwindow* aWindow)
{
	Debug::announce("Engine init: Input initializing...");

	s_Window = aWindow;

}