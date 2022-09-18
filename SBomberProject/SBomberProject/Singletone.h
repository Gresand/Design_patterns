#pragma once

#include <string>
#include <stdint.h>
#include <fstream>

class Singletone
{
public:
	static Singletone& GetInstance()
	{
		static Singletone instance;
		return instance;
	}

	void __fastcall OpenLogFile(const std::string& FN);
	void CloseLogFile();
	void __fastcall WriteToLog(const std::string& str);
	void __fastcall WriteToLog(const std::string& str, int n);
	void __fastcall WriteToLog(const std::string& str, double d);
	std::string GetCurDateTime();
private:
	Singletone() {};
	Singletone(const Singletone& obj) = delete;
	Singletone& operator = (const Singletone& obj) = delete;
	std::ofstream logOut;
};




