#include "ProxyTime.h"

std::string ProxyTime::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

void __fastcall ProxyTime::OpenLogFile(const std::string& FN)
{
    proxy->GetInstance().OpenLogFile(FN);
}
void ProxyTime::CloseLogFile()
{
    proxy->GetInstance().CloseLogFile();
}
void __fastcall ProxyTime::WriteToLog(const std::string& str)
{
    logStr = ProxyTime::GetInstance().GetCurDateTime() + " - " + str;
    proxy->GetInstance().WriteToLog(logStr);
}
void __fastcall ProxyTime::WriteToLog(const std::string& str, int n)
{
    logStr = ProxyTime::GetInstance().GetCurDateTime() + " - " + str;
    proxy->GetInstance().WriteToLog(logStr, n);
}
void __fastcall ProxyTime::WriteToLog(const std::string& str, double d)
{
    logStr = ProxyTime::GetInstance().GetCurDateTime() + " - " + str;
    proxy->GetInstance().WriteToLog(logStr, d);
}