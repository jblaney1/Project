#include <vector>
#include <iterator>
#include <iostream>
#include <string>

#include "LinkedList.h"

using std::cout;
using std::endl;

using std::vector;
using std::iterator;
using std::string;


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
	vector<int> vec3 = {};
	vector<int>::iterator k;

	int j = 0, i = 0, L, len1 = size(vec.vec1), len2 = size(vec.vec2), len3 = size(vec3);

	while (i < (len1) || j < (len2))
	{
		k = vec3.begin();
		L = 0;

		if ((len1) > i && len2 > j)
		{
			if (vec.vec1[i] > vec.vec2[j])
			{
				if (len3 != 0)
				{
					if (*k > vec.vec2[j])
					{
						vec3.emplace(k, vec.vec2[j]);
						j++;
						len3++;
					}
					else
					{
						while (*k < vec.vec2[j])
						{
							L++;
							if (L == len3)
							{
								vec3.push_back(vec.vec2[j]);
								len3++;
								j++;
								L++;
								break;
							}
							k++;
						}
						if (L != len3)
						{
							vec3.emplace(k, vec.vec2[j]);
							j++;
							len3++;
						}
					}
				}
				else if (len3 == 0)
				{
					vec3.emplace(k, vec.vec2[j]);
					len3++;
					j++;
				}
			}
			else if (vec.vec1[i] < vec.vec2[j])
			{
				if (len3 != 0)
				{
					if (*k > vec.vec1[i])
					{
						vec3.emplace(k, vec.vec1[i]);
						i++;
						len3++;
					}
					else
					{
						while (*k < vec.vec1[i])
						{
							L++;
							if (L == len3)
							{
								vec3.push_back(vec.vec1[i]);
								len3++;
								i++;
								L++;
								break;
							}
							k++;
						}
						if (L != len3)
						{
							vec3.emplace(k, vec.vec1[i]);
							i++;
							len3++;
						}
					}
				}
				else if (len3 == 0)
				{
					vec3.emplace(k, vec.vec2[i]);
					len3++;
					i++;
				}
			}
			else
			{
				if (len3 != 0)
				{
					if (*k > vec.vec1[i])
					{
						vec3.emplace(k, vec.vec1[i]);
						k++;
						vec3.emplace(k, vec.vec2[j]);
						i++;
						j++;
						len3++;
					}
					else
					{
						while (*k < vec.vec1[i])
						{
							L++;
							if (L == len3)
							{
								vec3.push_back(vec.vec2[j]);
								vec3.push_back(vec.vec1[i]);
								len3 + 2;
								i++;
								j++;
								L + 2;
								break;
							}

							k++;
						}
						if (L != len3)
						{
							vec3.emplace(k, vec.vec1[i]);
							k++;
							vec3.emplace(k, vec.vec2[j]);
							i++;
							j++;
							len3 + 2;

						}
					}
				}
				else if (len3 == 0)
				{
					vec3.emplace(k, vec.vec1[i]);
					len3++;
					k++;
					vec3.emplace(k, vec.vec2[j]);
					len3++;
					i++;
					j++;
				}
			}
		}
		else if (i < j)
		{
			if (*k > vec.vec1[i])
			{
				vec3.emplace(k, vec.vec1[i]);
				i++;
				len3++;
			}
			else
			{
				while (*k < vec.vec1[i])
				{
					L++;
					if (L == len3)
					{
						vec3.push_back(vec.vec1[i]);
						len3++;
						L++;
						i++;
						break;
					}
					k++;
				}
				if (L != len3)
				{
					vec3.emplace(k, vec.vec1[i]);
					i++;
					len3++;
				}
			}
		}
		else if (j < i)
		{
			if (*k > vec.vec2[j])
			{
				vec3.emplace(k, vec.vec2[j]);
				j++;
				len3++;
			}
			else
			{
				while (*k < vec.vec2[j])
				{
					L++;
					if (L == len3)
					{
						vec3.push_back(vec.vec2[j]);
						len3++;
						j++;
						L++;
						break;
					}
					k++;
				}
				if (L != len3)
				{
					vec3.emplace(k, vec.vec2[j]);
					j++;
					len3++;
				}
			}
		}
		else if (len1 < len2 && !((len1) > i && len2 > j))
		{
			if (*k > vec.vec2[j])
			{
				vec3.emplace(k, vec.vec2[j]);
				j++;
				len3++;
			}
			else
			{
				while (*k < vec.vec2[j])
				{
					L++;
					if (L == len3)
					{
						vec3.push_back(vec.vec2[j]);
						len3++;
						j++;
						L++;
						break;
					}
					k++;
				}
				if (L != len3)
				{
					vec3.emplace(k, vec.vec2[j]);
					j++;
					len3++;
				}
			}
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

			for (int i = (length / 2); i < length; i++)
			{
				vec.vec2.push_back(vec1[i]);
			}
		}
		else
		{
			int low = (length / 2), high = (length / 2);

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
				vec.vec2.push_back(vec1[i]);
				vec.vec2.push_back(vec1[i + 1]);
				j = length - 1;
			}
			else
			{
				vec.vec2.push_back(vec1[i]);
			}
			vec.vec1.push_back(vec1[j]);
			j++;
		}
	}
	return vec1 = Merge(vec);
}

// Hash()

struct chainBucket {
	bool collision;//whether or not there was a collision at this field
	List* bucketList;
};

class HashTable {
private:

	chainBucket Table[79];

public:

	unsigned int collisions;


	void addToTable(string text);
};

unsigned int Hash(string word)
{
	unsigned int hash = ((2*word[1]) + (4*word[2]) + (3*word[3]));
	return hash;
}

void HashTable::addToTable(string text)
{
	unsigned int hash = Hash(text),  key = Hash(text) % 79;

	if (Table[key].bucketList->empty())
	{
		chainBucket bucket;
		bucket.collision = false;
		bucket.bucketList = new List;
		bucket.bucketList->insertAsFirst(Hash(text));
		Table[key] = bucket;
	}
	else
	{
		Table[key].collision == true;
		Table[key].bucketList->insertAsLast(hash);
		collisions++;
	}
}
