#include <vector>
#include <iterator>

using std::vector;
using std::iterator;


void Swap(int* A, int* B)
{
	int swap = *A;
	*A = *B;
	*B = swap;
}

int size(vector<int> vec1)
{
	int size = 0;
	vector<int>::iterator it1, it2;
	it2 = vec1.end();
	it1 = vec1.begin();
	if (it1 != it2)
	{
		it2 = vec1.begin();
		it2++;
		it1 = vec1.begin();
		while (it1 != it2)
		{
			if (it2 == vec1.end())
			{
				size++;
				break;
			}
			size++;
			it1++;
			it2++;
		}
	}
	return size;
}

// QuickSort

double Partition(vector<int>& vec1, int low, int high)
{
	int pivot = vec1[high], i = (low - 1);

	for (int j = low; j <= (high - 1); j++)
	{
		if (vec1[j] <= pivot)
		{
			i++;
			Swap(&vec1[i], &vec1[j]);
		}
	}

	Swap(&vec1[i + 1], &vec1[high]);

	return (i + 1);
}

void Sort(vector<int>& vec1, int low, int high)
{
	if (low < high)
	{
		int pi = Partition(vec1, low, high);
		Sort(vec1, low, pi - 1);
		Sort(vec1, pi + 1, high);
	}
}

vector<int> QuickSort(vector<int>& vec1)
{
	Sort(vec1, 0, size(vec1) - 1);
	return vec1;
}

// Binary Search

bool BinarySearch(vector<int> vec1, int data)
{
	int length = size(vec1);

	if (length == 0)
	{
		return false;
	}
	else if (length == 2)
	{
		if (vec1[0] == data)
		{
			return true;
		}
		else if (vec1[1] == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if ((length % 2) == 1)
	{
		if (vec1[length / 2] == data)
		{
			return true;
		}
		else if (data < vec1[length / 2])
		{
			vector<int> vec2;

			for (int i = 0; i < length / 2; i++)
			{
				vec2.push_back(vec1[i]);
			}

			return BinarySearch(vec2, data);
		}
		else
		{
			vector<int> vec3;

				for (int i = (length / 2); i < length - 1; i++)
				{
					vec3.push_back(vec1[i]);
				}

			return BinarySearch(vec3, data);
		}
	}
	else
	{
		int low = length / 2, high = (length / 2) + 1;

		if (vec1[low] == data)
		{
			return true;
		}
		else if (vec1[high] == data)
		{
			return true;
		}
		else if (data < vec1[low])
		{
			vector<int> vec2;

			for (int i = 0; i < low; i++)
			{
				vec2.push_back(vec1[i]);
			}

			return BinarySearch(vec2, data);
		}
		else
		{
			vector<int> vec3;

				for (int i = high; i < length; i++)
				{
					vec3.push_back(vec1[i]);
				}

				return BinarySearch(vec3, data);
		}
	}
	
}

// Merge Sort

struct SplitVec {
	vector<int> vec1, vec2;
};

vector<int> Merge(SplitVec& vec)
{
	vector<int> vec3;
	int j = 0, i = 0, len1 = size(vec.vec1), len2 = size(vec.vec2);
	while (i < (len1) || j < (len2))
	{
		if ((len1) > i && len2 > j)
		{
			if (vec.vec1[i] > vec.vec2[j])
			{
				vec3.push_back(vec.vec2[j]);
				j++;
			}
			else if (vec.vec1[i] < vec.vec2[j])
			{
				vec3.push_back(vec.vec1[i]);
				i++;
			}
			else
			{
				vec3.push_back(vec.vec1[i]);
				vec3.push_back(vec.vec2[j]);
				i++;
				j++;
			}
		}
		else if (i < j)
		{
			vec3.push_back(vec.vec1[i]);
			i++;
		}
		else if (j < i)
		{
			vec3.push_back(vec.vec2[j]);
			j++;
		}
		else if (len1 > len2 && !((len1) > i && len2 > j))
		{
			vec3.push_back(vec.vec1[i]);
			i++;
		}
	}
	return vec3;
}

vector<int> MergeSort(vector<int>& vec1)
{
	SplitVec vec;
	int length = size(vec1);

	if (length > 4)
	{
		if ((length % 2) == 1)
		{
			for (int i = 0; i < length / 2; i++)
			{
				vec.vec1.push_back(vec1[i]);
			}

			for (int i = (length / 2); i < length - 1; i++)
			{
				vec.vec2.push_back(vec1[i]);
			}
		}
		else
		{
			int low = length / 2, high = (length / 2) + 1;

			for (int i = 0; i < low; i++)
			{
				vec.vec1.push_back(vec1[i]);
			}

			for (int i = high; i < length; i++)
			{
				vec.vec2.push_back(vec1[i]);
			}
		}
		MergeSort(vec.vec1);
		MergeSort(vec.vec2);
	}
	else if (length <= 4 && length != 0)
	{
		int j = length / 2;
		for (int i = 0; i < length / 2; i++)
		{
			if (length == 3)
			{
				vec.vec1.push_back(vec1[i]);
				vec.vec1.push_back(vec1[i + 1]);
			}
			else
			{
				vec.vec1.push_back(vec1[i]);
			}
			vec.vec2.push_back(vec1[j]);
			j++;
		}
	}
	return vec1 = Merge(vec);
}