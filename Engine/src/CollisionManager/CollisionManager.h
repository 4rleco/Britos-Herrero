#pragma once

#include "Entity/Entity2D.h"
#include "EngineAPI.h"

class CollisionManager
{
public:
	ENGINE_API bool CollisionCheck(Entity2D* entity, Entity2D* other);
};