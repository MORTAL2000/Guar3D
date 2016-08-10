#ifndef GUAR_GRAPHICS_TEXTURECOLLECTION_H
#define GUAR_GRAPHICS_TEXTURECOLLECTION_H

#include <vector>
#include <string>
#include "../../Texture/Texture.h"
#include "../GraphicsObjectCollection.h"

namespace guar
{
    namespace GFX
    {
        class TextureCollection : public GraphicsObjectCollection<Texture>
        {
        public:
            void init(void) override;
            
            TextureCollection();
                    
        };

    }
    
}

#endif