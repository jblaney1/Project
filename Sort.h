#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include "LinkedList.h" // From Lab2
using std::cout;
using std::endl;
using std::cin;

using std::vector;
using std::iterator;
using std::string;

// A function to swap two elements
void Swap(int* A, int* B)
{
	int swap = *A;
	*A = *B;
	*B = swap;
}

// A function to find the size of a vector
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

// A function to find the size of a string
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

// QuickSort, help from GeeksforGeeks.com
// The function that actually does the sorting
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

// The function that makes the sort recursive
void Sort(vector<int>& vec1, int low, int high)
{
	if (low < high)
	{
		int pi = Partition(vec1, low, high);
		Sort(vec1, low, pi - 1);
		Sort(vec1, pi + 1, high);
	}
}

// The function that the user actually calls
vector<int> QuickSort(vector<int>& vec1)
{
	Sort(vec1, 0, size(vec1) - 1);
	return vec1;
}

// Binary Search
bool BinarySearch(vector<int> vec1, int data)
{
	int length = size(vec1);
	QuickSort(vec1);

	if (length == 0)
	{
		return false;
	}
	else if (length == 1)
	{
		if (vec1[0] == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (vec1[length - 1] == data)
	{
		return true;
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
	else
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

			for (int i = (length / 2); i < length; i++)
			{
				vec3.push_back(vec1[i]);
			}

			return BinarySearch(vec3, data);
		}
	}
}

// Merge Sort
// In hind sight MergeSort would have been much easier with an array

// A structure to hold both sides of the vector after being split
struct SplitVec {
	vector<int> vec1, vec2;
};

// The function that sorts and merges two vectors into one vector
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

// The function that the user calls
// It takes a vector and splits it into smaller vectors until the length is 2 or so
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
		//cout << "The min string length is 6, please enter a longer string" << endl;
		return 0;
	}
	if ((word[0] == 'a') || (word[0] = 'A'))
	{
		h = ((1 * word[0]) + (3 * word[1]) + (5 * word[2]) + (7 * word[3]) + (11 * word[4]) + (13 * word[5])) * 3;
	}
	else if ((word[0] == 'b') || (word[0] = 'B'))
	{
		h = ((17 * word[0]) + (19 * word[1]) + (23 * word[2]) + (29 * word[3]) + (31 * word[4]) + (37 * word[5])) * 5;
	}
	else if ((word[0] == 'c') || (word[0] = 'C'))
	{
		h = ((41 * word[0]) + (43 * word[1]) + (47 * word[2]) + (53 * word[3]) + (59 * word[4]) + (61 * word[5])) * 7;
	}
	else if ((word[0] == 'd') || (word[0] = 'D'))
	{
		h = ((67 * word[0]) + (71 * word[1]) + (73 * word[2]) + (79 * word[3]) + (83 * word[4]) + (89 * word[5])) * 11;
	}
	else if ((word[0] == 'e') || (word[0] = 'E'))
	{
		h = ((97 * word[0]) + (101 * word[1]) + (103 * word[2]) + (107 * word[3]) + (109 * word[4]) + (113 * word[5])) * 13;
	}
	else if ((word[0] == 'f') || (word[0] = 'F'))
	{
		h = ((127 * word[0]) + (131 * word[1]) + (137 * word[2]) + (139 * word[3]) + (149 * word[4]) + (151 * word[5])) * 17;
	}
	else if ((word[0] == 'g') || (word[0] = 'G'))
	{
		h = ((151 * word[0]) + (113 * word[1]) + (89 * word[2]) + (61 * word[3]) + (37 * word[4]) + (13 * word[5])) * 19;
	}
	else if ((word[0] == 'h') || (word[0] = 'H'))
	{
		h = ((149 * word[0]) + (109 * word[1]) + (83 * word[2]) + (59 * word[3]) + (31 * word[4]) + (11 * word[5])) * 23;
	}
	else if ((word[0] == 'i') || (word[0] = 'I'))
	{
		h = ((139 * word[0]) + (107 * word[1]) + (79 * word[2]) + (53 * word[3]) + (29 * word[4]) + (7 * word[5])) * 29;
	}
	else if ((word[0] == 'j') || (word[0] = 'J'))
	{
		h = ((137 * word[0]) + (103 * word[1]) + (73 * word[2]) + (47 * word[3]) + (23 * word[4]) + (5 * word[5])) * 31;
	}
	else if ((word[0] == 'k') || (word[0] = 'K'))
	{
		h = ((131 * word[0]) + (101 * word[1]) + (71 * word[2]) + (43 * word[3]) + (19 * word[4]) + (3 * word[5])) * 37;
	}
	else if ((word[0] == 'l') || (word[0] = 'L'))
	{
		h = ((127 * word[0]) + (97 * word[1]) + (67 * word[2]) + (41 * word[3]) + (17 * word[4]) + (1 * word[5])) * 41;
	}
	else if ((word[0] == 'm') || (word[0] = 'M'))
	{
		h = ((1 * word[1]) + (3 * word[4]) + (5 * word[3]) + (7 * word[5]) + (11 * word[2]) + (13 * word[0])) * 43;
	}
	else if ((word[0] == 'n') || (word[0] = 'N'))
	{
		h = ((17 * word[1]) + (19 * word[4]) + (23 * word[3]) + (29 * word[5]) + (31 * word[2]) + (37 * word[0])) * 47;
	}
	else if ((word[0] == 'o') || (word[0] = 'O'))
	{
		h = ((41 * word[1]) + (43 * word[4]) + (47 * word[3]) + (53 * word[5]) + (59 * word[2]) + (61 * word[0])) * 53;
	}
	else if ((word[0] == 'p') || (word[0] = 'P'))
	{
		h = ((67 * word[1]) + (71 * word[4]) + (73 * word[3]) + (79 * word[5]) + (83 * word[2]) + (89 * word[0])) * 59;
	}
	else if ((word[0] == 'q') || (word[0] = 'Q'))
	{
		h = ((97 * word[1]) + (101 * word[4]) + (103 * word[3]) + (107 * word[5]) + (109 * word[2]) + (113 * word[0])) * 61;
	}
	else if ((word[0] == 'r') || (word[0] = 'R'))
	{
		h = ((127 * word[1]) + (131 * word[4]) + (137 * word[3]) + (139 * word[5]) + (149 * word[2]) + (151 * word[0])) * 67;
	}
	else if ((word[0] == 's') || (word[0] = 'S'))
	{
		h = ((151 * word[1]) + (113 * word[4]) + (89 * word[3]) + (61 * word[5]) + (37 * word[2]) + (13 * word[0])) * 71;
	}
	else if ((word[0] == 't') || (word[0] = 'T'))
	{
		h = ((149 * word[1]) + (109 * word[4]) + (83 * word[3]) + (59 * word[5]) + (31 * word[2]) + (11 * word[0])) * 73;
	}
	else if ((word[0] == 'u') || (word[0] = 'U'))
	{
		h = ((139 * word[1]) + (107 * word[4]) + (79 * word[3]) + (53 * word[5]) + (29 * word[2]) + (7 * word[0])) * 79;
	}
	else if ((word[0] == 'v') || (word[0] = 'V'))
	{
		h = ((137 * word[1]) + (103 * word[4]) + (73 * word[3]) + (47 * word[5]) + (23 * word[2]) + (5 * word[0])) * 83;
	}
	else if ((word[0] == 'w') || (word[0] = 'W'))
	{
		h = ((131 * word[1]) + (101 * word[4]) + (71 * word[3]) + (43 * word[5]) + (19 * word[2]) + (3 * word[0])) * 89;
	}
	else if ((word[0] == 'x') || (word[0] = 'X'))
	{
		h = ((127 * word[1]) + (97 * word[4]) + (67 * word[3]) + (41 * word[5]) + (17 * word[2]) + (1 * word[0])) * 97;
	}
	else if ((word[0] == 'y') || (word[0] = 'Y'))
	{
		h = ((157 * word[1]) + (163 * word[4]) + (167 * word[3]) + (173 * word[5]) + (179 * word[2]) + (181 * word[0])) * 101;
	}
	else if ((word[0] == 'z') || (word[0] = 'Z'))
	{
		h = ((191 * word[1]) + (193 * word[4]) + (197 * word[3]) + (199 * word[5]) + (211 * word[2]) + (223 * word[0])) * 103;
	}

	return h;
}

