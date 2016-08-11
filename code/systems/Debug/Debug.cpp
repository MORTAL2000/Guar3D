#include "Debug.h"

//external inc
#include <rlutil\rlutil.h>
//std inc
#include <iostream>

using namespace guar;

int Debug::Color::BLACK        = rlutil::BLACK        ;
int Debug::Color::BLUE         = rlutil::BLUE         ;
int Debug::Color::GREEN        = rlutil::GREEN        ;
int Debug::Color::CYAN         = rlutil::CYAN         ;
int Debug::Color::RED          = rlutil::RED          ;
int Debug::Color::MAGENTA      = rlutil::MAGENTA      ;
int Debug::Color::BROWN        = rlutil::BROWN        ;
int Debug::Color::GREY         = rlutil::GREY         ;
int Debug::Color::DARKGREY     = rlutil::DARKGREY     ;
int Debug::Color::LIGHTBLUE    = rlutil::LIGHTBLUE    ;
int Debug::Color::LIGHTGREEN   = rlutil::LIGHTGREEN   ;
int Debug::Color::LIGHTCYAN    = rlutil::LIGHTCYAN    ;
int Debug::Color::LIGHTRED     = rlutil::LIGHTRED     ;
int Debug::Color::LIGHTMAGENTA = rlutil::LIGHTMAGENTA ;
int Debug::Color::YELLOW       = rlutil::YELLOW       ;
int Debug::Color::WHITE        = rlutil::WHITE        ;

#include <thread>
void consoleInputThread()
{
	for (;;)
	{
		std::string buf;
		std::cin >> buf;

	}

}

void Debug::init(void) 
{
	std::thread t1(consoleInputThread);
	t1.detach();

}

void Debug::update(void) 
{
	
	
}

void Debug::setTextColor(const int &aColor)
{
	rlutil::setColor(aColor);

}

void Debug::print(const std::string &aMessage)
{


}