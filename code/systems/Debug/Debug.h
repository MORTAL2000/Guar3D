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
	public:
		static void log() {}

		template<typename First, typename ...Rest>
		static void log(First && first, Rest && ...rest)
		{
			std::cout << std::forward<First>(first);
			log(std::forward<Rest>(rest)...);

		}
        
        
    };

}

#endif