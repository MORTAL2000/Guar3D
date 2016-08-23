#ifndef INPUT_H
#define INPUT_H
/*
 *
 *
*/
//input inc
#include "Key\Key.h"
#include "MouseButton\MouseButton.h"
//math inc
#include <Math\Vector2\Vector2.h>

struct GLFWwindow;

namespace guar
{
	class Input
	{
		friend class Engine;

		Input() = delete; ~Input() = delete;

		static void init(GLFWwindow* aWindow);
		static void update(void);

	public: //public interface
		//keyboard
		static bool getKeyDown(const Key::KeyCode &aKeyCode);
		//mouse		
		static bool getMouseButtonDown(const MouseButton::MouseButtonCode &aMouseButtonCode);
		static Math::Vector2 getMousePos(void);
		static Math::Vector2 getMouseDelta(void);
		//getmousepos
		static void lockMouse(const bool &aState);

		//joysticks
		//joystick getJoystick(Input::JoystickHandle aJoystickHandle);

	};

}

#endif