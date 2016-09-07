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
const int Vertex::BitangentAttributeOffset = offsetof(Vertex::Format, bX)/sizeof(GFXfloat);

const int Vertex::Bone1AttributeOffset = offsetof(Vertex::Format, bone1I) / sizeof(GFXfloat);
const int Vertex::Bone2AttributeOffset = offsetof(Vertex::Format, bone2I) / sizeof(GFXfloat);
const int Vertex::Bone3AttributeOffset = offsetof(Vertex::Format, bone3I) / sizeof(GFXfloat);
const int Vertex::Bone4AttributeOffset = offsetof(Vertex::Format, bone4I) / sizeof(GFXfloat);
const int Vertex::Bone5AttributeOffset = offsetof(Vertex::Format, bone5I) / sizeof(GFXfloat);


const int Vertex::PositionAttributeSize  = 3;
const int Vertex::UVAttributeSize        = 2;
const int Vertex::NormalAttributeSize    = 3;
const int Vertex::TangentAttributeSize   = 3;
const int Vertex::BitangentAttributeSize = 3;

const int Vertex::Bone1AttributeSize = 2;
const int Vertex::Bone2AttributeSize = 2;
const int Vertex::Bone3AttributeSize = 2;
const int Vertex::Bone4AttributeSize = 2;
const int Vertex::Bone5AttributeSize = 2;



Vertex::Format Vertex::create
(
	GFXfloat aX      , GFXfloat aY      , GFXfloat aZ  ,
	GFXfloat aU      , GFXfloat aV      ,			   
	GFXfloat aNX     , GFXfloat aNY     , GFXfloat aNZ ,
	GFXfloat aTX     , GFXfloat aTY     , GFXfloat aTZ ,
	GFXfloat aBX     , GFXfloat aBY     , GFXfloat aBZ ,
	GFXfloat aBone1I , GFXfloat aBone1W ,
	GFXfloat aBone2I , GFXfloat aBone2W ,
	GFXfloat aBone3I , GFXfloat aBone3W ,
	GFXfloat aBone4I , GFXfloat aBone4W ,
	GFXfloat aBone5I , GFXfloat aBone5W 

)
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
    
	//Bone1
	vertex.bone1I = aBone1I; 
	vertex.bone1W = aBone1W;
	
	//Bone2
	vertex.bone2I = aBone2I; 
	vertex.bone2W = aBone2W;
	
	//Bone3
	vertex.bone3I = aBone3I; 
	vertex.bone3W = aBone3W;
	
	//Bone4
	vertex.bone4I = aBone4I; 
	vertex.bone4W = aBone4W;
	
	//Bone5
	vertex.bone5I = aBone5I; 
	vertex.bone5W = aBone5W;
	
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
    
    enableAttribute("a_Position"   , aProgramHandle, Vertex::PositionAttributeSize , Vertex::PositionAttributeOffset );
    enableAttribute("a_UV"         , aProgramHandle, Vertex::UVAttributeSize       , Vertex::UVAttributeOffset       );
    enableAttribute("a_Normal"     , aProgramHandle, Vertex::NormalAttributeSize   , Vertex::NormalAttributeOffset   );
	enableAttribute("a_Tangent"    , aProgramHandle, Vertex::TangentAttributeSize  , Vertex::TangentAttributeOffset  );
	enableAttribute("a_Bitangent"  , aProgramHandle, Vertex::BitangentAttributeSize, Vertex::BitangentAttributeOffset);

	enableAttribute("a_BoneWeight1", aProgramHandle, Vertex::Bone1AttributeSize    , Vertex::Bone1AttributeOffset    );
	enableAttribute("a_BoneWeight2", aProgramHandle, Vertex::Bone2AttributeSize    , Vertex::Bone2AttributeOffset    );
	enableAttribute("a_BoneWeight3", aProgramHandle, Vertex::Bone3AttributeSize    , Vertex::Bone3AttributeOffset    );
	enableAttribute("a_BoneWeight4", aProgramHandle, Vertex::Bone4AttributeSize    , Vertex::Bone4AttributeOffset    );
	enableAttribute("a_BoneWeight5", aProgramHandle, Vertex::Bone5AttributeSize    , Vertex::Bone5AttributeOffset    );

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

		//Bone1
		*m_FloatArray++ = m_VertexData[i].bone1I;
		*m_FloatArray++ = m_VertexData[i].bone1W;
		
		//Bone2
		*m_FloatArray++ = m_VertexData[i].bone2I;
		*m_FloatArray++ = m_VertexData[i].bone2W;

		//Bone3
		*m_FloatArray++ = m_VertexData[i].bone3I;
		*m_FloatArray++ = m_VertexData[i].bone3W;

		//Bone4
		*m_FloatArray++ = m_VertexData[i].bone4I;
		*m_FloatArray++ = m_VertexData[i].bone4W;

		//Bone5
		*m_FloatArray++ = m_VertexData[i].bone5I;
		*m_FloatArray++ = m_VertexData[i].bone5W;
        
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
        //Debug::log("Vertex::Data::~Data()\n");
        free(m_FloatArray);
        
    }
    
}