#include "ModernHouseBuilder.h"

void ModernHouseBuilder::createHouse()
{
    pHouseBlocks = new HouseBlocks;
}
void ModernHouseBuilder::buildMakeModernRoof()
{
    pHouseBlocks->modernRoof.push_back(MakeModernRoof());
}
void ModernHouseBuilder::buildMakeDefaultWall()
{
    pHouseBlocks->defaultWall.push_back(MakeDefaultWall());
}
void ModernHouseBuilder::buildMakeSmallWindow()
{
    pHouseBlocks->smallWindow.push_back(MakeSmallWindow());
}