#pragma once
#include "SBomber.h"
#include "DynamicObject.h"
#include <vector>

class BombIterator
{
public:
	BombIterator(std::vector<DynamicObject*>& refArr) : refArr(refArr), curIndex(-1), ptr(nullptr)
	{
		++(*this);
	}

	void reset()
	{
		curIndex = -1; 
		ptr = nullptr;
	}

	BombIterator& operator++ ()
	{
		curIndex++;
			if(curIndex ==-1) curIndex =0;

		for(; curIndex < refArr.size(); curIndex++)
		{ 
			Bomb* pBomb = dynamic_cast<Bomb*>(refArr[curIndex]);

			if(pBomb != nullptr)
			{ 
				ptr = &refArr[curIndex];
				break;
			} 
		} 

		if(curIndex == refArr.size()) 
		{ 
			curIndex =-1;
			ptr =nullptr;
		}

		return*this;
	}

	BombIterator& operator-- ()
	{
		if(curIndex ==-1) 
			curIndex = refArr.size() -1;
		
		for(; curIndex >=0; curIndex--)
		{ 
			Bomb* pBomb = dynamic_cast<Bomb*>(refArr[curIndex]);

			if(pBomb != nullptr)
			{ 
				ptr = &refArr[curIndex];
				break; 
			} 
		} 
		if(curIndex ==-1)
		{
			ptr = nullptr;
		}
		return*this;
	}

	DynamicObject* & operator*()
	{
		return refArr.at(curIndex);
	} 
	
	bool operator==(BombIterator it)
	{
		if(curIndex == it.curIndex && ptr == it.ptr && refArr == it.refArr)
		{
			return true;
		}
		return false;
	}

	bool operator!=(BombIterator it)
	{
		return!(*this== it); 
	} 

private:

	std::vector<DynamicObject*>& refArr;
	int curIndex;
	DynamicObject** ptr;
};

