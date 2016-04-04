#pragma once

#include <vector>
#include <algorithm>

template <class T>
class CycliclyShiftedArrayItemBinarySearch
{
public:
	CycliclyShiftedArrayItemBinarySearch(std::vector<T> arr, int shiftK)
	{
		my_arr = arr;
		shiftArray(shiftK);
	}

	int contains(T value, int strategy = 0)
	{
		switch (strategy)
		{
			case 0:
			{
				int shiftNumber = getShiftNumber(my_arr);
				std::vector<T> unshifted(my_arr.size());
				int index = shiftNumber;
				for (int i = 0; i < my_arr.size(); i++)
				{
					unshifted[i] = my_arr[index++];
					index %= my_arr.size();
				}
				return std::binary_search(unshifted.begin(), unshifted.end(), value);
			}
			default:
				break;
			}
		return 0;
	}

private:
	int getShiftNumber(std::vector<T> arr) const
	{
		for (int i = 0; i < arr.size() - 1;i++)
		{
			if (arr[i] >= arr[i + 1])
			{
				++i %= my_arr.size();
				return i;
			}
		}
		return 0;
	}

	void shiftArray(int k)
	{
		std::vector<T> dummy_arr(my_arr.size());
		int index = k % my_arr.size();
		for (auto i : my_arr)
		{
			dummy_arr[index++] = i;
			index %= my_arr.size();
		}
		my_arr = dummy_arr;
	}

	std::vector<T> my_arr;
};