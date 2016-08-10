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

		Input()  = delete;
		Input(const Input&) = delete;
		~Input() = delete;
		Input& operator=(const Input&) = delete;
		
		static void init(GLFWwindow* aWindow);

	public: //public interface
		static bool getKeyDown(const Key::KeyCode &aKeyCode);

	};

}

#endif