#include <iostream>
#include "CycliclyShiftedArrayItemBinarySearch.h"

int main()
{
	std::vector<int> elms = {1,3,5,6,7,8,9};
	CycliclyShiftedArrayItemBinarySearch<int> obj(elms, 5);
	std::cout<<obj.contains(3,1);
	std::cout << obj.contains(1, 1);
	std::cout << obj.contains(2, 1);
	std::cout << obj.contains(4, 1);
	std::cout << obj.contains(6, 1);
	std::cout << obj.contains(10, 1);
	std::cout << obj.contains(9, 1);

	return 0;
}