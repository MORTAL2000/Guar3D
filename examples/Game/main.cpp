/*
 * main.cpp
 * example usage of game engine
 * 
*/

//Game inc
#include "Game/Game.h"
//Engine inc
#include <Engine/Engine.h>
//Std inc
#include <stdio.h>
#include <Debug\Debug.h>

using namespace guar;

int main(void)
{
	try
	{
		Engine::mainInit();

		Game::init();

		Engine::mainLoop();

	}
	catch (std::runtime_error& e)
	{
		Debug::log(e.what());

	}

    return 0;
    
}








