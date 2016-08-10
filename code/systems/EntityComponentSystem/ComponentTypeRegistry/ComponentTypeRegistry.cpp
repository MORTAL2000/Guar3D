#include "ComponentTypeRegistry.h"

//ECS inc
#include "../Component/Transform/Transform.h"
#include "../Component/Renderer/Renderer.h"
//Debug inc
#include <Debug\Debug.h>

using namespace guar;
using namespace ECS;

void ComponentTypeRegistry::init()
{
	Debug::log("\n\registering components\n\n");

	registerNewComponentType<Transform>("Transform");
	registerNewComponentType<Renderer>("Renderer");
	
}