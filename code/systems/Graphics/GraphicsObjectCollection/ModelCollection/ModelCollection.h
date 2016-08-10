#ifndef GUAR_GRAPHICS_MODELCOLLECTION_H
#define GUAR_GRAPHICS_MODELCOLLECTION_H

/*
 * ModelCollection
 * 
*/

#include "../../Model/Model.h"
#include "../GraphicsObjectCollection.h"

#include <vector>
#include <string>

namespace guar
{
    namespace GFX
    {
        class ModelCollection : public GraphicsObjectCollection<Model>
        {
        public:
            void init(void) override;
    
            ModelCollection();
    
            
        };

    }
    
}

#endif