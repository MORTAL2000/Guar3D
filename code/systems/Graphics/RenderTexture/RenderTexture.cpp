#include "RenderTexture.h"

//GFX inc
#include "../OpenGL/OpenGL.h"
#include "../Texture/Texture.h"
#include "../Graphics.h"
#include "../Texture/CheckeredTextureOfDeath/CheckeredTextureOfDeath.h"
//Debug inc
#include <Debug\Debug.h>

using namespace guar;
using namespace GFX;

RenderTexture::RenderTexture() : 
	RenderTexture("Unnamed RenderTexture") 

{}

RenderTexture::RenderTexture(const std::string &aName)
{
	m_Name = aName;

	//FBO
	{
		// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 depth buffer.
		GLuint FramebufferName = 0;
		glGenFramebuffers(1, &FramebufferName);
		glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

		m_FBOHandle = FramebufferName;
	
	}

	//COLOR TEXTURE
	GLuint textureHandle;
	{
		// The texture we're going to render to
		glGenTextures(1, &textureHandle);

		glBindTexture(GL_TEXTURE_2D, textureHandle);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureHandle, 0);
	
	}

	//DEPTH TEXTURE
	GLuint depthTextureHandle;
	{
		glGenTextures(1, &depthTextureHandle);
		glBindTexture(GL_TEXTURE_2D, depthTextureHandle);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 800, 800, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTextureHandle, 0);

	}

	// Set the list of draw buffers.
	//glDrawBuffer(GL_NONE);//disables color texture
	GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
	glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers

	// Always check that our framebuffer is ok
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		Debug::log("RenderTexture::RenderTexture FRAMEBUFFER IS INCOMPLETE\n");

	m_ColorTexture = Texture( std::string("Color"),GFXuint(textureHandle     ));
	m_DepthTexture = Texture( std::string("Depth"),GFXuint(depthTextureHandle));

}

