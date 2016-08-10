#include "Thread.h"

using namespace guar;
using namespace Threads;

void Thread::threadWork(workFunction aWorkFunction)
{
	
	m_IsReady = true;

}

void fuck(int i) {}

Thread::Thread(workFunction aWorkFunction)
{
	m_Thread = std::thread(fuck,1);

}

bool Thread::isReady()
{
	return m_IsReady;

}