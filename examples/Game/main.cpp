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
	Engine::mainInit();

	Game::init();

	Engine::mainLoop();

    return 0;
    
}








