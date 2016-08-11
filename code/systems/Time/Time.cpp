#include "Time.h"

//debug inc
#include <Debug\Debug.h>
//external inc
#include <GLFW\glfw3.h>

using namespace guar;

//static variables
//etc
double currentTime;
double lastTime;

double Time::getTime(void)
{
	return glfwGetTime();

}

double Time::getDeltaTime(void)
{
	return currentTime;

}

void Time::init(void)
{
	currentTime = 0;
	lastTime = 0;

}

void Time::update(void)
{
	currentTime = glfwGetTime() - lastTime;
	lastTime = glfwGetTime();

	//Debug::log(currentTime,"\n");
	
}