#ifndef GRAPHICS_STATICSHADERS_RENDERTEXTURECOLORDISPLAY_H
#define GRAPHICS_STATICSHADERS_RENDERTEXTURECOLORDISPLAY_H

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
            class RenderTextureColorDisplay : public StaticShaderProgram
            {
            public:
                RenderTextureColorDisplay();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif