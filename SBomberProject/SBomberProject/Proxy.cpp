#include "Proxy.h"

#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

void __fastcall LoggerSingletone::OpenLogFile(const std::string& FN)
{

    singletone->GetInstance().OpenLogFile(FN);
}

void LoggerSingletone::CloseLogFile()
{
    singletone->GetInstance().CloseLogFile();
}

void __fastcall  LoggerSingletone::WriteToLog(const std::string& str)
{
    logStr = std::to_string(++LoggerSingletone::numberOfLine) + "\t" + str;
    singletone->GetInstance().WriteToLog(logStr);
}

void __fastcall  LoggerSingletone::WriteToLog(const std::string& str, int n)
{
    logStr = std::to_string(++LoggerSingletone::numberOfLine) + "\t" + str;
    singletone->GetInstance().WriteToLog(logStr, n);
}

void __fastcall  LoggerSingletone::WriteToLog(const std::string& str, double d)
{
    logStr = std::to_string(++LoggerSingletone::numberOfLine) + "\t" + str;
    singletone->GetInstance().WriteToLog(logStr, d);
}