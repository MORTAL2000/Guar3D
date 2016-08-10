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
	Debug::log("\n\n****\nEngine init: Input initializing...\n****\n");

	s_Window = aWindow;

}