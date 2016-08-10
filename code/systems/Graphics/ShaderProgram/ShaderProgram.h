#ifndef GUAR_GRAPHICS_SHADERPROGRAM_H
#define GUAR_GRAPHICS_SHADERPROGRAM_H

/*
 *  ShaderProgram.h
 *  
 *  Abstraction of a "Graphics Program"
 *  Responsible for loading, compiling, linking and retaining handles, etc. for shaders.
 *  
*/

//program includes
#include "../GraphicsTypes.h"
#include "../ShaderDrawCallInterpreter/ShaderDrawCallInterpreter.h"
#include "../GraphicsObject/GraphicsObject.h"

//stdlib includes
#include <string>

namespace guar
{ 
	namespace GFX
	{
		class ShaderProgram : public GraphicsObject
		{
		protected: //data members
			//std::string m_Name;
			GFXuint m_ProgramHandle;

		public: //accessors
			GFXuint getProgramHandle(void) { return m_ProgramHandle; }
			//std::string getName(void){return m_Name;}

		public: //public methods
			void draw(void);

		protected: //private methods
			void compileGraphicsProgram(const std::string &aVertexCode, const std::string &aFragmentCode);
			void processShaderSourceFile(const std::string &aFileName, std::string &ioDrawCode, std::string &ioVertexCode, std::string &ioFragmentCode);

			virtual void glDrawCalls(void) = 0;

		protected: //constructors
			ShaderProgram();

		};

	}

}

#endif