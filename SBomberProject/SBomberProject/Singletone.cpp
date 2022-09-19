#include "Singletone.h"

#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>


void __fastcall FileLoggerSingletone::OpenLogFile(const std::string& FN) 
{
    logOut.open(FN, std::ios_base::out);
}

void FileLoggerSingletone::CloseLogFile()
{
    if (logOut.is_open())
    {
        logOut.close();
    }
}

void __fastcall  FileLoggerSingletone::WriteToLog(const std::string& str)
{
    if (logOut.is_open())
    {
        logOut  << str << std::endl;
    }
}

void __fastcall  FileLoggerSingletone::WriteToLog(const std::string& str, int n)
{
    if (logOut.is_open())
    {
        logOut  << str << n << std::endl;
    }
}

void __fastcall  FileLoggerSingletone::WriteToLog(const std::string& str, double d)
{
    if (logOut.is_open())
    {
        logOut <<  str << d << std::endl;
    }
}