//project inc
#include "OpenGLCallInterpreter/OpenGLCallInterpreter.h"

//stdlib inc
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <stdexcept>

int main()
{
    OpenGLCallInterpreter openGLCallInterpreter;
    
    std::ifstream t("../scripts/script.lua");
    std::stringstream buffer;
    buffer << t.rdbuf();
    
    try
    {
        openGLCallInterpreter.loadLuaSourceFromFile("../scripts/script.lua");
        
    }
    catch (const std::runtime_error &e)
    {
         std::cout << e.what();
         return 0;
        
    }
    
    try
    {
        for (int i = 0; i < 200; i++)
            openGLCallInterpreter.call();
        
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what();
        return 0;
    }

    return 1;

}
