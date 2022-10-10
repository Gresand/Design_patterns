#pragma once

#include <stdint.h>
#include <ctime>

#include "DestroyableGroundObject.h"
#include "Mediator.h"

class Tank : public DestroyableGroundObject
{
public:
	Tank(Mediator* pMed)
	{
		pMediator = pMed;
	}
	~Tank()
	{
		pMediator = nullptr;
	}
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	void SendMenace() const;

	Mediator* pMediator;

private:

	std::string strMenace{ "Caput!" };
	std::string strEmpty{ "" };
	const uint16_t score = 30;
};

