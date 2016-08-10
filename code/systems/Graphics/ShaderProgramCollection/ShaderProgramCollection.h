#ifndef SHADERPROGRAMCOLLECTION_H
#define SHADERPROGRAMCOLLECTION_H

/*
 * ShaderProgramCollection.h
 * 
 * 
 */

//graphics includes
#include "../ShaderProgram/ShaderProgram.h"


//stdlib includes
#include <vector>
#include <string>

namespace guar
{ 
	namespace GFX
	{
		class ShaderProgramCollection// : public std::vector<ShaderProgram>
		{
		private: //data members
			std::vector<ShaderProgram*> m_Shaders;

		private: //private methods
			void removeShaderAt(const unsigned int &aPos);

		public:
			void loadDirectory(std::string aDirectoryName);

			void loadDefaultShaderPrograms();

			template<class T>
			void loadStaticShader();

			//remove
			ShaderProgram* getTestShader(void) { return m_Shaders[0]; }

		};

	}

}

#endif