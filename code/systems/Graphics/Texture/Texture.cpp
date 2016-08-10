#include "Texture.h"

#include <LodePNG/lodepng.h>
//#include <iostream>
#include <cstring>
#include "../OpenGL/OpenGL.h"
#include <stdlib.h>
#include <fstream>
#include <debug\Debug.h>

using namespace guar;
using namespace GFX;

Texture::Texture(const char* aTextureFileName, GFXint repeatmode, GFXuint magfilter) : GraphicsObject(aTextureFileName)
{
	m_TextureHandle = 0;

    Debug::log("Texture::Texture(const std::string &aTextureFileName, GFXuint repeatmode, GFXuint magfilter)\n");
    Debug::log(m_Name, "\n");
    
    
    //LODETESTPLESAEWORK(10);
    
    
    //load texture
    {
        std::string filename = aTextureFileName;
    #ifdef _DEBUG    
    //printf("Loading %s...\n",filename);
    
    #endif
    {
        unsigned char* pngbuffer;
        unsigned int   width, height;
        
        //lodepng_decode32(&pngbuffer, &width, &height, brick_png, sizeof(brick_png));
        if (lodepng_decode32_file( &pngbuffer, &width, &height, filename.c_str()) != 0)
        {
            #ifdef _DEBUG
                //printf("Failed to load %s\n",filename);

            #endif
			
        }
        
        //pngbuffer = awesome_png;
        
        GLuint texturehandle;
        
        glGenTextures( 1, &texturehandle );
        glActiveTexture( GL_TEXTURE0 );
        glBindTexture( GL_TEXTURE_2D, texturehandle );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pngbuffer );
        
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeatmode );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeatmode );
        
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magfilter );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //eyyy pixels
        
        //add_Texture(filename,texturehandle);
        m_Name = filename;
        m_TextureHandle = texturehandle;

        free( pngbuffer );

    }
    
    }
    
}

Texture::Texture() :
	m_TextureHandle(0)

{}

Texture::Texture(const unsigned char aByteArray[], const unsigned int &aByteArrayLength, GFXuint repeatmode, GFXuint magfilter)
{
        //std::cout << "Texture::Texture(const std::string &aTextureFileName, GFXuint repeatmode, GFXuint magfilter)\n";
   // std::cout << m_Name << "\n";
    std::string aTextureFileName = "test";
    
    //LODETESTPLESAEWORK(10);
    //unsigned char brick_png[]
    
    //load texture
    {
        std::string filename = aTextureFileName;
    #ifdef _DEBUG    
    //printf("Loading %s...\n",filename);
    
    #endif
    {
        unsigned char* pngbuffer;
        unsigned int   width, height;
        
        lodepng_decode32(&pngbuffer, &width, &height, aByteArray, aByteArrayLength);
        //if (lodepng_decode32_file( &pngbuffer, &width, &height, filename.c_str()) != 0)
        {
            #ifdef _DEBUG
                //printf("Failed to load %s\n",filename);

            #endif

        }
        
        //pngbuffer = awesome_png;
        
        GLuint texturehandle;
        
        glGenTextures( 1, &texturehandle );
        glActiveTexture( GL_TEXTURE0 );
        glBindTexture( GL_TEXTURE_2D, texturehandle );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pngbuffer );
        
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeatmode );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeatmode );
        
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magfilter );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        
        //add_Texture(filename,texturehandle);
        m_Name = filename;
        m_TextureHandle = texturehandle;

        free( pngbuffer );

    }
    
    }
    
    
}

Texture::Texture(std::string &aName, const GFXuint &aTextureHandle) : GraphicsObject(aName.c_str())
{
	m_TextureHandle = aTextureHandle;

}
