#pragma once
#include "CFabric.h"
class CFabric0 : public CFabric
{
public:
	CComplexVector* Create(string name, vector<CComplex> arr)
	{
		return new CComplexVector0(name, arr);
	}
};