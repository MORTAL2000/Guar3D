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
    class Debug final
    {
		friend class Engine; Debug() = delete; ~Debug() = delete;

		//Engine interface
		static void init(void);
		static void update(void);

		static void print(const std::string &aMessage);

		static void setTextColor(const int &aColor);

	public://Game programmer interface
		class Color final
		{
			Color() = delete;

		public:
			static int BLACK;
			static int BLUE;
			static int GREEN;
			static int CYAN;
			static int RED;
			static int MAGENTA;
			static int BROWN;
			static int GREY;
			static int DARKGREY;
			static int LIGHTBLUE;
			static int LIGHTGREEN;
			static int LIGHTCYAN;
			static int LIGHTRED;
			static int LIGHTMAGENTA;
			static int YELLOW;
			static int WHITE;

		};

		static void log() {}

		template<typename First, typename ...Rest>
		static void log(First && first, Rest && ...rest)
		{
			std::cout << std::forward<First>(first);				
			log(std::forward<Rest>(rest)...);
			
		}

		template<typename First, typename ...Rest>
		static void error(First && first, Rest && ...rest)
		{
			setTextColor(Color::RED);
			std::cout << std::forward<First>(first);
			log(std::forward<Rest>(rest)...);
			setTextColor(Color::WHITE);

		}

		template<typename First, typename ...Rest>
		static void success(First && first, Rest && ...rest)
		{
			setTextColor(Color::GREEN);
			std::cout << std::forward<First>(first);
			log(std::forward<Rest>(rest)...);
			setTextColor(Color::WHITE);

		}

		template<typename First, typename ...Rest>
		static void alert(First && first, Rest && ...rest)
		{
			setTextColor(Color::MAGENTA);
			std::cout << std::forward<First>(first);
			log(std::forward<Rest>(rest)...);
			setTextColor(Color::WHITE);

		}

		template<typename First, typename ...Rest>
		static void announce(First && first, Rest && ...rest)
		{
			setTextColor(Color::YELLOW);
			std::cout 
				<< "\n\n*****************\n"
				<< std::forward<First>(first)
				<<   "\n*****************\n\n"
				;
			log(std::forward<Rest>(rest)...);
			setTextColor(Color::WHITE);

		}

		template<typename First, typename ...Rest>
		static void clog(const int &aColor,First && first, Rest && ...rest)
		{
			setTextColor(aColor);
	
			std::cout << std::forward<First>(first);
			log(std::forward<Rest>(rest)...);
			setTextColor(Debug::TextColor::WHITE);

		}
        
    };

}

#endif