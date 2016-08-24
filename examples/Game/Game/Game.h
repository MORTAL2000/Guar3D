#ifndef GAME_GAME_H
#define GAME_GAME_H
/*
 * Game.h
 *
*/
#include <memory>

namespace guar { namespace Math { class Vector3;    } }
namespace guar { namespace ECS  { class SceneGraph; } }

namespace Game
{
	void init();

	void initMainScene();
	void initSkyScene();

	//void createCube(const std::weak_ptr<guar::ECS::SceneGraph> &aScene, const guar::Math::Vector3 &aPosition);

}

#endif