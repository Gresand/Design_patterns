
#include <conio.h>
#include <windows.h>

#include "SBomber.h"
#include "MyTools.h"
#include "Singletone.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================
FileLogger logger("log.txt");

int main(void)
{
    //FileLoggerSingletone::GetInstance().OpenLogFile("log.txt");

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

    //FileLoggerSingletone::GetInstance().CloseLogFile();

    return 0;
}