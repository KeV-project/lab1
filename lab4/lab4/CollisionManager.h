#pragma once
#include <math.h> 
#include "Rect.h"
#include "Ring.h"

static class CollisionManager
{
public:
	static bool IsCollision(Rect& rect1, Rect& rect2);
	static bool IsCollision(Ring& ring1, Ring& ring2);
};


