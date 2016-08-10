#ifndef GUAR_GRAPHICS_RENDEROBSERVER_H
#define GUAR_GRAPHICS_RENDEROBSERVER_H
/*
 * RenderObserver.h
 *
 * Graphics object that renders a scene. Base class for Cameras, Lights.
 *
*/
#include <Math/Vector3/Vector3.h>

#include <glm/fwd.hpp>//"../includes/glm/fwd.hpp"

namespace guar
{
    namespace GFX
    {
        class RenderTexture;
    
        class RenderObserver
        {
        protected:
            RenderObserver();
            
        protected:
            Math::Vector3        m_Position             ;
            Math::Vector3        m_Rotation             ;
            float          m_NearClippingDistance ;
            float          m_FarClippingDistance  ;
            float          m_FieldOfView          ;
            RenderTexture* m_RenderTexture        ;
    
        public:
            Math::Vector3        getPosition             (void);
            Math::Vector3        getRotation             (void);
            float          getNearClippingDistance (void);
            float          getFarClippingDistance  (void);
            float          getFieldOfView          (void);
            RenderTexture* getRenderTexture(void) { return m_RenderTexture; }
            
            void setPosition             (const Math::Vector3  &aPosition            );
            void setRotation             (const Math::Vector3  &aRotation            );
            void setNearClippingDistance (const float    &aNearClippingDistance);
            void setFarClippingDistance  (const float    &aFarClippingDistance );
            void setFieldOfView          (const float    &aFieldOfView         );
            void setRenderTexture(RenderTexture* aRenderTexture) { m_RenderTexture = aRenderTexture; }
    
            virtual void generateViewProjectionMatrix(glm::mat4x4* aViewMatrix, glm::mat4x4* aProjectionMatrix, glm::mat4x4* aVPMatrix) = 0;
    
            virtual void draw(void);
    
        };
        
    }

}

#endif