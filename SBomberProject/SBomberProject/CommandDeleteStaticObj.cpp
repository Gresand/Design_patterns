#include "CommandDeleteStaticObj.h"

void CommandDeleteStaticObj::Execute()
{
    auto it = this->vecStationObj->begin();
    for (; it != this->vecStationObj->end(); it++)
    {
        if (*it == this->obj)
        {
            this->vecStationObj->erase(it);
            break;
        }
    }
}
