#include "ShaderDrawCallInterpreter.h"

#include "../OpenGL/OpenGL.h"

#include <debug\Debug.h>

extern "C"
{
#include <Lua533/src/lua.h>
#include <Lua533/src/lauxlib.h>
#include <Lua533/src/lstate.h>
}

#include<stdlib.h>

static int glClear (lua_State *L) ;
static int glClearColor (lua_State *L);
static int setString (lua_State *L);
static int getIncrementer (lua_State *L);

void ShaderDrawCallInterpreter::init(void)
{    
    lua_pushcfunction(m_Lua, glClear);
    lua_setglobal(m_Lua, "glClear");
    
    lua_pushcfunction(m_Lua, glClearColor);
    lua_setglobal(m_Lua, "glClearColor");
    
    lua_pushcfunction(m_Lua, setString);
    lua_setglobal(m_Lua, "setString");
    
    lua_pushcfunction(m_Lua, getIncrementer);
    lua_setglobal(m_Lua, "getIncrementer");
    
}

static int glClear (lua_State *L) 
{
   GLbitfield mask = 0;
   
   if (lua_tonumber(L, 1))
       mask |= GL_COLOR_BUFFER_BIT;
    
    if (lua_tonumber(L, 2))
       mask |= GL_DEPTH_BUFFER_BIT;
    
    if (lua_tonumber(L, 3))
       mask |= GL_ACCUM_BUFFER_BIT;
    
    if (lua_tonumber(L, 4))
       mask |= GL_STENCIL_BUFFER_BIT;
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   return 4; //number of args
    
}

static int glClearColor (lua_State *L) //must always be of this sig
{
    float r  = lua_tonumber(L, 1);
    float g = lua_tonumber(L, 2);
    float b = lua_tonumber(L, 3);
    float a = lua_tonumber(L, 4);
    
    glClearColor(r,g,b,a);
    
    return 4; //number of args
    
}
//#include<iostream>
static int setString (lua_State *L)
{
    std::string somestring = lua_tostring(L,1);
    
    guar::Debug::log("Lua says: ", somestring, "\n");
    
    return 1;
    
}

static int test = 0;
static int getIncrementer (lua_State *L)
{
    lua_pushnumber(L,test++);
    
    return 1;
    
}