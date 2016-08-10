#include "RenderObjectCollection.h"
#include <iostream>

using namespace guar;
using namespace GFX;

void RenderObjectCollection::createRenderObject(std::string aName, Model* aModel, ShaderProgram* aShaderProgram)
{
    std::cout << " RenderObjectCollection::createRenderObject\n";
    
    m_RenderObjects.push_back(RenderObject(aModel, aShaderProgram));
    
}