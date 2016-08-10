#ifndef GUAR_THREADS_THREAD_H
#define GUAR_THREADS_THREAD_H
/*
*
*
*
*/
//std inc
#include<thread>

namespace guar
{
	namespace Threads
	{
		typedef void (*workFunction)(int);

		class Thread
		{
			Thread() = delete;

			std::thread m_Thread;
			bool m_IsReady;

			void threadWork(workFunction);
			
		public:
			Thread(workFunction);
			bool isReady(void);


		};

	}

}

#endif