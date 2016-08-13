#include "Game.h"

//Engine inc
#include <Engine/Engine.h>
//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\Component\Renderer\Renderer.h>
#include <EntityComponentSystem\Component\Camera\Camera.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
//GFX inc
#include <Graphics\Graphics.h>
#include <Graphics\RenderTexture\RenderTexture.h>
//Game inc
#include "../Components/Rotator/Rotator.h"
#include "../Components/PlayerController/PlayerController.h"
#include "../Components/Spinner/Spinner.h"
#include "../Components/Orbiter/Orbiter.h"

using namespace guar;

void Game::init()
{
	std::weak_ptr<ECS::SceneGraph> mainScene = Engine::createScene("mainScene");
	//ECS::SceneGraph* skyScene  = Engine::createScene("skyScene");
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Ground");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(600.0f, 5.0f, 600.0f));
		transform._Get()->setPosition(Math::Vector3(0, -7.5f, 0));

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/grass.png");

	}
	
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Other Dragon");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");//stanford-dragon
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(70.0f, 10.0f, 0.0f));

	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The cube");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(10.0f, 10.0f, 10.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 20.0f, 0.0f));

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Other Cube");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/Cube");//stanford-dragon
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(10.0f, 10.0f, 10.0f));
		transform._Get()->setPosition(Math::Vector3(90.0f, 10.0f, 0.0f));

	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The bunny");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-bunny.fbx");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/brick.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(0.01f, 0.01f, 0.01f));
		transform._Get()->setPosition(Math::Vector3(-10.0f, 5.0f, 0.0f));

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The torus");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();
		gameObject._Get()->addComponent<Game::Spinner>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/torus.fbx");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/awesome.png");


		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(0.5f, 0.5f, 0.5f));
		transform._Get()->setPosition(Math::Vector3(+15.0f, 5.0f, 0.0f));

	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Light");

		gameObject._Get()->addComponent<guar::ECS::Transform>();
		gameObject._Get()->addComponent<guar::ECS::Light>();
		gameObject._Get()->addComponent<Rotator>();

		
		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 30.0f));
		
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Dragon");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Shadowwall");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(40.0f, 40.0f, 10.0f));
		transform._Get()->setPosition(Math::Vector3(0.0, 15.0f, -30.0f));

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Player");

		gameObject._Get()->addComponent<guar::ECS::Transform>();
		gameObject._Get()->addComponent<guar::ECS::Camera>();
		gameObject._Get()->addComponent<PlayerController>();

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 40.0f));

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Sky");
		
		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();
		
		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(300.0f, 300.0f, 300.0f));
		transform._Get()->setPosition(Math::Vector3(0, 0, 0));
		
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Skybox");
		renderer._Get()->setTexture("_Texture", "../Textures/grass.png");

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Screen");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("RenderTextureDepthDisplay");
		renderer._Get()->setTexture("_Texture", Graphics::getRenderTexture()._Get()->getDepthTexture());

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(80.0f, 80.0f, 80.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 35.0f, -90.0f));
		//transform._Get()->setRotation(Vector3(0.0f, 180.0f, 0.0f));

	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The moving dragon");

		gameObject._Get()->addComponent<guar::ECS::Renderer>();
		gameObject._Get()->addComponent<guar::ECS::Transform>();
		gameObject._Get()->addComponent<Game::Orbiter>();

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->findComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));

	}

	std::cout << Graphics::getRenderTexture()._Get()->getName() << ", " << Graphics::getRenderTexture()._Get()->getColorTexture()._Get()->getName() << ": " << Graphics::getRenderTexture()._Get()->getColorTexture()._Get()->getHandle() << "\n";
	std::cout << Graphics::getTexture()._Get()->getHandle();
	
}