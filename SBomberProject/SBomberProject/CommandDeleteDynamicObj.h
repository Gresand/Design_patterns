#pragma once

#include "AbstractCommand.h"
#include "SBomber.h"
#include <vector>

class CommandDeleteDynamicObj : public AbstractCommand
{
private:

	DynamicObject* obj;
	std::vector<DynamicObject*> *vecDynamicObj;

public:
	CommandDeleteDynamicObj(DynamicObject* pObj, std::vector<DynamicObject*> &vecStaticObj) : obj(pObj), vecDynamicObj(vecDynamicObj) {};
	void Execute() override;
};

