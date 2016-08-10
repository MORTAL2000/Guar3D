#include "TextureCollection.h"
#include <iostream>

#include "../Texture/CheckeredTextureOfDeath/CheckeredTextureOfDeath.h"

using namespace guar;
using namespace GFX;

void TextureCollection::loadDirectory(std::string aDirectoryName)
{
    std::cout << "TextureCollection::loadDirectory(std::string aDirectoryName)\n";
    m_TextureVector.push_back(Texture("../Textures/awesome.png"));
    
}

void TextureCollection::loadDefaultTextures()
{
    m_TextureVector.push_back(staticTextures::CheckeredTextureOfDeath());
    
}