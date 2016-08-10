#ifndef OPENGLCALLINTERPRETER_H
#define OPENGLCALLINTERPRETER_H
/*
 * 
 * 
*/
#include "../LuaInterpreter/LuaInterpreter.h"

//stdlib inc
#include <string>

class OpenGLCallInterpreter : public LuaInterpreter
{
protected:
    virtual void init(void);
    
};

#endif