#ifndef GUAR_GRAPHICS_SHADERDRAWCALLINTERPRETER_H
#define GUAR_GRAPHICS_SHADERDRAWCALLINTERPRETER_H
/*
 * 
 * 
*/
#include <interpreters\LuaInterpreter\LuaInterpreter.h>

//stdlib inc
#include <string>

class ShaderDrawCallInterpreter : public LuaInterpreter
{
protected:
    virtual void init(void);

};

#endif