#include "RenderTextureCollection.h"
#include "../../RenderTexture/RenderTexture.h"

//#include <iostream>

using namespace guar;
using namespace GFX;

void RenderTextureCollection::init(void)
{
	RenderTexture* newRT = new RenderTexture();

	m_Vector.push_back(newRT);

	//std::cout << "***********************************************" << m_Vector[0]->getColorTexture()->getName();

}