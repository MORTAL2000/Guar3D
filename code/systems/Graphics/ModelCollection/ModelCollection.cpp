#include "ModelCollection.h"

#include "../Model/Quad/Quad.h"
#include "../Model/Cube/Cube.h"

#include <iostream>

using namespace guar;
using namespace GFX;

void ModelCollection::loadDirectory(std::string aDirectoryName)
{
    std::cout << "ModelCollection::loadDirectory(std::string aDirectoryName)\n";
    
    //actually do work HERE
    m_Models.push_back(Model("../Models/torus.fbx"));
    
}

void ModelCollection::loadDefaultStaticModels(void)
{
    m_Models.push_back(Cube());
    m_Models.push_back(Quad());
    
}