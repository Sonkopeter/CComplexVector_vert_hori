#pragma once
#include "CComplexVector.h"
using namespace std;

class CComplexVector0 : public CComplexVector
{
public:
	void output() override;
	CComplexVector0() : CComplexVector() {}
	CComplexVector0(int num) : CComplexVector(num) {}
	CComplexVector0(const CComplexVector& get) : CComplexVector(get) {}
	CComplexVector0(string name, vector<CComplex> arr) : CComplexVector(name, arr) {}
	using CComplexVector::operator=;
	using CComplexVector::operator*;
	friend CComplexVector0 operator+(const CComplexVector& first, const CComplexVector& second);
	friend CComplexVector0 operator-(const CComplexVector& first, const CComplexVector& second);
};
