#include "OpenGLDiagnostics.h"

//stdlib includes
#include <stdio.h>
#include <stdlib.h>

void checkGLErrors(void)
{
    GLenum errorCode = glGetError();

    if (errorCode == 0)
    {       
        printf("GLErrors: No errors\n");
        return;
        
    }
    else
        for(;;)
            if (errorCode == 0)
                return;
            else
            {
                printf("GLErrors: WARNING error %d\n",errorCode);
                errorCode = glGetError();
            
            }
            
}

void checkGLSLErrors(const GLuint aShaderHandle)
{
    GLint length;
	glGetShaderiv(aShaderHandle,GL_INFO_LOG_LENGTH,&length);
	GLchar* log = (GLchar*)malloc(length);
    
	glGetShaderInfoLog(aShaderHandle,200,&length,log);
    
	printf("Log file: ");
	if(length>1)
		printf("%s\n",log);
    
}

void clearGLErrors(void)
{
    printf("Clearing GL error stack\n");
    
    while(glGetError()!=0);
    
}