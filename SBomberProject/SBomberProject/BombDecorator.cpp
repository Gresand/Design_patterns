#include "BombDecorator.h"

void BombDecorator::Draw() const
{
	MyTools::SetColor(MyTools::CC_LightBlue);
	MyTools::GotoXY(x, y);
	std::cout << "#";
}