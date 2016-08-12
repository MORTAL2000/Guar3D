#include "RenderObjectCollection.h"
#include <iostream>
#include <memory>

using namespace guar;
using namespace GFX;

void RenderObjectCollection::createRenderObject(std::string aName, std::weak_ptr<Model> aModel, std::weak_ptr<ShaderProgram> aShaderProgram)
{
    std::cout << " RenderObjectCollection::createRenderObject\n";
    
    m_RenderObjects.push_back(RenderObject(aModel, aShaderProgram));
    
}