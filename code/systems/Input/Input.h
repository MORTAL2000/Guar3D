#ifndef INPUT_H
#define INPUT_H
/*
 *
 *
*/
#include "Key\Key.h"

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
		static bool getKeyDown(const Key::KeyCode &aKeyCode);

	};

}

#endif