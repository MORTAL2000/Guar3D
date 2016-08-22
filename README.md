# Guar3D
Game engine using C++11, OpenGL.
![alt tag](https://dl.dropboxusercontent.com/u/102655232/Github/Guar3D/Build_8_21_2016.png "Build August 21, 2016")
example game: [Win32 build](https://dl.dropboxusercontent.com/u/102655232/Github/Guar3D/build%20august_21_2016.7z) 


### Features:
* Entity Component system
* 3D Renderer
* 3D Physics simulation

### Usage:
 * Build dependent projects as static libraries (root/_VSC2015/dependencies/ for Visual Studio 2015).
 * Build Guar3D as a dynamic library (root/_VSC2015/systems/ for Visual Studio 2015)
 * include and link your game project against Guar3D.
 * your main.cpp should look like this:
```c++
int main(void)
{
	Engine::mainInit();

	//TODO: your init code here
	initExampleScene();

	Engine::mainLoop();

    return 0;
    
}
```
### Creating an example scene:
```c++
void initExampleScene()
{
	std::weak_ptr<ECS::SceneGraph> mainScene = Engine::createScene("mainScene");
    
    //Create the ground
    {
    	std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Ground");

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/grass.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(600.0f, 5.0f, 600.0f));
		transform._Get()->setPosition(Math::Vector3(0, -7.5f, 0));
        
    }
    
    //Create the player
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Player");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 40.0f));

		gameObject._Get()->addComponent<guar::ECS::Camera>(); //engine supplied component
		gameObject._Get()->addComponent<PlayerController>(); //custom component

	}	

}
```

### Creating a custom component
```c++
#ifndef GAME_COMPONENT_PLAYERCONTROLLER_H
#define GAME_COMPONENT_PLAYERCONTROLLER_H

//ecs inc
#include <EntityComponentSystem\Component\Component.h>
//math inc
#include <Math\Vector3\Vector3.h>
//std inc
#include <memory>

namespace guar { namespace ECS  { class  Transform; } }

namespace Game
{
	class PlayerController : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;
		guar::Math::Vector3 m_Rotation;

		void init  (void) override;
		void update(void) override;

	};

}

#endif
```

### Threading diagram
![alt tag](https://dl.dropboxusercontent.com/u/102655232/Github/Guar3D/Threading%20diagram%208_21_2016.png "Threading diagram, August 21, 2016")
The engine uses two main threads, a dedicated graphics thread and a main thread, for everything else. Both threads make use of thread pools to accomplish certain tasks such as loading resources from file, etc.

### Libraries used
OpenGL context & extension management
* [GLEW](http://glew.sourceforge.net/)
* [GLFW](http://www.glfw.org/)

Math
* [GLM](http://glm.g-truc.net/0.9.7/index.html)

Physics
* [Bullet](http://bulletphysics.org/wordpress/)

File io
* [zlib](http://www.zlib.net/)
* [assimp](http://www.assimp.org/)
* [lodePNG](http://lodev.org/lodepng/)
* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)

Scripting
* [Lua](https://www.lua.org/)

Portability headers
* [dirent](https://github.com/tronkko/dirent)
* [rlutil](https://github.com/tapio/rlutil)

library licenses can be found in root/licenses/%LibraryName% LICENSE.txt