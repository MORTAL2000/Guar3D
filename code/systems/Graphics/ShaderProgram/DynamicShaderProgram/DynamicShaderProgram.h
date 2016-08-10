#ifndef GUAR_GRAPHICS_DYNAMICSHADERPROGRAM_H
#define GUAR_GRAPHICS_DYNAMICSHADERPROGRAM_H

#include "../ShaderProgram.h"

#include <string>

namespace guar
{
    namespace GFX
    {
        class DynamicShaderProgram : public ShaderProgram
        {
        private:
            ShaderDrawCallInterpreter* m_ShaderDrawCallCallInterpreter;
            void parseDrawCode(const std::string &aDrawCode);
            
        protected:
            virtual void glDrawCalls(void) override;
        
        public:
            DynamicShaderProgram(const std::string &aFileName);
            
        public://ctors
            DynamicShaderProgram(const DynamicShaderProgram& b);
            
        };
    
    }
    
}

#endif