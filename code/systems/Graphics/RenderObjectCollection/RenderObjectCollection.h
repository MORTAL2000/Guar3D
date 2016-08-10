#ifndef RENDEROBJECTCOLLECTION_H
#define RENDEROBJECTCOLLECTION_H

#include <vector>
#include "../RenderObject/RenderObject.h"
#include "../Model/Model.h"
#include "../ShaderProgram/ShaderProgram.h"

namespace guar
{
	namespace GFX
	{
		class RenderObjectCollection
		{
		private:
			std::vector<RenderObject> m_RenderObjects;

		public: //
			void createRenderObject(std::string aName, Model* aModel, ShaderProgram* aShaderProgram);
			//RenderObject* getTestObject(void){return &m_RenderObjects[0];}
			RenderObject getTestObject(void) { return m_RenderObjects[0]; }

		};

	}

}

#endif