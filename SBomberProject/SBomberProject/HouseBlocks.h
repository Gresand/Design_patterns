#pragma once

#include <iostream>
#include <vector>
#include <string>

class MakeDefaultRoof
{
private:
	std::vector<std::string> roof;
public:
	MakeDefaultRoof()
	{
		roof.push_back("  ########  ");
		roof.push_back("##        ##");
	}
	std::vector<std::string> MakeRoof() const
	{
		return roof;
	}
};

class MakeModernRoof
{
private:
	std::vector<std::string> roof;
public:
	MakeModernRoof()
	{
		roof.push_back("   ######   ");
		roof.push_back("###******###");
	}
	~MakeModernRoof()
	{
		roof.clear();
		roof.shrink_to_fit();
	}
	std::vector<std::string> MakeRoof() const
	{
		return roof;
	}
};

class MakeDefaultWall
{
private:
	std::vector<std::string> wall;
public:
	MakeDefaultWall()
	{
		wall.push_back("############");
		wall.push_back("############");
		wall.push_back("############");
		wall.push_back("############");
	}
	std::vector<std::string> MakeWall() const
	{
		return wall;
	}
};

class MakeDefaultWindow
{
private:
	std::vector<std::string> window;
public:
	MakeDefaultWindow()
	{
		window.push_back("#          #");
		window.push_back("#          #");
	}
	std::vector<std::string> MakeWindow() const
	{
		return window;
	}
};

class MakeSmallWindow
{
private:
	std::vector<std::string> window;
public:
	MakeSmallWindow()
	{
		window.push_back("####    ####");
		window.push_back("####    ####");
	}
	std::vector<std::string>& MakeWindow()
	{
		return window;
	}
};

class HouseBlocks
{
public:
	HouseBlocks()
	{
		for (int j = 0; j < 6; j++)
		{
			house.push_back("");
		}
	}
	std::vector<std::string> house;

	std::vector<MakeDefaultRoof> defaultRoof;
	std::vector<MakeModernRoof> modernRoof;
	std::vector<MakeDefaultWall> defaultWall;
	std::vector<MakeDefaultWindow> defaultWindow;
	std::vector<MakeSmallWindow> smallWindow;

	std::vector<std::string>* getHouse();
};

