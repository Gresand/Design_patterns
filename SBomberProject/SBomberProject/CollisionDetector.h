#pragma once

#include "CollisionImplementor.h"
#include "CollisionImplementorA.h"

class CollisionDetector
{
private:
    CollisionImplementor* cImpl;

public:
    CollisionDetector() {}
    ~CollisionDetector() {}
    void CheckCollisions(double x, uint16_t finalx, bool& exitFlag, std::vector<Bomb*>&& vecBombs, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score, Ground* pGround, std::vector<DestroyableGroundObject*>&& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj)
    {
        cImpl = new CollisionImplementorA;
        cImpl->CheckPlaneAndLevelGUI(x, finalx, exitFlag);
        cImpl->CheckBombsAndGround(vecBombs, vecDynamicObj, score, pGround, vecDestoyableObjects, vecStaticObj);
    }

};