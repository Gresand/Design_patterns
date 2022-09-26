#include "BombReal.h"

void BombReal::Draw() const
{
	MyTools::SetColor(MyTools::CC_LightMagenta);
	MyTools::GotoXY(x, y);
	std::cout << "*";
}