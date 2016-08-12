#include "RenderTextureCollection.h"
//gfx inc
#include "../../RenderTexture/RenderTexture.h"
//std inc
#include <memory>

using namespace guar;
using namespace GFX;

void RenderTextureCollection::init(void)
{
	//this is a test and should be replaced
	std::shared_ptr<RenderTexture> newRT = std::shared_ptr<RenderTexture>(new RenderTexture());
	m_Vector.push_back(newRT);

}