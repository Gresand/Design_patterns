#pragma once
#include "AbstractSingletone.h"
#include "Proxy.h"
#include <string>
#include <chrono>
#include <cstring>

class ProxyTime : public AbstractSingletone
{
public:
	static ProxyTime& GetInstance()
	{
		static ProxyTime theInstance;
		return theInstance;
	}
	std::string logStr;
	void __fastcall OpenLogFile(const std::string& FN);
	void CloseLogFile();
	void __fastcall WriteToLog(const std::string& str);
	void __fastcall WriteToLog(const std::string& str, int n);
	void __fastcall WriteToLog(const std::string& str, double d);
	std::string GetCurDateTime();
private:
	LoggerSingletone* proxy;
	ProxyTime() {};
	ProxyTime(const ProxyTime& ss) = delete;
	ProxyTime& operator=(const ProxyTime&) = delete;
};

