#include <iostream>
#include "CycliclyShiftedArrayItemBinarySearch.h"

int main()
{
	std::vector<int> elms = {1,3,5,6,7,8,9};
	CycliclyShiftedArrayItemBinarySearch<int> obj(elms, 5);
	obj.contains(3);

	return 0;
}