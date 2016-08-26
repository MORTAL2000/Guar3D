/*
 *  Model.h
 *  
 *  
*/
#ifndef GUAR_GRAPHICS_MODEL_H
#define GUAR_GRAPHICS_MODEL_H

/*
 * Model
 * 
*/
#include <string>
#include "../GraphicsTypes.h"
#include "../VertexFormat/VertexFormat.h"
#include "../GraphicsObject/GraphicsObject.h"
#include "../Skeleton/Skeleton.h"
#include "../Animation/Animation.h"

namespace guar
{
    namespace GFX
    {
        class Model : public GraphicsObject
        {
			//animation data
			GFX::Skeleton m_Skeleton;
			std::vector<GFX::Animation> m_Animations;
						
			//gpu data
            GFXuint m_VertexBufferHandle;
            int     m_VertexCount;
            
			void animate(void);

        public:    
            int getVertexCount(void) { return m_VertexCount; }
            
            void draw(const GFXuint &programHandle);
			
                    
            //constructors    
            Model(const std::string &aFileName, const std::string &aMeshName = "");
            Model(const std::string &aName, Vertex::Data aVertexData);
    
        private:
            Vertex::Data loadMeshFromFile(const std::string &aFileName, const std::string &aMeshName = "");
            
        };

    }
        
}

#endif