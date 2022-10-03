#pragma once

#include "HouseBuilder.h"
#include "HouseBlocks.h"

class Director
{
public:

    HouseBlocks* createHouse(HouseBuilder& builder)
    {
        builder.createHouse();
        builder.buildMakeDefaultRoof();
        builder.buildMakeModernRoof();
        builder.buildMakeDefaultWall();
        builder.buildMakeDefaultWindow();
        builder.buildMakeSmallWindow();
        return builder.getBuitHouse();
    }
};