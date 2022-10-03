
#include <iostream>

#include "House.h"
#include "MyTools.h"

#include "Director.h"
#include "HouseBlocks.h"
#include "HouseBuilder.h"
#include "ModernHouseBuilder.h"
#include "DefaultHouseBuilder.h"
#include "Singletone.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	Director dir;

	// DefaultHouseBuilder dh_buider;
	ModernHouseBuilder mh_buider;
	// HouseBlocks *dh = dir.createHouse(dh_buider);
	HouseBlocks* mh = dir.createHouse(mh_buider);

	MyTools::SetColor(CC_Yellow);
	MyTools::GotoXY(x, y - 5);
	cout << "  ########  ";
	cout << mh->getHouse()->at(0);
	MyTools::GotoXY(x, y - 4);
	cout << "##        ##";
	cout << mh->getHouse()->at(1);
	MyTools::GotoXY(x, y - 3);
	cout << "############";
	cout << mh->getHouse()->at(2);
	MyTools::GotoXY(x, y - 2);
	cout << "#          #";
	cout << mh->getHouse()->at(3);
	MyTools::GotoXY(x, y - 1);
	cout << "#          #";
	cout << mh->getHouse()->at(4);
	MyTools::GotoXY(x, y);
	cout << "############";
	cout << mh->getHouse()->at(5);
}