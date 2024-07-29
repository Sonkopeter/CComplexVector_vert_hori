#include "CComplexVector1.h"
void CComplexVector1::output()
{
	ofstream file(name_, ios_base::app);
    for (size_t i = 0; i < Vec.size(); i++)
		file << Vec[i] << "\n";
	file << endl;
}
