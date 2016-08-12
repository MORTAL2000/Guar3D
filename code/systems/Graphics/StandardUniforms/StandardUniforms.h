#ifndef GUAR_GRAPHICS_STANDARDUNIFORMS_H
#define GUAR_GRAPHICS_STANDARDUNIFORMS_H
/*
* Standard Uniforms
*
*/

//gfxinc
#include "../GraphicsTypes.h"
//mathinc
#include <Math/Vector3/Vector3.h>

//stdinc
#include <map>
#include <vector>
#include <memory>

namespace guar
{
    namespace GFX
    {
        class Texture;
        class RenderCamera;
        class RenderObject;
        class RenderObserver;
        class RenderLight;
    
        namespace StandardUniforms
        {
            extern const char* CameraPosition   ;
    
            extern const char* Time               ;
            extern const char* Texture            ;
            extern const char* MVP                ;
            extern const char* ModelMatrix        ;
			extern const char* ModelRotationMatrix;
            extern const char* ModelViewMatrix    ;
            extern const char* ViewMatrix         ;
            extern const char* ProjectionMatrix   ;
    
            extern const char* Normal2WorldMatrix;
            extern const char* Normal2EyeSpaceMatrix;
    
            //Etc.
    
            //void loadStandardUniforms(RenderObject &aRenderObject, RenderObserver* aCamera, std::vector<RenderLight> &aLights, std::map<std::string, guar::GFX::Texture*> &aTextureUniforms);
			void loadStandardUniforms(RenderObject &aRenderObject, RenderObserver* aCamera, std::vector<RenderLight> &aLights, std::map<std::string, std::weak_ptr<GFX::Texture>> aTextureUniforms);

        }

	}

}


#endif