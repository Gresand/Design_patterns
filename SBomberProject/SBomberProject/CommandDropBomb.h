#pragma once

#include "AbstractCommand.h"
#include "SBomber.h"
#include "Singletone.h"
#include <string>
#include <vector>

class CommandDropBomb : public AbstractCommand
{
public:
	CommandDropBomb(Plane* plane, std::vector<DynamicObject*> &vecDynamicObj, uint16_t& bombsNumber, int16_t& score)
		: _plane(plane), _vecDynamicObj(&vecDynamicObj), _bombsNumber(&bombsNumber), _score(&score) {};
	void Execute() override;

private:
	Plane* _plane;
	std::vector<DynamicObject*> *_vecDynamicObj;
	uint16_t* _bombsNumber;
	int16_t* _score;
};

