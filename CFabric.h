#pragma once
#include "CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"

class CFabric {
public:
	virtual CComplexVector* Create(string name, vector<CComplex> arr) = 0;
	virtual ~CFabric();
};
