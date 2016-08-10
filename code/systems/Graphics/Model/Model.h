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

namespace guar
{
    namespace GFX
    {
        class Model : public GraphicsObject
        {
			

        protected:
			//Model() {}//msvc2013 wants this?
            //std::string m_Name;
            GFXuint m_VertexBufferHandle;
            int m_VertexCount;
            
        public:    
            //accessors
            //std::string getName(void){return m_Name;}
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