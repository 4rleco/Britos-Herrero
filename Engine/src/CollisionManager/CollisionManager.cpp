#include "CollisionManager.h"

bool CollisionManager::CollisionCheck(Entity2D entity, Entity2D other)
{
	return (entity.GetX() + entity.GetWidth() >= other.GetX() - other.GetWidth() && 
		entity.GetX() - entity.GetWidth() <= other.GetX() + other.GetWidth() && 
		entity.GetY() + entity.GetHeight() >= other.GetY() - other.GetHeight() &&
		entity.GetY() - entity.GetHeight() <= other.GetY() + other.GetHeight());
}
