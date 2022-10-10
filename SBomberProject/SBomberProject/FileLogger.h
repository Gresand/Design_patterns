#pragma once

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

class FileLogger
{
private:
    std::ofstream logOut;
public:
    FileLogger(const std::string& FN)
    {
        logOut.open(FN, std::ios_base::out);
    }
    ~FileLogger()
    {
        if (logOut.is_open())
        {
            logOut.close();
        }
    }

    std::string GetCurDateTime();

    void __fastcall WriteToLog(const std::string& str);

    void __fastcall WriteToLog(const std::string& str, int n);

    void __fastcall WriteToLog(const std::string& str, double d);
};
