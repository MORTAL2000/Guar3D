#ifndef GUAR_GRAPHICS_SKYBOX
#define GUAR_GRAPHICS_SKYBOX

/*
 * Skybox
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
            class Skybox : public StaticShaderProgram
            {
            public:
                Skybox();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif