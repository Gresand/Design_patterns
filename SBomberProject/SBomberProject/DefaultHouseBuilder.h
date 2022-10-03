#pragma once

#include "HouseBuilder.h"

class DefaultHouseBuilder : public HouseBuilder
{
	void createHouse() override;
	void buildMakeDefaultRoof() override;
	void buildMakeDefaultWall() override;
	void buildMakeDefaultWindow() override;
	HouseBlocks* getBuitHouse() override
	{
		return pHouseBlocks;
	}
};

