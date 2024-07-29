#include "CComplexVector0.h"

void CComplexVector0::output()
{
	std::ofstream file(name_, ios_base::app);
    for (size_t i = 0; i < Vec.size(); i++)
		file << Vec[i] << " ";
	file << "\n";
	file << std::endl;
}

CComplexVector0 operator+(const CComplexVector& first, const CComplexVector& second) {
    if (first.Vec.size() > second.Vec.size()) {
		CComplexVector0 retVec = first;
		auto start = chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < second.Vec.size(); i++) {
			retVec.Vec[i] = retVec.Vec[i] + second.Vec[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		cout << "Time: " << elapsed_ms << " ms\n";
		return retVec;
	}
	else {
		CComplexVector0 retVec = second;
		auto start = chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < first.Vec.size(); i++) {
			retVec.Vec[i] = retVec.Vec[i] + first.Vec[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		cout << "Time: " << elapsed_ms << " ms\n";
		return retVec;
	}
}

CComplexVector0 operator-(const CComplexVector& first, const CComplexVector& second) {
    if (first.Vec.size() > second.Vec.size()) {
		CComplexVector0 retVec = first;
		auto start = chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < second.Vec.size(); i++) {
			retVec.Vec[i] = retVec.Vec[i] - second.Vec[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		cout << "Time: " << elapsed_ms << " ms\n";
		return retVec;
	}
	else {
		CComplexVector0 retVec = first;
        retVec.Vec.resize(second.Vec.size());
		auto start = chrono::system_clock::now();
#pragma omp parallel for
        for (int i = 0; i < first.Vec.size(); i++) {
			retVec.Vec[i] = retVec.Vec[i] - second.Vec[i];
		}
#pragma omp parallel for
        for (int i = first.Vec.size(); i < second.Vec.size(); i++) {
			retVec.Vec[i] = second.Vec[i];
		}
		auto end = chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
		cout << "Time: " << elapsed_ms << " ms\n";
		return retVec;
	}
}
