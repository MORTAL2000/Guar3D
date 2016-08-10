#include "ModelCollection.h"

#include "../../Model/Quad/Quad.h"
#include "../../Model/Cube/Cube.h"

//#include <iostream>

using namespace guar;
using namespace GFX;

void ModelCollection::init(void)
{
	m_Vector.push_back(new Cube());
	m_Vector.push_back(new Quad());
	//m_Vector.push_back(new Model("../Models/stanford-dragon.fbx"));
	
}

ModelCollection::ModelCollection()
{
	m_FileTypes.push_back(".fbx");

}