#include "OpenGLCallInterpreter/OpenGLCallInterpreter.h"

extern "C"
{
#include "./includes/Lua/lua.h"
#include "./includes/Lua/lauxlib.h"
}

#include<stdlib.h>

static int glClear (lua_State *L) ;
static int glClearColor (lua_State *L);
static int setString (lua_State *L);

void OpenGLCallInterpreter::init(void)
{    
    lua_pushcfunction(m_Lua, glClear);
    lua_setglobal(m_Lua, "glClear");
    
    lua_pushcfunction(m_Lua, glClearColor);
    lua_setglobal(m_Lua, "glClearColor");
    
    lua_pushcfunction(m_Lua, setString);
    lua_setglobal(m_Lua, "setString");
    
}

static int glClear (lua_State *L) 
{
      printf("Lua called glClear()\n");
      
      return 0; //number of args
    
}

static int glClearColor (lua_State *L) //must always be of this sig
{
    float r  = lua_tonumber(L, 1);
    float g = lua_tonumber(L, 2);
    float b = lua_tonumber(L, 3);
    float a = lua_tonumber(L, 4);
    
    printf("Lua called glClearColor(%f,%f,%f,%f)\n",r,g,b,a);
    
    return 4; //number of args
    
}

static int setString (lua_State *L)
{
    std::string somestring = lua_tostring(L,1);
    
    printf("Lua called setString(\"%s\")\n",somestring.c_str());
    
    return 1;
    
}
