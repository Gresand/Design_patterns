#include "HouseBlocks.h"

std::vector<std::string>* HouseBlocks::getHouse()
{
	for (auto iter : defaultRoof)
	{
		for (auto i = 0; i < iter.MakeRoof().size(); i++)
		{
			house.at(i) = iter.MakeRoof().at(i);
		}
	}
	for (auto iter : modernRoof)
	{
		for (auto i = 0; i < iter.MakeRoof().size(); i++)
		{
			house.at(i) = iter.MakeRoof().at(i);
		}
	}
	for (auto iter : defaultWall)
	{
		for (auto i = 0; i < iter.MakeWall().size(); i++)
		{
			house.at(2 + i) = iter.MakeWall().at(i);
		}
	}
	for (auto iter : defaultWindow)
	{
		for (auto i = 0; i < iter.MakeWindow().size(); i++)
		{
			house[3 + i] = iter.MakeWindow().at(i);
		}
	}
	for (auto iter : smallWindow)
	{
		for (auto i = 0; i < iter.MakeWindow().size(); i++)
		{
			house[3 + i] = iter.MakeWindow().at(i);
		}
	}
	return &house;
}