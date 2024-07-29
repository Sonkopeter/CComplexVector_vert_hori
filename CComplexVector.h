#pragma once

#include <cfloat>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <map>
#include <chrono>
#include <omp.h>
#include <sstream>
using namespace std;

class CComplex {
public:
	double im, re;
	CComplex() { re = 0; im = 0; }
	CComplex(double re, double im) { this->re = re; this->im = im; }
	CComplex(const CComplex& get) {
		re = get.re;
		im = get.im;
	}
	CComplex operator+(const CComplex& second);
	CComplex operator*(const CComplex& second);
	CComplex operator-(const CComplex& second);
	CComplex& operator=(const CComplex& second);
//	double abs();
	friend std::ostream& operator<<(std::ostream& out, const CComplex& num)
	{
		return num.print(out);
	}

	std::ostream& print(std::ostream& out) const
	{
				if ((std::abs(re) < DBL_EPSILON) && (std::abs(im) < DBL_EPSILON)) {
					out << "0";
				}
				else if (std::abs(re) < DBL_EPSILON) {
					out << im << "*i";
				}
				else if (std::abs(im) < DBL_EPSILON) {
					out << re;
				}
				else if (im > 0) {
					out << re << "+" << im << "*i";
				}
				else out << re << im << "*i";
				return out;
	}
};

class CComplexVector {
protected:
	string name_;
public:
	vector<CComplex> Vec;
	virtual ~CComplexVector() = default;
	CComplexVector()
	{
		Vec.resize(2);
		for (int i = 0; i < 2; i++)
		{
			Vec[i].re = 0.0;
			Vec[i].im = 0.0;
		}
		name_ = "";
	}
	CComplexVector(int num)
	{
		Vec.resize(num);
		for (int i = 0; i < num; i++)
		{
			Vec[i].re = 0.0;
			Vec[i].im = 0.0;
		}
		name_ = "";
	}
	CComplexVector(const CComplexVector& get)
	{
        Vec.resize(get.Vec.size());
        for (size_t i = 0; i < get.Vec.size(); i++) {
			Vec[i] = get.Vec[i];
		}
		name_ = get.name_;
	}
	CComplexVector(string name, vector<CComplex> arr) {
        Vec.resize(arr.size());
        for (size_t i = 0; i < arr.size(); i++)
		{
			this->Vec[i].re = arr[i].re;
			this->Vec[i].im = arr[i].im;
		}
		name_ = name;
	}
	void rand_vector(size_t s) {
		Vec.resize(s);
		for (size_t i = 0; i < s; i++) {
			Vec[i].re = rand();
			Vec[i].im = rand();
		}
	}
	CComplexVector& operator=(const CComplexVector& second);
	CComplex operator*(const CComplexVector& second);
	virtual void output() = 0;
	friend std::ostream& operator<<(std::ostream& out, const CComplexVector& num)
	{
		return num.print(out);
	}

	std::ostream& print(std::ostream& out) const
	{
		out << "[" << Vec[0] << ", " << Vec[1] << "]";
		return out;
	}
};

void output(std::vector<CComplexVector*> v_obj, std::string filename);
