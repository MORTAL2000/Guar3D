#ifndef GUAR_GRAPHICS_RENDERLIGHT_H
#define GUAR_GRAPHICS_RENDERLIGHT_H

#include "../RenderObserver/RenderObserver.h"

namespace guar
{
    namespace GFX
    {
        class RenderTexture;
    
        class RenderLight : public RenderObserver
        {
        public:
            void draw(void) override;
    
            RenderLight();
    
            void generateViewProjectionMatrix(glm::mat4x4* aViewMatrix, glm::mat4x4* aProjectionMatrix, glm::mat4x4* aVPMatrix) override;
            
        };

    }
        
}

#endif