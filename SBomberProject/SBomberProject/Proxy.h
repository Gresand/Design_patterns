#pragma once
#include "Singletone.h"
#include "AbstractSingletone.h"

class LoggerSingletone : public AbstractSingletone
{
public:
	static LoggerSingletone& GetInstance()
	{
		static LoggerSingletone instance;
		return instance;
	}

	void __fastcall OpenLogFile(const std::string& FN) override;
	void CloseLogFile() override;
	void __fastcall WriteToLog(const std::string& str) override;
	void __fastcall WriteToLog(const std::string& str, int n) override;
	void __fastcall WriteToLog(const std::string& str, double d) override;

private:
	LoggerSingletone() {};
	LoggerSingletone(const LoggerSingletone& obj) = delete;
	LoggerSingletone& operator = (const LoggerSingletone& obj) = delete;

	int numberOfLine = 0;
	std::string logStr;

	FileLoggerSingletone* singletone;
};

