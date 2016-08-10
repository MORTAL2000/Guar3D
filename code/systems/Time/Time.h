#ifndef GUAR_TIME_H
#define GUAR_TIME_H
/* 
 * Time.h
 * 
 * 
*/
namespace guar
{
	class Time
	{
		friend class Engine;

		Time() = delete; ~Time() = delete;

		static void init(void);
		static void update(void);

	public:
		static double getTime(void);
		static double getDeltaTime(void);

	};

}

#endif