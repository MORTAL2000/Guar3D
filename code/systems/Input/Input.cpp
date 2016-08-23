#include "Input.h"

//Debug inc
#include <Debug\Debug.h>
//dep inc
#include <GLFW\glfw3.h>
//graphics inc
#include <Graphics\Graphics.h>

using namespace guar;

static GLFWwindow* s_Window = 0;
//mouse pos
static Math::Vector2 s_MousePosition;
static Math::Vector2 s_MousePositionDelta;
static Math::Vector2 s_OldMousePosition;

//Mouse buttons
MouseButton::MouseButtonCode s_Mouse_One   ;
MouseButton::MouseButtonCode s_Mouse_Two   ;
MouseButton::MouseButtonCode s_Mouse_Three ;
MouseButton::MouseButtonCode s_Mouse_Four  ;
MouseButton::MouseButtonCode s_Mouse_Five  ;
MouseButton::MouseButtonCode s_Mouse_Six   ;
MouseButton::MouseButtonCode s_Mouse_Seven ;
MouseButton::MouseButtonCode s_Mouse_Eight ;
MouseButton::MouseButtonCode s_Mouse_Last  ;
MouseButton::MouseButtonCode s_Mouse_Left  ;
MouseButton::MouseButtonCode s_Mouse_Right ;
MouseButton::MouseButtonCode s_Mouse_Middle;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	s_MousePosition.x = xpos;
	s_MousePosition.y = ypos;

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
		case (GLFW_MOUSE_BUTTON_1) : s_Mouse_One    = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_2) : s_Mouse_Two    = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_3) : s_Mouse_Three  = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_4) : s_Mouse_Four   = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_5) : s_Mouse_Five   = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_6) : s_Mouse_Six    = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_7) : s_Mouse_Seven  = (action == GLFW_PRESS)? true : false; break;
		case (GLFW_MOUSE_BUTTON_8) : s_Mouse_Eight  = (action == GLFW_PRESS)? true : false; break;

	}

}

bool Input::getKeyDown(const Key::KeyCode &aKeyCode)
{
	return glfwGetKey(s_Window, aKeyCode);

}

bool Input::getMouseButtonDown(const MouseButton::MouseButtonCode &aMouseButtonCode)
{
	if (aMouseButtonCode == MouseButton::One   ){return s_Mouse_One   ;}
	if (aMouseButtonCode == MouseButton::Two   ){return s_Mouse_Two   ;}
	if (aMouseButtonCode == MouseButton::Three ){return s_Mouse_Three ;}
	if (aMouseButtonCode == MouseButton::Four  ){return s_Mouse_Four  ;}
	if (aMouseButtonCode == MouseButton::Five  ){return s_Mouse_Five  ;}
	if (aMouseButtonCode == MouseButton::Six   ){return s_Mouse_Six   ;}
	if (aMouseButtonCode == MouseButton::Seven ){return s_Mouse_Seven ;}
	if (aMouseButtonCode == MouseButton::Eight ){return s_Mouse_Eight ;}

	return false;
			  
}			  

Math::Vector2 Input::getMousePos(void)
{
	return s_MousePosition / Graphics::getWindowSize();

}

void Input::lockMouse(const bool &aState)
{
	if (aState == true)
		glfwSetInputMode(s_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	else
		glfwSetInputMode(s_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Input::init(GLFWwindow* aWindow)
{
	Debug::announce("Engine init: Input initializing...");

	s_Window = aWindow;

	glfwSetCursorPosCallback  (s_Window, cursor_position_callback);
	glfwSetMouseButtonCallback(s_Window, mouse_button_callback   );

}

Math::Vector2 Input::getMouseDelta(void)
{
	return s_MousePositionDelta;

}

void Input::update(void)
{
	s_MousePositionDelta = Input::getMousePos() - s_OldMousePosition;
	s_OldMousePosition = Input::getMousePos();

	glfwPollEvents();//refactor

	
}