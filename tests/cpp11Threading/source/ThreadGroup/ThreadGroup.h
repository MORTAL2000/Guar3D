#ifndef GUAR_THREADS_THREADGROUP_H
#define GUAR_THREADS_THREADGROUP_H
/*
 *
 *
 *
*/
//std inc
#include <vector>

#include "../Thread/Thread.h"

namespace guar
{
	namespace Threads
	{
		//class Thread;

		class ThreadGroup
		{
			std::vector<Threads::Thread> m_Threads;

		public:
			ThreadGroup();

		};

	}

}

#endif