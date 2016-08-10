#ifndef GUAR_GRAPHICS_RENDERTEXTURECOLLECTION_H
#define GUAR_GRAPHICS_RENDERTEXTURECOLLECTION_H

#include "../GraphicsObjectCollection.h"
#include "../../RenderTexture/RenderTexture.h"

namespace guar
{
    namespace GFX
    {    
        class RenderTextureCollection : public GraphicsObjectCollection<RenderTexture>
        {
        public:
            void init(void) override;
    
    
        };

    }
        
}

#endif