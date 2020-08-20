#include "CollisionManager.h"

bool CollisionManager::IsCollision(Rect& rect1, Rect& rect2)
{
	if (abs(rect1.GetCentreX() - rect2.GetCentreX()) <
		((abs(rect1.GetLength() + rect2.GetLength())) / 2) &&
		abs(rect1.GetCentreY() - rect2.GetCentreY()) <
		(abs(rect1.GetWidth() + rect2.GetWidth()) / 2))
	{
		return true;
	}
	return false;
}

bool CollisionManager::IsCollision(Ring& ring1, Ring& ring2)
{
	int c = sqrt(pow(ring1.GetCentreX() - ring2.GetCentreX(), 2) +
		pow(ring1.GetCentreY() - ring2.GetCentreY(), 2));
	if (c < (ring1.GetOutRadius() + ring2.GetOutRadius()))
	{
		return true;
	}
	return false;
}

