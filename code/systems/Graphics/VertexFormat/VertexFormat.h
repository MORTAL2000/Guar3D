#ifndef GUAR_GRAPHICS_VERTEXFORMAT_H
#define GUAR_GRAPHICS_VERTEXFORMAT_H
/*
 * Maintains vertex format, provides offset, size, format etc. info
 * 
*/
#include "../GraphicsTypes.h"
#include <vector>

namespace guar
{
    namespace GFX
    {
        namespace Vertex
        {
            //WARNING: be sure to update Vertex::Data::toArray(void) implementation to reflect any additions/order changes to the struct
            typedef struct
            {
                GFXfloat x,y,z;
                GFXfloat u,v;
                GFXfloat nX,nY,nZ;
                GFXfloat tX,tY,tZ;
                GFXfloat bX,bY,bZ;
                
                //  ETC
    
                
            } Format;
            
            //Offsets
            extern const int PositionAttributeOffset;
            extern const int UVAttributeOffset;
            extern const int NormalAttributeOffset;
            extern const int TangentAttributeOffset;
            extern const int BitangentAttributeOffset;
            
            //Attribute sizes
            extern const int PositionAttributeSize;
            extern const int UVAttributeSize;
            extern const int NormalAttributeSize;
            extern const int TangentAttributeSize;
            extern const int BitangentAttributeSize;
            
            void EnableAttributes(const GFXuint &aProgramHandle, const GFXuint &aVertexBufferHandle);
            
            //convenient instantiation function
            Format create
            (
                GFXfloat aX  = 0, GFXfloat aY  = 0, GFXfloat aZ  = 0, 
                GFXfloat aU  = 0, GFXfloat aV  = 0, 
                GFXfloat aNX = 0, GFXfloat aNY = 0, GFXfloat aNZ = 0,
                GFXfloat aTX = 0, GFXfloat aTY = 0, GFXfloat aTZ = 0,
                GFXfloat aBX = 0, GFXfloat aBY = 0, GFXfloat aBZ = 0
            
            );
    
            class Data
            {
            private:
                std::vector<Vertex::Format> m_VertexData;
                GFXfloat* m_FloatArray;
                
            public:
                void push_back(const Vertex::Format &aVertex){m_VertexData.push_back(aVertex);}
                int  size(void){return m_VertexData.size();}
                GFXfloat* toArray(void);
                
                Data():m_FloatArray(0){};
                ~Data();
                    
            };
    
        }
        
    }

}

#endif