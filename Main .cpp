#include "CComplexVector.h"
#include "CFabric.h"
#include "CFabric0.h"
#include "CFabric1.h"
#include "autotests.h"

int main() {
    //autotest();
    AutoMP();
	vector <CComplexVector*> v_obj;
	
    //CComplex a(1, 1), b(3, 0), c(2, 0), d(4, 0);
    //CComplex yo = a;
    //vector<CComplex> arr1 = { a, c };
    //vector<CComplex> arr2 = { b, d };
    //CComplexVector0 v0("out5.txt", arr1), res1;
    //CComplexVector1 v1("out6.txt", arr2);
    //CComplexVector1 res2 = v0 - v1;

    //cout << "v0 = " << v0 << endl; cout << "v1 = " << v1 << endl;
    //res1 = v0 + v1;
    //cout << "res1 = " << res1 << endl; cout << "res2 = " << res2 << endl;
	
	string filename = "1.txt";
    output(v_obj, filename);
	return 0;
}
