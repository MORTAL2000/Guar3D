#ifndef GRAPHICS_STATICSHADERS_RENDERTEXTUREDEPTHDISPLAY_H
#define GRAPHICS_STATICSHADERS_RENDERTEXTUREDEPTHDISPLAY_H

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
            class RenderTextureDepthDisplay : public StaticShaderProgram
            {
            public:
                RenderTextureDepthDisplay();
                
            protected:
                virtual void glDrawCalls(void) override;
                virtual std::string vertexShaderGLSL(void) override;
                virtual std::string fragmentShaderGLSL(void) override;
                
            };
        
        }

    }
        
}
#endif