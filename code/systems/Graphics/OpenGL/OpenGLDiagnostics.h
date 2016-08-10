#ifndef OPENGLDIAGNOSTICS_H
#define OPENGLDIAGNOSTICS_H

/*
 * OpenGLDiagnostics.h
 * Supplies useful debugging fuctions when working directly with the OpenGL API
 * 
*/

//Lib includes
#include "OpenGL.h"

void checkGLErrors(void);
void checkGLSLErrors(const GLuint aShaderHandle);
void clearGLErrors(void);

#endif