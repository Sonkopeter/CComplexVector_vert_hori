#pragma once
#include "CFabric.h"
class CFabric1 : public CFabric
{
public:
	CComplexVector* Create(string name, vector<CComplex> arr)
	{
		return new CComplexVector1(name, arr);
	}
};