#include "VertexFormat.h"
#include <stdlib.h>
//#include <iostream>
#include <stddef.h>
#include "../OpenGL/OpenGL.h"
#include <debug\Debug.h>


using namespace guar;
using namespace GFX;

const int Vertex::PositionAttributeOffset  = offsetof(Vertex::Format, x )/sizeof(GFXfloat);
const int Vertex::UVAttributeOffset        = offsetof(Vertex::Format, u )/sizeof(GFXfloat);
const int Vertex::NormalAttributeOffset    = offsetof(Vertex::Format, nX)/sizeof(GFXfloat);
const int Vertex::TangentAttributeOffset   = offsetof(Vertex::Format, tX)/sizeof(GFXfloat);
const int Vertex::BitangentAttributeOffset = offsetof(Vertex::Format, tX)/sizeof(GFXfloat);

const int Vertex::PositionAttributeSize  = 3;
const int Vertex::UVAttributeSize        = 2;
const int Vertex::NormalAttributeSize    = 3;
const int Vertex::TangentAttributeSize   = 3;
const int Vertex::BitangentAttributeSize = 3;

Vertex::Format Vertex::create(GFXfloat aX, GFXfloat aY, GFXfloat aZ, GFXfloat aU, GFXfloat aV, GFXfloat aNX, GFXfloat aNY, GFXfloat aNZ, GFXfloat aTX, GFXfloat aTY, GFXfloat aTZ, GFXfloat aBX, GFXfloat aBY, GFXfloat aBZ)
{
    Vertex::Format vertex;
    
    //Pos
    vertex.x = aX;
    vertex.y = aY;
    vertex.z = aZ;
    
    //UV
    vertex.u = aU;
    vertex.v = aV;
    
	//Normal
    vertex.nX = aNX;
    vertex.nY = aNY;
    vertex.nZ = aNZ;

	//Tangent
	vertex.tX = aTX;
	vertex.tY = aTY;
	vertex.tZ = aTZ;

	//Bitangent
	vertex.bX = aBX;
	vertex.bY = aBY;
	vertex.bZ = aBZ;
    
    //  ETC

    return vertex;
    
}

static void enableAttribute(const std::string &aAttributeName, const GFXuint &aProgramHandle, const GFXuint attributeSize, const GFXuint attributeOffset)
{
    GLint attribute = glGetAttribLocation(aProgramHandle, aAttributeName.c_str() ); //Graphics::shader_programme, "a_Pos" );
        
    if (attribute ==-1)
        return;
        
    glEnableVertexAttribArray(attribute);
    
    //Create vertex attribute pointers..
    //Position attribute pointer
    glVertexAttribPointer
    (
        attribute, //Position attribute index
        attributeSize, //Pos size
        GL_FLOAT, //data type of each member of the format (must be uniform, look at glbindbufferdata, it takes an array or ptr to an array, so no suprise)
        GL_FALSE, 
        sizeof(Vertex::Format), //stride is size of vertex format in bytes
        (void*)(sizeof(GFXfloat)*attributeOffset)  
    
    );
        
}

void Vertex::EnableAttributes(const GFXuint &aProgramHandle, const GFXuint &aVertexBufferHandle)
{
    glBindBuffer( GL_ARRAY_BUFFER, aVertexBufferHandle);
    
    enableAttribute("a_Position" , aProgramHandle, Vertex::PositionAttributeSize , Vertex::PositionAttributeOffset );
    enableAttribute("a_UV"       , aProgramHandle, Vertex::UVAttributeSize       , Vertex::UVAttributeOffset       );
    enableAttribute("a_Normal"   , aProgramHandle, Vertex::NormalAttributeSize   , Vertex::NormalAttributeOffset   );
	enableAttribute("a_Tangent"  , aProgramHandle, Vertex::TangentAttributeSize  , Vertex::TangentAttributeOffset  );
	enableAttribute("a_Bitangent", aProgramHandle, Vertex::BitangentAttributeSize, Vertex::BitangentAttributeOffset);

    //glBindBuffer( GL_ARRAY_BUFFER, 0);
    
}

GFXfloat* Vertex::Data::toArray(void)
{
    //allocate memory
    if (m_FloatArray !=0)
        free(m_FloatArray);
    
    m_FloatArray = (GFXfloat*)malloc(sizeof(Vertex::Format)*m_VertexData.size());
    
    //copy data from vec to float array @ ptr
    for(unsigned int i = 0; i < m_VertexData.size(); i++)
    {
        //Position
        *m_FloatArray++ = m_VertexData[i].x;
        *m_FloatArray++ = m_VertexData[i].y;
        *m_FloatArray++ = m_VertexData[i].z;
        
        //UV
        *m_FloatArray++ = m_VertexData[i].u;
        *m_FloatArray++ = m_VertexData[i].v;
        
        //Normal
        *m_FloatArray++ = m_VertexData[i].nX;
        *m_FloatArray++ = m_VertexData[i].nY;
        *m_FloatArray++ = m_VertexData[i].nZ;

		//Tangent
		*m_FloatArray++ = m_VertexData[i].tX;
		*m_FloatArray++ = m_VertexData[i].tY;
		*m_FloatArray++ = m_VertexData[i].tZ;

		//Bitangent
		*m_FloatArray++ = m_VertexData[i].bX;
		*m_FloatArray++ = m_VertexData[i].bY;
		*m_FloatArray++ = m_VertexData[i].bZ;

        
        //  ETC
        
        //std::cout << "Vertex #" << i << ": " << m_VertexData[i].x << ", " << m_VertexData[i].y << ", " << m_VertexData[i].z << "\n";
        
        
    }
    
    //rewind the ptr
    m_FloatArray-= m_VertexData.size()*(sizeof(Vertex::Format)/sizeof(GFXfloat));
    
    return m_FloatArray;
    
}

Vertex::Data::~Data()
{
    if (m_FloatArray != 0)
    {
        Debug::log("Vertex::Data::~Data()\n");
        free(m_FloatArray);
        
    }
    
}