#ifndef MODELCOLLECTION_H
#define MODELCOLLECTION_H

/*
 * ModelCollection
 * 
*/

#include "../Model/Model.h"

#include <vector>
#include <string>

namespace guar
{
	namespace GFX
	{
		class ModelCollection //: public std::vector<Model>
		{
		private: //data members
			std::vector<Model> m_Models;

		public:
			void loadDirectory(std::string aDirectoryName);
			void loadDefaultStaticModels(void);

			//remove
			Model* getTestModel(void) { return &m_Models[0]; }

		};

	}

}

#endif