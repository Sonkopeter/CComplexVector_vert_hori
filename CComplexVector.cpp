#include <stdio.h>
#include "CComplexVector.h"
#include "CFabric.h"
#include "CFabric0.h"
#include "CFabric1.h"

CComplex CComplex::operator*(const CComplex& second)
{
	CComplex retNum;
	retNum.re = re * second.re - im * second.im;
	retNum.im = re * second.im + second.re * im;
	return retNum;
}

CComplex CComplex::operator+(const CComplex& second)
{
	CComplex retNum;
	retNum.re = re + second.re;
	retNum.im = im + second.im;
	return retNum;
}

CComplex CComplex::operator-(const CComplex& second)
{
	CComplex retNum;
	retNum.re = re - second.re;
	retNum.im = im - second.im;
	return retNum;
}

CComplex& CComplex::operator=(const CComplex& second) {
	re = second.re;
	im = second.im;
	return *this;
}


CComplexVector& CComplexVector::operator=(const CComplexVector& second) {
    Vec.resize(second.Vec.size());
#pragma omp parallel for
    for (int i = 0; i < second.Vec.size(); i++) {
		Vec[i] = second.Vec[i];
	}
	return *this;
}

CComplex CComplexVector::operator*(const CComplexVector& second) {
	CComplex retNum;
	size_t Min;
    if (second.Vec.size() < Vec.size())
        Min = second.Vec.size();
    else Min = Vec.size();
	auto start = chrono::system_clock::now();
#pragma omp parallel for
    for (int i = 0; i < Min; i++) {
		CComplex secSopr;
		secSopr.re = second.Vec[i].re;
		secSopr.im = -second.Vec[i].im;
		retNum = retNum + (secSopr * Vec[i]);
	}
	auto end = chrono::system_clock::now();
	int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
	cout << "Time: " << elapsed_ms << " ms\n";
	return retNum;
}

void output(std::vector<CComplexVector*> v_obj, std::string filename)
{
	std::map <string, CFabric*> ourMap;
	ourMap["hori"] = new CFabric0;
	ourMap["vert"] = new CFabric1;
	string tmpString;
	fstream file;
	file.open(filename, ios::in);
	try {
		if (!file) {
			cout << "\nCan't find this file : " << filename;
			throw std::runtime_error("wrong file name\n");
		}
		while (getline(file, tmpString)) {
			stringstream strStream;
			strStream << tmpString;
			string type;
			strStream >> type;
			string name;
			strStream >> name;
			int size;
			strStream >> size;
			vector<CComplex> arr(size);
			int el;
			size_t i = 0;
			while (strStream >> el) {
				arr[i].re = el;
				if (strStream >> el)
					arr[i].im = el;
				i++;
			}

			auto cur = ourMap.find(type);
			if (cur == ourMap.end()) {
				throw std::invalid_argument("Error! Wrong type of vector in file input.txt!\n");
			}
			v_obj.push_back(cur->second->Create(name, arr));
		}

		for (auto it : v_obj)
		{
			it->output();
		}
		for (auto it : v_obj)
		{
			delete it;
		}
		delete ourMap["hori"];
		delete ourMap["vert"];
		file.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}
}
