#include "LogVisitor.h"

void LogVisitor::log(Bomb* e)
{
    std::string str = "Bomb position: (" +
        std::to_string(e->GetX()) + ',' +
        std::to_string(e->GetY()) + ") , direction: (" +
        std::to_string(e->GetDirection().first) + ',' +
        std::to_string(e->GetDirection().second) + ") , speed: ";
    FileLoggerSingletone::GetInstance().WriteToLog(str, e->GetSpeed());
}
void LogVisitor::log(Plane* e)
{
    std::string str = "Plane position: (" +
        std::to_string(e->GetX()) + ',' +
        std::to_string(e->GetY()) + ") , direction: (" +
        std::to_string(e->GetDirection().first) + ',' +
        std::to_string(e->GetDirection().second) + ") , speed: ";
    FileLoggerSingletone::GetInstance().WriteToLog(str, e->GetSpeed());
}