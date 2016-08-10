#ifndef GUAR_GRAPHICS_GRAPHICSOBJECT_H
#define GUAR_GRAPHICS_GRAPHICSOBJECT_H
/* 
 * 
 * 
*/
//stdinc
#include <string>

namespace guar
{
    namespace GFX
    {
        class GraphicsObject
        {
        protected:
            std::string m_Name;
    
        public:
            std::string getName(void) { return m_Name; }
    
            GraphicsObject(const char* aName);
            GraphicsObject();
    
        };

    }
    
}

#endif