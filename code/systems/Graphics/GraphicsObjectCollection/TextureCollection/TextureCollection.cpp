#include "TextureCollection.h"
//gfx inc
#include "../../Texture/CheckeredTextureOfDeath/CheckeredTextureOfDeath.h"
//std inc
#include <memory>

using namespace guar;
using namespace GFX;

TextureCollection::TextureCollection()
{
	m_FileTypes.push_back(".png");

}

void TextureCollection::init()
{
    m_Vector.push_back(std::shared_ptr<Texture>(new staticTextures::CheckeredTextureOfDeath()));
    
}