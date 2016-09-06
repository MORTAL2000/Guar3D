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
                GFXfloat x,y,z;          //pos
                GFXfloat u,v;	         //uv
                GFXfloat nX,nY,nZ;       //normal
                GFXfloat tX,tY,tZ;       //tangent
                GFXfloat bX,bY,bZ;       //bitangent
				GFXfloat bone1I,bone1W;  //Bone data 1
				GFXfloat bone2I,bone2W;  //Bone data 2
				GFXfloat bone3I,bone3W;  //Bone data 3
				GFXfloat bone4I,bone4W;  //Bone data 4
				GFXfloat bone5I,bone5W;  //Bone data 5

                //  ETC
    
                
            } Format;
            
            //Offsets
            extern const int PositionAttributeOffset;
            extern const int UVAttributeOffset;
            extern const int NormalAttributeOffset;
            extern const int TangentAttributeOffset;
            extern const int BitangentAttributeOffset;

			extern const int Bone1AttributeOffset;
			extern const int Bone2AttributeOffset;
			extern const int Bone3AttributeOffset;
			extern const int Bone4AttributeOffset;
			extern const int Bone5AttributeOffset;

            //Attribute sizes
            extern const int PositionAttributeSize;
            extern const int UVAttributeSize;
            extern const int NormalAttributeSize;
            extern const int TangentAttributeSize;
            extern const int BitangentAttributeSize;

			extern const int Bone1AttributeSize;
			extern const int Bone2AttributeSize;
			extern const int Bone3AttributeSize;
			extern const int Bone4AttributeSize;
			extern const int Bone5AttributeSize;

            
            void EnableAttributes(const GFXuint &aProgramHandle, const GFXuint &aVertexBufferHandle);
            
            //convenient instantiation function
            Format create
            (
                GFXfloat aX      =  0, GFXfloat aY      = 0, GFXfloat aZ  = 0, 
                GFXfloat aU      =  0, GFXfloat aV      = 0, 				  
                GFXfloat aNX     =  0, GFXfloat aNY     = 0, GFXfloat aNZ = 0, 
                GFXfloat aTX     =  0, GFXfloat aTY     = 0, GFXfloat aTZ = 0, 
                GFXfloat aBX     =  0, GFXfloat aBY     = 0, GFXfloat aBZ = 0,
				GFXfloat aBone1I = -1, GFXfloat aBone1W = 0,
				GFXfloat aBone2I = -1, GFXfloat aBone2W = 0,
				GFXfloat aBone3I = -1, GFXfloat aBone3W = 0,
				GFXfloat aBone4I = -1, GFXfloat aBone4W = 0,
				GFXfloat aBone5I = -1, GFXfloat aBone5W = 0
				            
            );
    
            class Data
            {
            private:
                std::vector<Vertex::Format> m_VertexData;
                GFXfloat* m_FloatArray; //revisit this
                
            public:
                void push_back(const Vertex::Format &aVertex){m_VertexData.push_back(aVertex);}
                int  size(void){return m_VertexData.size();}
				Vertex::Format* get(const size_t &i) { return &m_VertexData[i]; }
                GFXfloat* toArray(void);
                
                Data():m_FloatArray(0){};
                ~Data();
                    
            };
    
        }
        
    }

}

#endif