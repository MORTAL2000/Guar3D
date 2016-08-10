#include "Time.h"

//debug inc
#include <Debug\Debug.h>

//external inc
#include <GLFW\glfw3.h>

using namespace guar;

double Time::lastFrameTime = 0;

double Time::getTime(void)
{
	return glfwGetTime();

}

double Time::getDeltaTime(void)
{
	return glfwGetTimerFrequency();  //getTime() - lastFrameTime;

}

void Time::init(void)
{



}

void Time::update(void)
{
	lastFrameTime = getTime();

	
}