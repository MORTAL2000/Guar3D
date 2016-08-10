#include "ThreadGroup.h"

//std inc
#include <thread>

using namespace guar;
using namespace Threads;

ThreadGroup::ThreadGroup()
{
	int size = std::thread::hardware_concurrency();

	//for(int i = 0; i < size; i++)
	//	m_Threads.push_back(Thread());

}