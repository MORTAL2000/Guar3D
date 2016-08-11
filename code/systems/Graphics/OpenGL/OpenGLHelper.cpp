#include "OpenGLHelper.h"

//gfx inc
#include "../Graphics.h"
#//debug inc
#include <Debug\Debug.h>
//stdlib includes
#include <stdio.h>
#include <stdlib.h>

using namespace GLHelp;
using namespace guar;

//
// Diagnostic functions
//

void Diagnostics::checkGLErrors(void)
{
	GLenum errorCode = glGetError();

	if (errorCode == 0)
	{
		Debug::success("GLErrors: No errors\n");
		return;

	}
	else
		for (;;)
			if (errorCode == 0)
				return;
			else
			{
				Debug::error("GLErrors: WARNING error: ", errorCode,"\n");
				errorCode = glGetError();

			}

}

void Diagnostics::checkGLSLErrors(const GLuint aShaderHandle)
{
	GLint length;
	glGetShaderiv(aShaderHandle, GL_INFO_LOG_LENGTH, &length);
	GLchar* log = (GLchar*)malloc(length);

	glGetShaderInfoLog(aShaderHandle, 200, &length, log);

	printf("Log file: ");
	if (length>1)
		printf("%s\n", log);

}

void Diagnostics::clearGLErrors(void)
{
	printf("Clearing GL error stack\n");

	while (glGetError() != 0);

}

//
// Uniform functions
//

void Uniforms::load1Foat(const GLuint &aShaderHandle, const char* &aUniformName, const float &aValue)
{
	GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName);

	if (uniformHandle != -1)
		glUniform1f(uniformHandle, aValue);

}

void Uniforms::loadVector3f(const GLuint &aShaderHandle, const char* &aUniformName, float* &aValue)
{
	GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName);

	if (uniformHandle != -1)
		glUniform3fv(uniformHandle, 1, aValue);

}

void Uniforms::loadTexture(const GLuint &aShaderHandle, const char* aUniformName, const GLuint &aTextureHandle, const GLuint &aTextureUnit, const GLenum &aTextureType)
{
	GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName);

	if (uniformHandle == -1)
		return;

	switch (aTextureUnit)
	{
		case 0:
		glActiveTexture(GL_TEXTURE0);
		break;

		case 1:
		glActiveTexture(GL_TEXTURE1);
		break;

		case 2:
		glActiveTexture(GL_TEXTURE2);
		break;

		case 3:
		glActiveTexture(GL_TEXTURE3);
		break;

		default:
		glActiveTexture(GL_TEXTURE0);
		break;

	}
	
	
	
	
	glBindTexture(aTextureType, aTextureHandle);
	glUniform1i(uniformHandle, aTextureUnit);

}

void Uniforms::loadMatrix4x4(const GLuint &aShaderHandle, const char* &aUniformName, const float* aMatrix4x4)
{
	GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName);

	if (uniformHandle != -1)
		glUniformMatrix4fv(uniformHandle, 1, GL_FALSE, aMatrix4x4);

}

void loadMatrix3x3(const GLuint &aShaderHandle, const char* &aUniformName, const float* aMatrix3x3)
{
	GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName);

	if (uniformHandle != -1)
		glUniformMatrix3fv(uniformHandle, 1, GL_FALSE, aMatrix3x3);

}