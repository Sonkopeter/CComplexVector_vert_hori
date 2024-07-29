#include"autotests.h"

#include <stdio.h>
#include <math.h>
#include <sstream>
#include <map>
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
#include <sstream>
int autotest()
{
    CComplex a(1, 1), b(3, 0), c(2, 0), d(4, 0);
    vector<CComplex> arr1 = { a, c };
    vector<CComplex> arr2 = { b, d };
    cout << a << endl;
    CComplexVector0 v0("out5.txt", arr1), resPl;
    CComplexVector1 v1("out6.txt", arr2), resMi;
    cout << "v0 = " << v0 << endl;
    cout << "v1 = " << v1 << endl;





    resMi = v0 - v1;
    cout << "resMi = " << resMi << endl;
   //cout << resMi.Vec[0].re << endl;
    //cout << resMi.Vec[0].im << endl;
    //cout << resMi.Vec[1].re << endl;
    //cout << resMi.Vec[1].im << endl;


    if ((fabs(resMi.Vec[0].re + 2.0) < DBL_EPSILON) && (fabs(resMi.Vec[0].im - 1.0) < DBL_EPSILON) && (fabs(resMi.Vec[1].re + 2.0) < DBL_EPSILON) && (fabs(resMi.Vec[1].im) < DBL_EPSILON)){
        cout << "Test 1 passed" << endl;
    }
    else{
        cout << "Wrong minus" << endl;
        return 0;
    }

    CComplexVector1 res2 = v0 - v1;
    cout << "res2 = " << res2 << endl;

    if ((fabs(res2.Vec[0].re + 2.0) < DBL_EPSILON) && (fabs(res2.Vec[0].im - 1.0) < DBL_EPSILON) && (fabs(res2.Vec[1].re + 2.0) < DBL_EPSILON) && (fabs(res2.Vec[1].im) < DBL_EPSILON)){
        cout << "Test 2 passed" << endl;

    }
    else{
        cout << "Wrong other minus" << endl;
        return 0;
    }

    resPl = v0 + v1;
    cout << "resPl = " << resPl << endl;

    if ((fabs(resPl.Vec[0].re - 4.0) < DBL_EPSILON) && (fabs(resPl.Vec[0].im - 1.0) < DBL_EPSILON) && (fabs(resPl.Vec[1].re - 6.0) < DBL_EPSILON) && (fabs(resPl.Vec[1].im) < DBL_EPSILON)){
        cout << "Test 3 passed" << endl;

    }
    else{
        cout << "Wrong plus" << endl;
        return 0;
    }

    CComplexVector0 res3 = v0 + v1;
    cout << "res3 = " << res3 << endl;

    if ((fabs(res3.Vec[0].re - 4.0) < DBL_EPSILON) || (fabs(res3.Vec[0].im - 1.0) < DBL_EPSILON) || (fabs(res3.Vec[1].re - 6.0) < DBL_EPSILON) || (fabs(res3.Vec[1].im) < DBL_EPSILON)){
        cout << "Test 4 passed" << endl;
    }
    else{
        cout << "Wrong other plus" << endl;
        return 0;
    }


    return 1;
}
