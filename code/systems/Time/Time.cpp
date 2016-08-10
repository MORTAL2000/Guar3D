#include "Time.h"

//debug inc
#include <Debug\Debug.h>
//external inc
#include <GLFW\glfw3.h>

using namespace guar;

//static variables
//etc

double Time::getTime(void)
{
	return glfwGetTime();

}

double Time::getDeltaTime(void)
{
	return glfwGetTimerFrequency();

}

void Time::init(void)
{



}

void Time::update(void)
{

	
}