#pragma once
#include "DynamicObject.h"
#include "Bomb.h"
#include "MyTools.h"
#include "BombReal.h"
#include <iostream>

class BombDecorator : public Bomb
{
public:

	BombDecorator() 
	{
		_bomb = new BombReal;
		_bomb->SetSpeed(10);
	};

	~BombDecorator()
	{
		delete _bomb;
	}

	void Draw() const override;

private:
	Bomb* _bomb;
};