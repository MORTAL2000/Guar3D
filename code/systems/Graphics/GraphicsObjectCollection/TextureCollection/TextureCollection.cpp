#include "TextureCollection.h"
//#include <iostream>

#include "../../Texture/CheckeredTextureOfDeath/CheckeredTextureOfDeath.h"

using namespace guar;
using namespace GFX;

TextureCollection::TextureCollection()
{
	m_FileTypes.push_back(".png");

}

void TextureCollection::init()
{
    m_Vector.push_back(new staticTextures::CheckeredTextureOfDeath());
    
}