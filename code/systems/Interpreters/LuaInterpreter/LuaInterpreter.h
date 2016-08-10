#ifndef GUAR_INTERPRETERS_LUAINTERPRETER_H
#define GUAR_INTERPRETERS_LUAINTERPRETER_H

/*
 * LuaInterpreter
 * wrapper for a lua state
 * derivation rules: put lua state init code in luaStateInit
 * 
*/

//stdlib includes
#include<string>

//class string;
struct lua_State;

class LuaInterpreter
{    
private:
    std::string m_SourceString;
    
protected:
    lua_State *m_Lua;
    virtual void init(void) = 0;
    
public:
    LuaInterpreter();    
    virtual ~LuaInterpreter();
    
    void loadLuaSourceFromString(const std::string &aSourceString);
    //void loadLuaSourceFromFile(const std::string &aSourceString);
    void call(const int &aNumberOfArgs = 0, const int &aNumberOfResults = 0);

};

#endif