#ifndef GUAR_GRAPHICS_RENDEROBJECT_H
#define GUAR_GRAPHICS_RENDEROBJECT_H
/*
 * RenderObject.h
 * 
 * RenderObject is the only data type able to be instantiated by
 * external systems.
 *
 * Texture, Model and ShaderProgram instances are owned exclusively by
 * their respective collection types.
 * 
*/
//TODO: add a system of weak_ptr: return weakptrs to pos etc, zero in ~()

//projinc
#include <Math/Vector3/Vector3.h>

//stdinc
#include <string>
#include <map>
#include <vector>
#include <memory>

namespace guar
{
    namespace GFX
    {
        class Model;
        class ShaderProgram;
        class Texture;
        class RenderTexture;
        class RenderCamera;
        class RenderObserver;
        class RenderLight;
    
        class RenderObject final
        {
        private: //data members
            Model* m_Model;
            ShaderProgram* m_ShaderProgram;
            //ShaderProgram* m_DeferredGeoShaderProgram;
            //?MYSTERYTYPE?* m_DeferredWhatToDoWithTheGeoData; //??
    
            //Modelmat properties
            Math::Vector3 m_Position;
            Math::Vector3 m_Rotation;
            Math::Vector3 m_Scale;
    
            //Uniform properties
            std::map<std::string, std::weak_ptr<Texture>> m_TextureUniforms;
    
        public: //interface
            void draw(RenderObserver& aCamera, std::vector<RenderLight> &aLights);
    
            Model*         getModel         (void) { return m_Model;    }
            ShaderProgram* getShaderProgram (void);
            Math::Vector3  getPosition      (void) { return m_Position; }
            Math::Vector3  getRotation      (void) { return m_Rotation; }
            Math::Vector3  getScale         (void) { return m_Scale;    }
    
            void setModel         (Model*              aModel         ) { m_Model         = aModel;         }
            void setShaderProgram (ShaderProgram*      aShaderProgram ) { m_ShaderProgram = aShaderProgram; }
            void setPosition      (const Math::Vector3 &aPos          ) { m_Position      = aPos;           }
            void setRotation      (const Math::Vector3 &aRotation     ) { m_Rotation      = aRotation;      }
            void setScale         (const Math::Vector3 &aScale        ) { m_Scale         = aScale;         }
            
            //Uniform get/set
            void setTexture(const std::string &aUniformName, const std::string &aTextureName);
            void setTexture(const std::string &aUniformName, Texture* aTexture);
    
    
            Texture* getTexture(const std::string &aUniformName);
    
            //ctr
            RenderObject(Model* aModel, ShaderProgram* aShaderProgram);
            RenderObject();
            RenderObject(const RenderObject& aRenderObject);
            
        };
        
    }

}

#endif