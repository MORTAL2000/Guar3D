#ifndef GUAR_GRAPHICS_GRAPHICSOBJECTCOLLECTION_H
#define GUAR_GRAPHICS_GRAPHICSOBJECTCOLLECTION_H
/*
 *
 *
*/
//projinc
#include "../GraphicsObject/GraphicsObject.h"

//stdinc
#include <vector>
#include <string>

namespace guar
{
    namespace GFX
    {
        template<class BaseType, class DynamicType = BaseType> class GraphicsObjectCollection
        {
            static_assert(std::is_base_of<GraphicsObject, BaseType>::value == true, "BaseType must derive from GraphicsObject");
            //static_assert(std::is_base_of<BaseType, DynamicType>::value == true, "DynamicType must derive from BaseType");
    
        protected:
            //data members
            std::vector<BaseType*> m_Vector;
            std::vector<std::string> m_FileTypes;
            
        public:
            virtual void init(void) = 0;
    
            BaseType* getDefault(void)
            {
                if (m_Vector.size() == 0)
                    throw(std::runtime_error("GraphicsCollection needs at least one object in its vector"));
    
                return m_Vector[0]; 
            
            }
    
            BaseType* find(const std::string &aItemName)
            {
                for (int i = 0; i < m_Vector.size(); i++)
                    if (((GraphicsObject*)m_Vector[i])->getName() == aItemName)
                        return m_Vector[i];
    
                return getDefault();
    
            }
    
            BaseType* operator[](const int &i)
            {
                if (i >= m_Vector.size())
                    return getDefault();
    
                return m_Vector[i];
    
            }
    
            bool listOfAllDynamicTypeFilesInDir(const char *dirname, std::vector<std::string>& ioListOfShaderFiles)
            {
                DIR *dir = opendir(dirname);
    
                if (dir == NULL)
                {
                    printf("Could not open directory %s (Does it exist?)\n", dirname);
                    return false;
    
                }
    
                struct dirent *ent;
    
                while ((ent = readdir(dir)) != NULL)
                    if (fileNameHasFileType(ent->d_name))
                        ioListOfShaderFiles.push_back(ent->d_name);
    
                closedir(dir);
                return true;
    
            }
    
            bool fileNameHasFileType(char *string)
            {
                if (m_FileTypes.size() != 0)
                {
                    string = strrchr(string, '.');
    
                    if (string != NULL)
                        for (int i = 0; i < m_FileTypes.size(); i++)
                            if (strcmp(string, m_FileTypes[i].c_str()) == 0)//if (strcmp(string, ".shader") == 0)
                                return 1;
                
                }
                
                return 0;
    
            }
    
            void loadDirectory(std::string aDirectoryName)
            {
                if (*aDirectoryName.rbegin() != '/') //adds '/' to end of dirname if none exist
                    aDirectoryName += "/";
    
                //printf("ShaderProgramCollection loading dir \"%s\"\n",aDirectoryName.c_str());
    
                std::vector<std::string> fileNames;
    
                if (listOfAllDynamicTypeFilesInDir(aDirectoryName.c_str(), fileNames))
                {
                    for (unsigned int i = 0; i < fileNames.size(); i++)
                    {
                        std::string fullFileName = aDirectoryName + fileNames[i];
    
                        try
                        {
                            m_Vector.push_back(new DynamicType(fullFileName.c_str()));
    
                        }
                        catch (const std::runtime_error &e)
                        {
                            std::cout << e.what();
    
                        }
    
                    }
    
                    //std::cout << "number of shaders in list is: " << m_Vector.size() << "\n";
                    //std::cout << "Loaded shaders are:\n";
    
                    for (int i = 0; i < m_Vector.size(); i++)
                        std::cout << m_Vector[i]->getName() << "\n";
    
                }
    
            }
            
        };
        
    }

}

#endif