#pragma once

#include <vector>
#include "DestroyableGroundObject.h"
#include "Bomb.h"
#include "Ground.h"
#include "MyTools.h"

class CollisionImplementor
{
public:
    CollisionImplementor() {}
    virtual ~CollisionImplementor() {}
    virtual void CheckPlaneAndLevelGUI(double x, uint16_t finalx, bool& exitFlag) = 0;
    virtual void CheckBombsAndGround(std::vector<Bomb*>& vecBombs, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score, Ground* pGround, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj) = 0;
    virtual void __fastcall CheckDestoyableObjects(int16_t& score, Bomb* pBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj) = 0;
    virtual void __fastcall DeleteDynamicObj(DynamicObject* pBomb, std::vector<DynamicObject*>& vecDynamicObj) = 0;
    virtual void __fastcall DeleteStaticObj(GameObject* pObj, std::vector<GameObject*>& vecStaticObj) = 0;
};