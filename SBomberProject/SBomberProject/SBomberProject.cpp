
#include <conio.h>
#include <windows.h>

#include "SBomber.h"
#include "MyTools.h"
#include "Singletone.h"
#include "Proxy.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    LoggerSingletone::GetInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();
        Sleep(30);

        game.TimeFinish();

    } while (!game.GetExitFlag());

    LoggerSingletone::GetInstance().CloseLogFile();

    return 0;
}