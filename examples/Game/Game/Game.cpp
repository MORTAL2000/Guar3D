#include "Game.h"

//Engine inc
#include <Engine/Engine.h>
//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\Component\Renderer\Renderer.h>
#include <EntityComponentSystem\Component\Camera\Camera.h>
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
#include <EntityComponentSystem\Component\Collider\BoxCollider\BoxCollider.h>
//GFX inc
#include <Graphics\Graphics.h>
#include <Graphics\RenderTexture\RenderTexture.h>
//PHY inc
#include <Physics\SceneGraph\SceneGraph.h>
//Game inc
#include "../Components/Rotator/Rotator.h"
#include "../Components/PlayerController/PlayerController.h"
#include "../Components/Spinner/Spinner.h"
#include "../Components/Orbiter/Orbiter.h"
#include "../Components/SkyPlayer/SkyPlayer.h"
#include "../Components/Chaser/Chaser.h"

using namespace guar;

void Game::init()
{
	initSkyScene();
	initMainScene();

}

void Game::initSkyScene()
{
	std::weak_ptr<ECS::SceneGraph> skyScene = Engine::createScene("skyScene");
	{
		std::weak_ptr<ECS::GameObject> gameObject = skyScene._Get()->createNewGameObject("The Sky");

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
		std::weak_ptr<ECS::GameObject> gameObject = skyScene._Get()->createNewGameObject("The SKY Player");

		gameObject._Get()->addComponent<guar::ECS::Transform>();
		gameObject._Get()->addComponent<guar::ECS::Camera>();
		gameObject._Get()->addComponent<SkyPlayer>();

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->findComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 40.0f));

	}


}

void Game::initMainScene()
{
	std::weak_ptr<ECS::SceneGraph> mainScene = Engine::createScene("mainScene");
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Ground");

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/grass.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(600.0f, 5.0f, 600.0f));
		transform._Get()->setPosition(Math::Vector3(0, -7.5f, 0));

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(600.0f, 5.0f, 600.0f));

		std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
		rigidbody._Get()->setMass(0.f);
		
	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Other Dragon");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");//stanford-dragon
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(70.0f, 10.0f, 0.0f));

	}

	float cubeScale = 5.f;
	for (int i = 0; i < 10; i++)
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject(std::string("Rigidbody test #") + std::to_string(i));

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(cubeScale, cubeScale, cubeScale));
		transform._Get()->setPosition(Math::Vector3(+3.25f + (i*0.015f), 110.0f + (i*5.f), 1.0f));

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(cubeScale, cubeScale, cubeScale));
		
		std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
		rigidbody._Get()->setMass(1.f);

		
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Other Cube");

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/Cube");//stanford-dragon
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(cubeScale, cubeScale, cubeScale));
		transform._Get()->setPosition(Math::Vector3(0.0f, 90.0f, 0.0f));
				
	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The bunny");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-bunny.fbx");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/brick.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(0.01f, 0.01f, 0.01f));
		transform._Get()->setPosition(Math::Vector3(-10.0f, 5.0f, 0.0f));
	
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The torus");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/torus.fbx");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/awesome.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(0.5f, 0.5f, 0.5f));
		transform._Get()->setPosition(Math::Vector3(+15.0f, 5.0f, 0.0f));

		gameObject._Get()->addComponent<Game::Spinner>();
	
	}

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Light");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 30.0f));
		transform._Get()->setRotation(Math::Vector3::Right*20.f);

		gameObject._Get()->addComponent<guar::ECS::Light>();		
		gameObject._Get()->addComponent<Rotator>();

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Dragon");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
	
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Shadowwall");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(40.0f, 40.0f, 10.0f));
		transform._Get()->setPosition(Math::Vector3(0.0, 15.0f, -30.0f));

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(40.0f, 40.0f, 10.0f));

		std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
		rigidbody._Get()->setMass(0.f);
	
	}
	

	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Screen");

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("RenderTextureDepthDisplay");
		renderer._Get()->setTexture("_Texture", Graphics::getRenderTexture()._Get()->getDepthTexture());

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(80.0f, 80.0f, 80.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 35.0f, -90.0f));

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(80.0f, 80.0f, 80.0f));

		std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
		rigidbody._Get()->setMass(0.f);
		
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("Rigidbody test ABOVE THESCREEN");

		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(cubeScale, cubeScale, cubeScale));
		transform._Get()->setPosition(Math::Vector3(0.0f, 100.0f, -49.0f));

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(cubeScale, cubeScale, cubeScale));

		std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
		rigidbody._Get()->setMass(1.f);


	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The moving dragon");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("../Models/stanford-dragon.fbx");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "../Textures/Water.png");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));

		gameObject._Get()->addComponent<Game::Orbiter>();
	
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Player");

		//std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		//renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		//renderer._Get()->setShaderProgram("Opaque");
		//renderer._Get()->setTexture("_Texture", "");

		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 40.0f));
		transform._Get()->setRotation(Math::Vector3(0.f, 180.f, 0.f));
		transform._Get()->setScale(Math::Vector3(2., 2., 2.));

		std::weak_ptr<guar::ECS::Camera> camera = gameObject._Get()->addComponent<guar::ECS::Camera>();
		//camera._Get()->setViewportSize(Math::Vector2(20, 20));
		//camera._Get()->setViewportPosition(Math::Vector2(20, 20));

		gameObject._Get()->addComponent<PlayerController>();

	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("Chaser");
	
		std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
		renderer._Get()->setModel("Cube");// "../Models/stanford-dragon.fbx"
		renderer._Get()->setShaderProgram("Opaque");
		renderer._Get()->setTexture("_Texture", "");
	
		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setPosition(Math::Vector3(0., +10., +15.));
		transform._Get()->setScale(Math::Vector3(1., 1., 1.));
	
		gameObject._Get()->addComponent<Chaser>();

		std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
		boxCollider._Get()->setSize(Math::Vector3(1., 1., 1.));
	
	}
	{
		std::weak_ptr<ECS::GameObject> gameObject = mainScene._Get()->createNewGameObject("The Observer");
	
		std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
		transform._Get()->setScale(Math::Vector3(1.0f, 1.0f, 1.0f));
		transform._Get()->setPosition(Math::Vector3(0.0f, 5.0f, 70.0f));
		transform._Get()->setRotation(Math::Vector3(0.f, 180.f, 0.f));
	
		std::weak_ptr<guar::ECS::Camera> camera = gameObject._Get()->addComponent<guar::ECS::Camera>();
		camera._Get()->setViewportSize(Math::Vector2(20, 20));
		camera._Get()->setViewportPosition(Math::Vector2(0, 80));
		camera._Get()->setClearColor(guar::GFX::Color(0.5f, 0.5f, 0.5f, 0.5f));
		camera._Get()->setClearMode(true, guar::GFX::ClearMode::DepthBuffer /*| guar::GFX::ClearMode::ColorBuffer*/);

	}
		
}