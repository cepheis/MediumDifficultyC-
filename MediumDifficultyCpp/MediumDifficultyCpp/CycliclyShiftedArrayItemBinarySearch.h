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
				return regular_binary_search(unshifted, 0, unshifted.size() - 1, value);
			}
			case 1:
			{
				return shifted_binary_search(my_arr, 0, my_arr.size() - 1, value);
			}
			default:
				break;
			}
		return 0;
	}

private:

	bool regular_binary_search(std::vector<T> arr, int begin, int end,T value)
	{
		int mid = (begin + end) / 2;
		if (arr[mid] == value)
		{
			return true;
		}
		
		if (begin != end)
		{
			if (value < arr[mid])
				return regular_binary_search(arr, begin, mid, value);
			return regular_binary_search(arr, mid+1, end, value);
		}
		return false;
	}

	bool shifted_binary_search(std::vector<T> arr, int begin, int end, T value)
	{
		int mid = (begin + end) / 2;
		if (arr[mid] == value)
		{
			return true;
		}

		if (begin != end)
		{
			if (value < arr[mid])
			{
				if (arr[begin] <= arr[mid])
				{
					if (arr[begin] <= value)
						return regular_binary_search(arr, begin, mid, value);
					return shifted_binary_search(arr, mid + 1, end, value);
				}
				return shifted_binary_search(arr, begin, mid, value);
			}

			if (arr[mid] <= arr[end])
			{
				if (arr[end] >= value)
					return regular_binary_search(arr, mid + 1, end, value);
				return shifted_binary_search(arr, begin, mid, value);
			}
			return shifted_binary_search(arr, mid + 1, end, value);
		}
		return false;
	}


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