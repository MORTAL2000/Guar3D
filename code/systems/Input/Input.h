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
	private: //class function rules
		Input()  = delete;
		Input(const Input&) = delete;
		~Input() = delete;
		Input& operator=(const Input&) = delete;
		friend class Engine;

	private: //private methods
		static void init(GLFWwindow* aWindow);

	private: //data members
		static GLFWwindow* m_Window;

	public: //public interface
		static bool getKeyDown(const Key::KeyCode &aKeyCode);

	};

}

#endif