#include "CommandDeleteDynamicObj.h"

void CommandDeleteDynamicObj::Execute()
{
    auto it = this->vecDynamicObj->begin();
    for (; it != this->vecDynamicObj->end(); it++)
    {
        if (*it == this->obj)
        {
            this->vecDynamicObj->erase(it);
            break;
        }
    }
}