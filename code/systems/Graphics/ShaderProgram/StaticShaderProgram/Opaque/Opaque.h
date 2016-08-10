#ifndef GRAPHICS_SHADERPROGRAM_STATICSHADER_OPAQUE_H
#define GRAPHICS_SHADERPROGRAM_STATICSHADER_OPAQUE_H

/*
 * 
 * 
*/

#include <string>
#include "../StaticShaderProgram.h"

namespace guar
{
    namespace GFX
    {
        namespace staticShaders
        {
            class Opaque : public StaticShaderProgram
            {
            public:
                Opaque();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif