#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include "LinkedList.h" // From Lab2
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

int size(string text)
{

	int size = 0;
	string::iterator it1, it2;
	it2 = text.end();
	it1 = text.begin();
	if (it1 != it2)
	{
		it2 = text.begin();
		it2++;
		it1 = text.begin();
		while (it1 != it2)
		{
			if (it2 == text.end())
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

int Partition(vector<int>& vec1, int low, int high)
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

// In hind sight MergeSort would have been much easier with an array

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
						vec3.insert(k, 2, vec.vec1[i]);
						i++;
						j++;
						len3 = len3 + 2;
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
								i++;
								j++;
								len3++;
								len3++;
								L = len3;
								break;
							}

							k++;
						}
						if (L != len3)
						{
							vec3.insert(k, 2, vec.vec1[i]);
							i++;
							j++;
							len3++;
						}
					}
				}
				else if (len3 == 0)
				{
					vec3.push_back(vec.vec2[j]);
					vec3.push_back(vec.vec1[i]);
					i++;
					j++;
					len3++;
					len3++;
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
						L = len3;
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
						L = len3;
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
			if (len3 == 0)
			{
				vec3.push_back(vec.vec2[j]);
				len3++;
			}
			else if (*k > vec.vec2[j])
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
						L = len3;
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

unsigned int Hash(string word)
{
	int length = size(word);
	unsigned int h;

	if (length < 6)
	{
		cout << "The min string length is 6, please enter a longer string" << endl;
		return 0;
	}
	if ((word[0] == 'a') || (word[0] = 'A'))
	{
		h = ((1 * word[0]) + (3 * word[1]) + (5 * word[2]) + (7 * word[3]) + (11 * word[4]) + (13 * word[5]));
	}
	else if ((word[0] == 'b') || (word[0] = 'B'))
	{
		h = ((17 * word[0]) + (19 * word[1]) + (23 * word[2]) + (29 * word[3]) + (31 * word[4]) + (37 * word[5]));
	}
	else if ((word[0] == 'c') || (word[0] = 'C'))
	{
		h = ((41 * word[0]) + (43 * word[1]) + (47 * word[2]) + (53 * word[3]) + (59 * word[4]) + (61 * word[5]));
	}
	else if ((word[0] == 'd') || (word[0] = 'D'))
	{
		h = ((67 * word[0]) + (71 * word[1]) + (73 * word[2]) + (79 * word[3]) + (83 * word[4]) + (89 * word[5]));
	}
	else if ((word[0] == 'e') || (word[0] = 'E'))
	{
		h = ((97 * word[0]) + (101 * word[1]) + (103 * word[2]) + (107 * word[3]) + (109 * word[4]) + (113 * word[5]));
	}
	else if ((word[0] == 'f') || (word[0] = 'F'))
	{
		h = ((127 * word[0]) + (131 * word[1]) + (137 * word[2]) + (139 * word[3]) + (149 * word[4]) + (151 * word[5]));
	}
	else if ((word[0] == 'g') || (word[0] = 'G'))
	{
		h = ((151 * word[0]) + (113 * word[1]) + (89 * word[2]) + (61 * word[3]) + (37 * word[4]) + (13 * word[5]));
	}
	else if ((word[0] == 'h') || (word[0] = 'H'))
	{
		h = ((149 * word[0]) + (109 * word[1]) + (83 * word[2]) + (59 * word[3]) + (31 * word[4]) + (11 * word[5]));
	}
	else if ((word[0] == 'i') || (word[0] = 'I'))
	{
		h = ((139 * word[0]) + (107 * word[1]) + (79 * word[2]) + (53 * word[3]) + (29 * word[4]) + (7 * word[5]));
	}
	else if ((word[0] == 'j') || (word[0] = 'J'))
	{
		h = ((137 * word[0]) + (103 * word[1]) + (73 * word[2]) + (47 * word[3]) + (23 * word[4]) + (5 * word[5]));
	}
	else if ((word[0] == 'k') || (word[0] = 'K'))
	{
		h = ((131 * word[0]) + (101 * word[1]) + (71 * word[2]) + (43 * word[3]) + (19 * word[4]) + (3 * word[5]));
	}
	else if ((word[0] == 'l') || (word[0] = 'L'))
	{
		h = ((127 * word[0]) + (97 * word[1]) + (67 * word[2]) + (41 * word[3]) + (17 * word[4]) + (1 * word[5]));
	}
	else if ((word[0] == 'm') || (word[0] = 'M'))
	{
		h = ((1 * word[5]) + (3 * word[4]) + (5 * word[3]) + (7 * word[2]) + (11 * word[1]) + (13 * word[0]));
	}
	else if ((word[0] == 'n') || (word[0] = 'N'))
	{
		h = ((17 * word[5]) + (19 * word[4]) + (23 * word[3]) + (29 * word[2]) + (31 * word[1]) + (37 * word[0]));
	}
	else if ((word[0] == 'o') || (word[0] = 'O'))
	{
		h = ((41 * word[5]) + (43 * word[4]) + (47 * word[3]) + (53 * word[2]) + (59 * word[1]) + (61 * word[0]));
	}
	else if ((word[0] == 'p') || (word[0] = 'P'))
	{
		h = ((67 * word[5]) + (71 * word[4]) + (73 * word[3]) + (79 * word[2]) + (83 * word[1]) + (89 * word[0]));
	}
	else if ((word[0] == 'q') || (word[0] = 'Q'))
	{
		h = ((97 * word[5]) + (101 * word[4]) + (103 * word[3]) + (107 * word[2]) + (109 * word[1]) + (113 * word[0]));
	}
	else if ((word[0] == 'r') || (word[0] = 'R'))
	{
		h = ((127 * word[5]) + (131 * word[4]) + (137 * word[3]) + (139 * word[2]) + (149 * word[1]) + (151 * word[0]));
	}
	else if ((word[0] == 's') || (word[0] = 'S'))
	{
		h = ((151 * word[5]) + (113 * word[4]) + (89 * word[3]) + (61 * word[2]) + (37 * word[1]) + (13 * word[0]));
	}
	else if ((word[0] == 't') || (word[0] = 'T'))
	{
		h = ((149 * word[5]) + (109 * word[4]) + (83 * word[3]) + (59 * word[2]) + (31 * word[1]) + (11 * word[0]));
	}
	else if ((word[0] == 'u') || (word[0] = 'U'))
	{
		h = ((139 * word[5]) + (107 * word[4]) + (79 * word[3]) + (53 * word[2]) + (29 * word[1]) + (7 * word[0]));
	}
	else if ((word[0] == 'v') || (word[0] = 'V'))
	{
		h = ((137 * word[5]) + (103 * word[4]) + (73 * word[3]) + (47 * word[2]) + (23 * word[1]) + (5 * word[0]));
	}
	else if ((word[0] == 'w') || (word[0] = 'W'))
	{
		h = ((131 * word[5]) + (101 * word[4]) + (71 * word[3]) + (43 * word[2]) + (19 * word[1]) + (3 * word[0]));
	}
	else if ((word[0] == 'x') || (word[0] = 'X'))
	{
		h = ((127 * word[5]) + (97 * word[4]) + (67 * word[3]) + (41 * word[2]) + (17 * word[1]) + (1 * word[0]));
	}
	else if ((word[0] == 'y') || (word[0] = 'Y'))
	{
		h = ((157 * word[5]) + (163 * word[4]) + (167 * word[3]) + (173 * word[2]) + (179 * word[1]) + (181 * word[0]));
	}
	else if ((word[0] == 'z') || (word[0] = 'Z'))
	{
		h = ((191 * word[5]) + (193 * word[4]) + (197 * word[3]) + (199 * word[2]) + (211 * word[1]) + (223 * word[0]));
	}

	return h;
}

struct chainBucket {
	bool collision;
	unsigned int Hash;
	List* bucketList = new List;
};

class HashTable {
private:

	chainBucket Table[79];

public:

	unsigned int collisions;

	void addToTable(string text);
	void printTable();
};

void HashTable::addToTable(string text)
{
	unsigned int hash = Hash(text), key = Hash(text) % 79;

	if (hash == 0)
	{
		return;
	}
	if (Table[key].Hash != hash)
	{
		chainBucket bucket;
		bucket.collision = false;
		bucket.Hash = hash;
		bucket.bucketList = new List;
		bucket.bucketList->insertAsFirst(text);
		Table[key] = bucket;
	}
	else
	{
		Table[key].collision = true;
		Table[key].bucketList->insertAsLast(text);
		collisions++;
	}
}


// Help from lab 10 HashMaps

void HashTable::printTable()
{
	cout << "\nKey:[HASHVAL] Bucket:[<COLLISION?>]\n";
	cout << ">>  LinkedList  \n\n";

	for (const auto& n : Table) 
	{
		List* chain = new List;
		chain = n.bucketList;

		if (n.Hash != 3435973836)
		{
			cout << "Key:[" << n.Hash << "] Bucket:[<" << n.collision << ">]";
			if (n.collision)
			{
				chain->print();
			}
				cout << "\n";
		}

	}
}