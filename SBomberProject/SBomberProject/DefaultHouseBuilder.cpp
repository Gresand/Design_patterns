#include "DefaultHouseBuilder.h"

void DefaultHouseBuilder::createHouse()
{
    pHouseBlocks = new HouseBlocks;
}
void DefaultHouseBuilder::buildMakeDefaultRoof()
{
    pHouseBlocks->defaultRoof.push_back(MakeDefaultRoof());
}
void DefaultHouseBuilder::buildMakeDefaultWall()
{
    pHouseBlocks->defaultWall.push_back(MakeDefaultWall());
}
void DefaultHouseBuilder::buildMakeDefaultWindow()
{
    pHouseBlocks->defaultWindow.push_back(MakeDefaultWindow());
}