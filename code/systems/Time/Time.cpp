#include "Time.h"

//debug inc
#include <Debug\Debug.h>
//external inc
#include <GLFW\glfw3.h>
//std inc
#include <iostream>
#include <chrono>

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

	//Debug::log(getDeltaTime(),"\n");

	/*
	//refactor
			using std::chrono::nanoseconds;
			using std::chrono::duration_cast;
			auto t0 = std::chrono::high_resolution_clock::now();
			auto t1 = std::chrono::high_resolution_clock::now();
			nanoseconds ns = duration_cast<nanoseconds>(t1 - t0);
			//Debug::log(ns.count(),"\n");
	*/
	
}