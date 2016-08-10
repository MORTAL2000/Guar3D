#include "ShaderProgramCollection.h"

#include "../ShaderProgram/DynamicShaderProgram/DynamicShaderProgram.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdexcept>
#include<iostream>
#include "../ShaderProgram/StaticShaderProgram/StaticShaderProgram.h"
#include "../ShaderProgram/StaticShaderProgram/PinkShaderOfDeath/PinkShaderOfDeath.h"
#include "../ShaderProgram/StaticShaderProgram/AlphaCutOff/AlphaCutOff.h"


using namespace guar;
using namespace GFX;

static bool listOfAllShaderFilesInDir(const char *dirname,  std::vector<std::string>& ioListOfShaderFiles);
bool fileNameHasShaderType( char *string );

template<class T>
void ShaderProgramCollection::loadStaticShader()
{
    StaticShaderProgram *object = new T();
    
   //std::cout << object.
    
    m_Shaders.push_back(object);
    
}

void ShaderProgramCollection::loadDefaultShaderPrograms(void)
{
    loadStaticShader<staticShaders::AlphaCutOff>();
    loadStaticShader<staticShaders::PinkShaderOfDeath>();
    
    
}

void ShaderProgramCollection::loadDirectory(std::string aDirectoryName)
{    
    if (*aDirectoryName.rbegin() != '/') //adds '/' to end of dirname if none exist
        aDirectoryName += "/";
    
    printf("ShaderProgramCollection loading dir \"%s\"\n",aDirectoryName.c_str());
    
    std::vector<std::string> shaderFileNames;
    
    if (listOfAllShaderFilesInDir(aDirectoryName.c_str(),shaderFileNames))
    {
        for(unsigned int i = 0; i < shaderFileNames.size();i++)
        {
            std::string fullFileName = aDirectoryName + shaderFileNames[i];
            
            try
            {
                m_Shaders.push_back(new DynamicShaderProgram(fullFileName));
            
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what();
                
            }
            
        }
        
        std::cout << "number of shaders in list is: " << m_Shaders.size() << "\n";
        std::cout << "Loaded shaders are:\n";
        
        for(int i = 0; i < m_Shaders.size();i++)
            std::cout << m_Shaders[i]->getName() << "\n";
        
    }

    
}

void ShaderProgramCollection::removeShaderAt(const unsigned int &aPos)
{
//    delete m_Shaders[&aPos].m_ShaderDrawCallCallInterpreter;
    m_Shaders.erase(m_Shaders.begin() + aPos);
    
}

static bool listOfAllShaderFilesInDir(const char *dirname,  std::vector<std::string>& ioListOfShaderFiles)
{
    DIR *dir = opendir (dirname);
    
    if (dir == NULL)
    {
        printf ("Could not open directory %s (Does it exist?)\n", dirname);
        return false;
        
    }
    
    struct dirent *ent;
        
        while ((ent = readdir (dir)) != NULL) 
            if (fileNameHasShaderType(ent->d_name))
                ioListOfShaderFiles.push_back(ent->d_name);

        closedir (dir);
        return true;
    
}

bool fileNameHasShaderType( char *string )
{
    string = strrchr(string, '.');
    
    if( string != NULL )
        if(strcmp(string, ".shader") == 0 )
            return 1;
    
    return 0;
  
}