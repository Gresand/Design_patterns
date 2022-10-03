#pragma once

#include "CollisionImplementor.h"

class CollisionImplementorA : public CollisionImplementor
{
public:
    CollisionImplementorA() {}
    ~CollisionImplementorA() {}
    void CheckPlaneAndLevelGUI(double x, uint16_t finalx, bool& exitFlag) override;
    void CheckBombsAndGround(std::vector<Bomb*>& vecBombs, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score, Ground* pGround, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj) override;
    void __fastcall CheckDestoyableObjects(int16_t& score, Bomb* pBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj) override;
    void __fastcall DeleteDynamicObj(DynamicObject* pBomb, std::vector<DynamicObject*>& vecDynamicObj) override;
    void __fastcall DeleteStaticObj(GameObject* pObj, std::vector<GameObject*>& vecStaticObj) override;
};