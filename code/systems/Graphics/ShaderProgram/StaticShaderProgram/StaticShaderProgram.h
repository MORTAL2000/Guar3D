#ifndef GUAR_GRAPHICS_STATICSHADERPROGRAM_H
#define GUAR_GRAPHICS_STATICSHADERPROGRAM_H

/*
 * StaticShaderProgram.h
 * 
 * A static shader program has its source code compiled into the binary. 
 * Pro: Faster than a dynamic shader program.
 * Con: The source code cannot be modified at runtime.
 * 
 * Usage:
 * implement all pure virtual functions, call the (string,string) constructor from the derived class constructor.
 * Failing to do these things will result in compiler errors.
 * 
*/

#include "../ShaderProgram.h"

#include "string.h"

namespace guar
{
    namespace GFX
    {
        class StaticShaderProgram : public ShaderProgram
        {
        public:
            StaticShaderProgram(const std::string &aName, const std::string &aVertexSource, const std::string &aFragmentSource);
            
        protected:
            virtual void glDrawCalls(void) = 0;
            virtual std::string vertexShaderGLSL(void) = 0;
            virtual std::string fragmentShaderGLSL(void) = 0;
            
            
            
        };

    }
    
}

#endif