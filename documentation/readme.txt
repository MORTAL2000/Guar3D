LIBRARIES:
    GLFW, GLEW and ASSIMP need source projects

Project name: codeliteHelloGLFW
Description: Uses GLFW and Glad to create a portable GLES 3.0 context.


Graphics:
    - Texture from disk and from byte array (dynamic, static)
    - Shaders from disk and compiled code (dynamic, static)
    - Models from array (static)
    
    
    
languages:
c
cpp
GLSL
Lua
    
    
libs:

GLFW
GLEW
Lua5.33
jsoncpp
fbxsdk

--
FBXSDK
--
notes:
FBXSDK does not support mingGW, as a result runtime model loading must be disabled if you wish to compile with mingGW.

code is primarly compiled with clang++, developed in codelite in win64x environemnt. This should be considered the most reliable environment for the project.