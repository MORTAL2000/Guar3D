#ifndef GUAR_GRAPHICS_SHADERPROGRAMCOLLECTION_H
#define GUAR_GRAPHICS_SHADERPROGRAMCOLLECTION_H
/*
 * ShaderProgramCollection.h
 * 
*/
//graphics includes
#include "../../ShaderProgram/ShaderProgram.h"
#include "../../ShaderProgram/DynamicShaderProgram/DynamicShaderProgram.h"

#include "../GraphicsObjectCollection.h"

//stdlib includes
#include <vector>
#include <string>

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdexcept>
#include<iostream>

namespace guar
{ 
    namespace GFX
    {
        class DynamicShaderProgram;
    
        class ShaderProgramCollection : public GraphicsObjectCollection<ShaderProgram, DynamicShaderProgram>
        {
        public:
            void init(void) override;
    
            ShaderProgramCollection();
            
            
            template<class T>
            void loadStaticShader();
    
        };

    }
        
}

#endif