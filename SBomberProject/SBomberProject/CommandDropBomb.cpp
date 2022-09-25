#include "CommandDropBomb.h"

void CommandDropBomb::Execute()
{
    if (*_bombsNumber > 0)
    {
        FileLoggerSingletone::GetInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");
        
        double x = this->_plane->GetX() + 4;
        double y = this->_plane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        this->_vecDynamicObj->push_back(pBomb);
        this->_bombsNumber--;
        this->_score -= Bomb::BombCost;
    }
}