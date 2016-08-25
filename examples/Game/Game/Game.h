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

}

#endif