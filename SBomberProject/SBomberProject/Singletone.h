#pragma once

#include <string>
#include <stdint.h>
#include <fstream>

#include "AbstractSingletone.h"

class FileLoggerSingletone : public AbstractSingletone
{
public:
	static FileLoggerSingletone& GetInstance()
	{
		static FileLoggerSingletone instance;
		return instance;
	}

	void __fastcall OpenLogFile(const std::string& FN);
	void CloseLogFile();
	void __fastcall WriteToLog(const std::string& str);
	void __fastcall WriteToLog(const std::string& str, int n);
	void __fastcall WriteToLog(const std::string& str, double d);
	std::string GetCurDateTime();
private:
	FileLoggerSingletone() {};
	FileLoggerSingletone(const FileLoggerSingletone& obj) = delete;
	FileLoggerSingletone& operator = (const FileLoggerSingletone& obj) = delete;
	std::ofstream logOut;
};




