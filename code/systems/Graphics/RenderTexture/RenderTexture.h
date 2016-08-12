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
//math inc
#include <Math\Vector2\Vector2.h>
//stdinc
#include <string>
#include <memory>

namespace guar
{
    namespace GFX
    {
        class RenderTexture : public GraphicsObject
        {
            std::string              m_Name         ;
            GFXuint                  m_FBOHandle    ;
            std::shared_ptr<Texture> m_ColorTexture ;
            std::shared_ptr<Texture> m_DepthTexture ;
			Math::Vector2            m_TextureSize  ;

        public:
            std::string            getName               (void) { return  m_Name;                             }
            GFXuint                getFBOHandle          (void) { return  m_FBOHandle;                        }
            std::weak_ptr<Texture> getColorTexture       (void) { return  m_ColorTexture;                     }
            std::weak_ptr<Texture> getDepthTexture       (void) { return  m_DepthTexture;                     }
            GFXuint                getColorTextureHandle (void) { return  m_ColorTexture._Get()->getHandle(); }
            GFXuint                getDepthTextureHandle (void) { return  m_DepthTexture._Get()->getHandle(); }
			Math::Vector2          getTextureSize        (void) { return  m_TextureSize;                      }
    
            RenderTexture();
            RenderTexture(const std::string &aName);
    
        };
        
    }

}

#endif