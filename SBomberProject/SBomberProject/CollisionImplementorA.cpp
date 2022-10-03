#include "CollisionImplementorA.h"

void CollisionImplementorA::CheckPlaneAndLevelGUI(double x, uint16_t finalx, bool& exitFlag)
{
    if (x > finalx)
    {
        exitFlag = true;
    }
}

void CollisionImplementorA::CheckBombsAndGround(std::vector<Bomb*>& vecBombs, std::vector<DynamicObject*>& vecDynamicObj, int16_t& score, Ground* pGround, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj)
{
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // ����������� ����� � ������
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(score, vecBombs[i], vecDestoyableObjects, vecStaticObj);
            DeleteDynamicObj(vecBombs[i], vecDynamicObj);
        }
    }

}

void __fastcall CollisionImplementorA::CheckDestoyableObjects(int16_t& score, Bomb* pBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, std::vector<GameObject*>& vecStaticObj)
{
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            DeleteStaticObj(vecDestoyableObjects[i], vecStaticObj);
        }
    }
}

void __fastcall CollisionImplementorA::DeleteDynamicObj(DynamicObject* pBomb, std::vector<DynamicObject*>& vecDynamicObj)
{
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++)
    {
        if (*it == pBomb)
        {
            vecDynamicObj.erase(it);
            break;
        }
    }
}
void __fastcall CollisionImplementorA::DeleteStaticObj(GameObject* pObj, std::vector<GameObject*>& vecStaticObj)
{
    auto it = vecStaticObj.begin();
    for (; it != vecStaticObj.end(); it++)
    {
        if (*it == pObj)
        {
            vecStaticObj.erase(it);
            break;
        }
    }
}