#pragma once

#include "HouseBuilder.h"
class ModernHouseBuilder : public HouseBuilder
{
	void createHouse() override;
	void buildMakeModernRoof() override;
	void buildMakeDefaultWall() override;
	void buildMakeSmallWindow() override;
	HouseBlocks* getBuitHouse() override
	{
		return pHouseBlocks;
	}
};

