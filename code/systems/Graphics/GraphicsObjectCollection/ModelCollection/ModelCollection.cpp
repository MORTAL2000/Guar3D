#include "ModelCollection.h"
//gfx inc
#include "../../Model/Quad/Quad.h"
#include "../../Model/Cube/Cube.h"
//std inc
#include <memory>

using namespace guar;
using namespace GFX;

void ModelCollection::init(void)
{
	m_Vector.push_back(std::shared_ptr<Model>(new Cube()));
	m_Vector.push_back(std::shared_ptr<Model>(new Quad()));
	
}

ModelCollection::ModelCollection()
{
	m_FileTypes.push_back(".fbx");

}