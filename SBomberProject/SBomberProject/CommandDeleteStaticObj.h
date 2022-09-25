#pragma once

#include "AbstractCommand.h"
#include "SBomber.h"
#include <vector>

class CommandDeleteStaticObj : public AbstractCommand
{
private:

	GameObject* obj;
	std::vector<GameObject*> *vecStationObj;

public:

	CommandDeleteStaticObj(GameObject* pObj, std::vector<GameObject*> &vecStaticObj) : obj(pObj), vecStationObj(&vecStaticObj) {};
	~CommandDeleteStaticObj() override
	{
		vecStationObj = nullptr;
		obj = nullptr;
	}
	void Execute() override;
};

