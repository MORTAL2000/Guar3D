#include "GraphicsObject.h"

using namespace guar;
using namespace GFX;

GraphicsObject::GraphicsObject(const char* aName) :
	m_Name(aName)
{}

GraphicsObject::GraphicsObject() : GraphicsObject("Unnamed GraphicsObject")
{}