// A structure to hold the elements being stored in the HashTable
struct chainBucket {
	bool collision;
	unsigned int Hash;
	List* bucketList = new List;
};

// The HashTable class
class HashTable {
private:

	chainBucket Table[157];

public:

	unsigned int collisions = 0;

	void addToTable(string text);
	bool find(string text);
	void printTable();
};

// A function to add elements to the hashTable
// This is the function that the user actually calls
// both to hash and to add a hash to the table
void HashTable::addToTable(string text)
{
	unsigned int hash = Hash(text), key = Hash(text) % 157;

	if (hash == 0)
	{
		return;
	}
	else if (Table[key].Hash != hash)
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

bool HashTable::find(string text)
{
	bool found = false;
	unsigned int key = Hash(text) % 157;

	if (key == 0)
	{
		return false;
	}
	else
	{
		found = Table[key].bucketList->find(text);
	}

	return found;
}


// Help from lab 10 HashMaps
void HashTable::printTable()
{
	cout << "\nKey:[HASHVAL] Bucket:[<COLLISION?>]\n";
	cout << ">>  LinkedList  \n\n";
	int i = 0;
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
			else
			{
				i++;
			}
			cout << "\n";
		}

	}
	cout << "There were : " << i << " : different hash values and " << collisions << " collisions" << endl;
}

// Bloom Filter
// n = 10000 elements
// m = 1000 "bits"
// k = (n/m)ln2 = 6.9 = 7 hash functions
class BloomFilter
{
private:
	int collection[1000];

public:
	BloomFilter(string x, bool y);
};
BloomFilter::BloomFilter(string text, bool insert = false)
{
	std::hash<string> str_hash;
	std::hash<unsigned int> int_hash;
	string word = text;
	bool present = true;

	if (insert == true)
	{
		for (int i = 0; i < 7; i++)
		{
			collection[(str_hash(word) + (i * int_hash(str_hash(word)))) % 1000] = 1;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (collection[(str_hash(word) + (i * int_hash(str_hash(word)))) % 1000] != 1)
		{
			present = false;
			break;
		}
	}

	if (insert != true)
	{
		if (present)
		{
			cout << "the word " << word << " is likely in the list" << endl;
		}
	}
	if(!present)
	{
		cout << "the word is not in the list" << endl;
	}

	return;
}