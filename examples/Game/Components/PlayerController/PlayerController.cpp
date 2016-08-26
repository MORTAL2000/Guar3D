#include "PlayerController.h"

//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
#include <EntityComponentSystem\Component\PhysicsBody\PhysicsBody.h>
#include <EntityComponentSystem\Component\Camera\Camera.h>
//PHY inc
#include <Physics\SceneGraph\SceneGraph.h>
#include <Physics\Collision\Collision.h>
//Input inc
#include <Input\Input.h>
//Math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Constants.h>
//Time inc
#include <Time\Time.h>
//std inc
#include <math.h>
//debug inc
#include <Debug\Debug.h>
//game inc
#include "../../Game/Game.h"

using namespace Game;
using namespace guar;

#include <EntityComponentSystem\Component\Renderer\Renderer.h>
#include <EntityComponentSystem\Component\Collider\BoxCollider\BoxCollider.h>
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>
void createCube(const std::weak_ptr<guar::ECS::SceneGraph> &aScene, const guar::Math::Vector3 &aPosition)
{
	float cubeScale = 5.f;
	std::weak_ptr<ECS::GameObject> gameObject = aScene._Get()->createNewGameObject(std::string("Rigidbody test"));
	
	std::weak_ptr<guar::ECS::Renderer> renderer = gameObject._Get()->addComponent<guar::ECS::Renderer>();
	renderer._Get()->setModel("Cube");
	renderer._Get()->setShaderProgram("Opaque");
	renderer._Get()->setTexture("_Texture", "../Textures/Water.png");
	
	std::weak_ptr<guar::ECS::Transform> transform = gameObject._Get()->addComponent<guar::ECS::Transform>();
	transform._Get()->setScale(Math::Vector3(cubeScale, cubeScale, cubeScale));
	transform._Get()->setPosition(aPosition);
	
	std::weak_ptr<guar::ECS::BoxCollider> boxCollider = gameObject._Get()->addComponent<guar::ECS::BoxCollider>();
	boxCollider._Get()->setSize(Math::Vector3(cubeScale, cubeScale, cubeScale));

	//std::weak_ptr<guar::ECS::Camera> camera = gameObject._Get()->addComponent<guar::ECS::Camera>();
	//camera._Get()->setViewportSize(Math::Vector2(20, 20));
	//camera._Get()->setViewportPosition(Math::Vector2(0, 0));
	
	std::weak_ptr<guar::ECS::Rigidbody> rigidbody = gameObject._Get()->addComponent<guar::ECS::Rigidbody>();
	rigidbody._Get()->setMass(1.f);

	//Debug::log("BUILDING FROM PLAYERCONTROLLER: ", gameObject._Get()->getName(), "\n");

}

void PlayerController::init(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();
	m_Camera = getGameObject()->findComponent<guar::ECS::Camera>();

	//m_Rotation = m_Transform._Get()->getRotation().getEuler();

	m_Distance = 1.;
	m_ReloadTimer = 0;

}

void PlayerController::update(void)
{
	//Rotate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getMouseButtonDown(MouseButton::Two) == true)
		{
			Input::lockMouse(true);

			if (Input::getMouseDelta().x > 0)
				delta += Math::Vector3::Up;

			if (Input::getMouseDelta().x < 0)
				delta -= Math::Vector3::Up;

			if (Input::getMouseDelta().y < 0)
				delta += Math::Vector3::Left;

			if (Input::getMouseDelta().y > 0)
				delta += Math::Vector3::Right;

			delta *= Time::getDeltaTime() * 100.0f;
			
		}
		else
		{
			Input::lockMouse(false);
			
			if (Input::getKeyDown(Key::Q))
				delta -= Math::Vector3::Up;

			if (Input::getKeyDown(Key::E))
				delta += Math::Vector3::Up;

			if (Input::getKeyDown(Key::R))
				delta += Math::Vector3::Left;

			if (Input::getKeyDown(Key::F))
				delta += Math::Vector3::Right;

			delta *= Time::getDeltaTime() * 5.0f;
			
		}

		m_Rotation += delta;
		m_Transform._Get()->setRotation(m_Rotation);

	}

	//Translate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::W))
		{
			//delta -= Math::Vector3 //d vec, with -z axis// - (90.0f * Math::PI / 180)
			//(
			//	/*cos(m_Rotation.y - (90.0f * Math::PI / 180))*cos(m_Rotation.x),*/
			//	/*sin(m_Rotation.x),										     */
			//	/*sin(m_Rotation.y - (90.0f * Math::PI / 180))*cos(m_Rotation.x) */
			//
			//
			//);

			delta.x -= sin(m_Rotation.y);
			delta.z += cos(m_Rotation.y);
			
		}

		if (Input::getKeyDown(Key::S))
		{
			//delta += Math::Vector3 //d vec, with -z axis// - (90.0f * Math::PI / 180)
			//(
			//	/*cos(m_Rotation.y - (90.0f * Math::PI / 180))*cos(m_Rotation.x),*/
			//	/*sin(m_Rotation.x),											 */
			//	/*sin(m_Rotation.y - (90.0f * Math::PI / 180))*cos(m_Rotation.x) */
			//
			//);

			delta.x += sin(m_Rotation.y);
			delta.z -= cos(m_Rotation.y);

		}

		if (Input::getKeyDown(Key::A))
		{
			delta.x += sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z -= cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::D))
		{
			delta.x -= sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z += cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::LEFT_CONTROL) || Input::getKeyDown(Key::C))
			delta.y -= 1;

		if (Input::getKeyDown(Key::SPACE))
			delta.y += 1;

		delta *= Time::getDeltaTime() * 60.0f;

		m_Transform._Get()->translate(delta);

	}

	//shoot
	{
		if (Input::getKeyDown(Key::T))
		{
			
			m_Distance += 1.*Time::getDeltaTime();
			//Debug::log(m_Distance,"\n");
		}

		if (Input::getMouseButtonDown(MouseButton::One))
		{
			//Debug::log(Input::getMousePos(), "\n");

			PHY::Collision raycastInfo;
			
			//if (getGameObject()->getSceneGraph()._Get()->getPhysicsScene()._Get()->rayCast(m_Transform._Get()->getPosition(), m_Transform._Get()->getForwardVector(), 1000.f, raycastInfo))
			if (getGameObject()->getSceneGraph()._Get()->getPhysicsScene()._Get()->rayCast(m_Transform._Get()->getPosition(),m_Camera._Get()->getWorldPointFromScreenPoint(Input::getMousePos()), raycastInfo))
			{
				Debug::log(raycastInfo.physicsbody._Get()->getGameObject()->getName(),"\n");
				
			}

		}

		if (Input::getMouseButtonDown(MouseButton::Three))
		{
			if (m_ReloadTimer > 1.)
			{
				createCube(getGameObject()->getSceneGraph(), m_Camera._Get()->getWorldPointFromScreenPoint(Input::getMousePos(), 30.f));
				m_ReloadTimer = 0;
			}

		}

		m_ReloadTimer += Time::getDeltaTime();

	}

}