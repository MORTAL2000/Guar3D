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
    
    //load texture
    {
        std::string filename = aTextureFileName;

		{
		    unsigned char* pngbuffer;
		    unsigned int   width, height;

		    if (lodepng_decode32_file( &pngbuffer, &width, &height, filename.c_str()) != 0)
		    {
				//std::assert(0);
				
		    }

			//FLIP THE DATA: required because opengl uv space's v is upside down...
			{
				//calculate meta data, prep output buffer
				unsigned int numberOfChannels = 4;//4 channels (rgba)
				size_t numberOfBytesInTexture = width  * height * numberOfChannels;
				size_t numberOfBytesPerRow    = width  * numberOfChannels;
				unsigned char* flippedPNG = (unsigned char*)malloc(sizeof(unsigned char)*numberOfBytesInTexture);
				
				//write the data flipped vertically to the new buffer
				unsigned char* inputPTR = pngbuffer;
				unsigned char* outputPTR = flippedPNG;

				for (size_t i = 0; i < numberOfBytesInTexture - numberOfBytesPerRow; i++)
					*inputPTR++;
				
				for (size_t y = 0; y < height; y++) //for each column..
				{
					for (size_t x = 0; x < numberOfBytesPerRow; x++) //copy the row data to the new buffer
						*outputPTR++ = *inputPTR++;

					for (size_t x = 0; x < numberOfBytesPerRow * 2; x++) //rewind the pointer 2 rows
						*inputPTR--;

				}

				//destroy the old buffer, point to the new
				free(pngbuffer);
				pngbuffer = flippedPNG;
			
			}
			
			//push texture data to video memory
		    GLuint texturehandle;
		    
		    glGenTextures( 1, &texturehandle );
		    glActiveTexture( GL_TEXTURE0 );
		    glBindTexture( GL_TEXTURE_2D, texturehandle );
		    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pngbuffer );
		    
		    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeatmode);
		    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeatmode);
		    
		    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magfilter );
		    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		    
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
