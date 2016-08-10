#ifndef GUAR_GRAPHICS_TEXTURE_H
#define GUAR_GRAPHICS_TEXTURE_H
/*
 * 
 * 
*/
#include "../GraphicsTypes.h"

#include "../GraphicsObject/GraphicsObject.h"

#include <string>

namespace guar
{
    namespace GFX
    {
        class Texture : public GraphicsObject
        {
        protected:
            //std::string m_Name;
            GFXuint m_TextureHandle;
        
        public:
            Texture(const char* aTextureFileName, GFXint repeatmode = 0, GFXuint magfilter = 0);
            Texture(const unsigned char aByteArray[], const unsigned int &aByteArrayLength, GFXuint repeatmode = 0, GFXuint magfilter = 0);
            
            GFXuint getHandle(void){ return m_TextureHandle;}
    
            Texture(std::string &aName, const GFXuint &aTextureHandle);
            Texture();
    
            //Texture &Texture :: operator= (Texture);
    
        };

    }
        
}

#endif