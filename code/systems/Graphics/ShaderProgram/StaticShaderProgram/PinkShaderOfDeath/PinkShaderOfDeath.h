#ifndef GUAR_GRAPHICS_PINKSHADEROFDEATH_H
#define GUAR_GRAPHICS_PINKSHADEROFDEATH_H

/*
 * Fallback shader used when a shader under development fails to compile.
 * Visually obnoxious, makes it very obvious something went wrong with the
 * renderobject being rendered. 
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
            class PinkShaderOfDeath : public StaticShaderProgram
            {
            public:
                PinkShaderOfDeath();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif