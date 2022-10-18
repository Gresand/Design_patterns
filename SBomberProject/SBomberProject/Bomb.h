#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	Bomb() {}
	Bomb(const Bomb& other) {
		speed = other.speed;
		speed = other.speed;
		xDirction = other.xDirction;
		yDirection = other.yDirection;
		x = other.x - 1.;
		y = other.y;
	}

	static const uint16_t BombCost = 10; 

	void Draw() const override;

	Bomb* clone()
	{
		return new Bomb(*this);
	}

private:

};

