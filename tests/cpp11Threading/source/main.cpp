/*
 *
 *
 */
#include "ThreadGroup\ThreadGroup.h"

#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include <future>

using namespace guar;
using namespace Threads;

#define WORKSIZE 100000
#define THREADGROUPSIZE 1000


int output[WORKSIZE];
std::thread thread[THREADGROUPSIZE];

int i = 0;

void asdf(int* index)
{
	output[*index] = 100 * 23 / 64;

	*index++;
	i++;

	
}

int main()
{	
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

	////MULTITHREAD THREAD
	//for (int j = 0; j < THREADGROUPSIZE; j++)
	//{
	//	thread[j] = std::thread(asdf, &i);
	//
	//}
	//
	//for (; i < WORKSIZE;)
	//{
	//	for (int j = 0; j < THREADGROUPSIZE; j++)
	//	{
	//		if (thread[j].joinable())
	//		{
	//			thread[j].join();
	//			thread[j] = std::thread(asdf, &i);
	//
	//		}
	//		
	//	
	//	}
	//	
	//	//for (int j = 0; j < THREADGROUPSIZE; j++)
	//	//{
	//	//	if (thread[j].joinable())
	//	//	{
	//	//		thread[j].join();
	//	//		
	//	//	}
	//	//
	//	//}
	//
	////	std::cout << WORKSIZE << ": " << i << "\n";
	//
	//}

	//MULTITHREAD ASYNC
	std::future<int> fut = std::async(asdf, i);

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Time: " << elapsed_seconds.count() << "\n";

	start = std::chrono::system_clock::now();

	//SINGLE THREAD
	for (i = 0; i < WORKSIZE; i++)
	{
		output[i] = 100 * 23 / 64;
	//	std::cout << WORKSIZE << ": " << i << "\n";
	}

	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "Time: " << elapsed_seconds.count() << "\n";

	//std::cout << "\n**\noutput: \n**\n";
	//for (int i = 0; i < WORKSIZE; i++)
	//	std::cout << output[i] << "\n";

	std::string wait;
	std::cin >> wait;
	return 0;

}