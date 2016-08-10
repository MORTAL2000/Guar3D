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

		//Data members
		static double lastFrameTime;

	public:
		static double getTime(void);
		static double getDeltaTime(void);

		static void init(void);
		static void update(void);
		
	};

}

#endif