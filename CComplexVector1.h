#pragma once
#include "CComplexVector.h"
using namespace std;

class CComplexVector0;
CComplexVector0 operator+(const CComplexVector& first, const CComplexVector& second);
CComplexVector0 operator-(const CComplexVector& first, const CComplexVector& second);

class CComplexVector1 : public CComplexVector
{
public:
	void output() override;
	CComplexVector1() : CComplexVector() {}
    CComplexVector1(const CComplexVector& get) : CComplexVector(get) {}
	CComplexVector1(string name, vector<CComplex> arr) : CComplexVector(name, arr) {}
	using CComplexVector::operator=;
	using CComplexVector::operator*;
};
