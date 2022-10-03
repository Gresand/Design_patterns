#pragma once

#include "HouseBlocks.h"

class HouseBuilder
{
protected:
	HouseBlocks* pHouseBlocks;

public:
	HouseBuilder() : pHouseBlocks(nullptr) {}
	virtual ~HouseBuilder() {}
	virtual void createHouse() {}
	virtual void buildMakeDefaultRoof() {}
	virtual void buildMakeModernRoof() {}
	virtual void buildMakeDefaultWall() {}
	virtual void buildMakeDefaultWindow() {}
	virtual void buildMakeSmallWindow() {}
	virtual HouseBlocks* getBuitHouse()
	{
		return pHouseBlocks;
	}
};