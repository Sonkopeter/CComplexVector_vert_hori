#include "autotests.h"
#include "CComplexVector0.h"

void AutoMP() {
    
    int i = 5000000;
    CComplexVector0 X, Y, plus, min;
    X.rand_vector(i); Y.rand_vector(i);
    CComplex scalar_product;

    cout << "Checking the operation plus\n\n";
    plus = X + Y;
    cout << "Size: " << i << "\n";


    cout << "\n\nChecking the operation minus\n\n";
    min = X - Y;
    cout << "Size: " << i << "\n";


    cout << "\n\nChecking the operation scalar product\n\n";
    scalar_product = X * Y;
    cout << "Size: " << i << "\n";

}