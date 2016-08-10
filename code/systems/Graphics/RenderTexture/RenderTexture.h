#ifndef GRAPHICS_RENDERTEXTURE_H
#define GRAPHICS_RENDERTEXTURE_H
/* 
 * RenderTexture.h
 * 
 * 
*/
//gfxinc
#include "../GraphicsTypes.h"
#include "../GraphicsObject/GraphicsObject.h"
#include "../Texture/Texture.h"
//stdinc
#include <string>

namespace guar
{
    namespace GFX
    {
        class RenderTexture : public GraphicsObject
        {
            std::string m_Name;
            GFXuint     m_FBOHandle;
            Texture     m_ColorTexture;
            Texture     m_DepthTexture;
    
        public:
            std::string getName              (void) { return  m_Name;                     }
            GFXuint     getFBOHandle         (void) { return  m_FBOHandle;                }
            Texture*    getColorTexture      (void) { return &m_ColorTexture;             }
            Texture*    getDepthTexture      (void) { return &m_DepthTexture;             }
            GFXuint     getColorTextureHandle(void) { return  m_ColorTexture.getHandle(); }
            GFXuint     getDepthTextureHandle(void) { return  m_DepthTexture.getHandle(); }
    
            RenderTexture();
            RenderTexture(const std::string &aName);
    
        };
        
    }

}

#endif