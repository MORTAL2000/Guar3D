#ifndef GUAR_DEBUG_H
#define GUAR_DEBUG_H
/*
 * 
 * 
*/

//stdlib includes
#include <string>
#include <iostream>

namespace guar
{
    class Debug
    {
		friend class Engine; Debug() = delete; ~Debug() = delete;

		//Engine interface
		void init(void);
		void update(void);

		void print(const std::string &aMessage);

	public: //Game programmer interface
		enum TextColor
		{
			BLACK,
			BLUE,
			GREEN,
			CYAN,
			RED,
			MAGENTA,
			BROWN,
			GREY,
			DARKGREY,
			LIGHTBLUE,
			LIGHTGREEN,
			LIGHTCYAN,
			LIGHTRED,
			LIGHTMAGENTA,
			YELLOW,
			WHITE

		};

	private:
		static void setTextColor(const Debug::TextColor &aColor);

		//static void dolog() {}
		//template<typename First, typename ...Rest>
		//static void dolog(First && first, Rest && ...rest)
		//{
		//	std::cout << std::forward<First>(first);
		//	dolog(std::forward<Rest>(rest)...);
		//
		//}

	public:
		template<typename First, typename ...Rest>
		static void log(First && first, Rest && ...rest)
		{
			//if (std::is_same<First, enum TextColor>::value == true)
			//{
			//	setTextColor(first);
			//
			//}

		//	if (std::is_same<First, TextColor>::value == true)
		//	{
		//		//if (first == YELLOW)
				//setTextColor(YELLOW);
			
			//}
			//else
			//{
				std::cout << std::forward<First>(first);
				

			//}
			//
			//dolog(std::forward<Rest>(rest)...);
			//
			//setTextColor(TextColor::WHITE);

		}

		//template
		//<
		//	typename First,
		//	typename... Rest,
		//	typename = EnableIf
		//	<std::is_same<Decay<LastType<Rest...>>,TextColor>::value
		//>
		//static void log(First && first, Rest && ...rest)
		//{
		//	std::cout << std::forward<First>(first);
		//	log(std::forward<Rest>(rest)...);
		//
		//}
		

		
        
    };

}

#endif