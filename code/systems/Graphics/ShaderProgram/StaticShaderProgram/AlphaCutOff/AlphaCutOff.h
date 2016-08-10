#ifndef GUAR_GRAPHICS_ALPHACUTOFF_H
#define GUAR_GRAPHICS_ALPHACUTOFF_H

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
            class AlphaCutOff : public StaticShaderProgram
            {
            public:
                AlphaCutOff();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif