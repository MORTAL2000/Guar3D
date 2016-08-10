#include "LuaInterpreter.h"

extern "C"
{
#include <Lua533/src/lua.h>
#include <Lua533/src/lauxlib.h>
}

//stdlib inc
#include <stdexcept>
#include <iostream>

//
// ctors
//
LuaInterpreter::LuaInterpreter()
{
    m_Lua = 0;
    
}

//
// dtors
//
LuaInterpreter::~LuaInterpreter()
{
    if (m_Lua != 0)
        lua_close(m_Lua);
    
}

void LuaInterpreter::loadLuaSourceFromString(const std::string &aSourceString)
{
    //std::cout << "LuaInterpreter::loadLuaSourceFromString " << aSourceString << "\n";
    m_SourceString = aSourceString;
    
    if (!m_Lua)
    {
        m_Lua = luaL_newstate();
        init();
    
    }
    
    if (luaL_loadstring(m_Lua, aSourceString.c_str())) //if (luaL_loadstring(m_Lua,"Test\0")) //
        throw(std::runtime_error("LuaInterpreter error in anonymous lua script:\n" + aSourceString + "\n error: " + lua_tostring(m_Lua, -1)));
    
    lua_setglobal(m_Lua,"_ACTIVE_FUNCTION_");
    
    
}

//void LuaInterpreter::loadLuaSourceFromFile(const std::string &aSourceString)
//{        
//    if (!m_Lua)
//    {
//        m_Lua = luaL_newstate();
//        init();
//   
//    }
//    
//    if (luaL_loadfile(m_Lua, aSourceString.c_str()))
//        throw(std::runtime_error("Couldn't load file: " + aSourceString + "\nReason: " + lua_tostring(m_Lua, -1)));
//    
//    lua_setglobal(m_Lua,"_ACTIVE_FUNCTION_");
//    
//    
//    
//}
    
#include <iostream>
void LuaInterpreter::call(const int &aNumberOfArgs, const int &aNumberOfResults)
{       
    if (!m_Lua)
        loadLuaSourceFromString(m_SourceString);
    
    lua_getglobal(m_Lua,"_ACTIVE_FUNCTION_");
    
    if (lua_pcall(m_Lua, aNumberOfArgs, LUA_MULTRET, aNumberOfResults)) 
         throw(std::runtime_error("Lua runtime error: " + std::string(lua_tostring(m_Lua, -1))));
    
     ///////////old
    //std::cout <<  "LuaInterpreter::call" << ": " << m_Lua << "\n";
    //
    //if (m_Lua == 0)
    //    throw(std::runtime_error("Error: tried to interpret a script with a null lua state\n"));
    //
    //lua_getglobal(m_Lua,"_ACTIVE_FUNCTION_");
    //
    //if (lua_pcall(m_Lua, aNumberOfArgs, LUA_MULTRET, aNumberOfResults)) 
    //     throw(std::runtime_error("Lua runtime error: " + std::string(lua_tostring(m_Lua, -1))));
    
}