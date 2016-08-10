#ifndef GUAR_GRAPHICS_GRAPHICSTYPES_H
#define GUAR_GRAPHICS_GRAPHICSTYPES_H

/*
 * GraphicsTypes.h
 * defines handle types for working with the Graphics abstraction
 * 
 */

namespace guar
{
    namespace GFX
    {
        typedef          long int   GFXint   ;
        typedef unsigned long int   GFXuint  ; //handle to graphics objects
        typedef               float GFXfloat ;
    
        struct Color
        {
            float r,g,b,a;
    
            Color() : Color(0, 0, 0, 0) {}
            Color(const float &aR, const float &aG, const float &aB, const float &aA) : 
                r(aR), b(aB), g(aG), a(aA) 
            {}
    
        };
    
    }
    
}

#endif