// Project 2.cpp : Defines the entry point for the console application.
//


#include "Sort.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	int j = 0, k = 0;
	bool sorted = true;

	// srand() help from university of alaska publication

	srand(time(NULL));

	// QuickSort Testing
	// This test creates 100 vectors of random ints (10 times)
	// each vector is longer than the last starting at length 0
	// each integer is between -1000 and 1000
	// If the function did not sort the vector correctly it prints a statement
	// this statement has the index the error occured at and the number that was
	// not sorted correctly

	// If you really want to test the sorting ability set the bound on j to be 500
	while (k < 10)
	{
		while (j < 100)
		{
			vector<int> vec1;

			for (int k = 0; k <= j; k++)
			{
				vec1.push_back(rand() % 1000);
				vec1.push_back(-1 * rand() % 1000);
			}

			QuickSort(vec1);

			// To see a printout of the testing process uncomment out the following 5 lines.

//			for (int i = 0; i < size(vec1); i++)
//			{
//				cout << vec1[i] << ",  ";
//			}
//			cout << endl << "size : " << vec1.size() << endl;

			for (int i = 0; i < size(vec1); i++)
			{
				if ((i + 1) != size(vec1))
				{
					if (vec1[i] > vec1[i + 1])
					{
						cout << "The value: " << vec1[i] << " was not sorted correctly at index: " << i << endl;
						sorted = false;
					}
				}
			}

			vec1.clear();

			j++;
		}

		j = 0;
		k++;
		cout << "vector1 was sorted (QuickSort): " << boolalpha << sorted << endl;
		sorted = true;
	}

	cout << endl;
	sorted = true;
	j = 0;
	k = 0;

	// MergeSort testing
	// The same testing process is followed as the QuickSort testing

	while (k < 10)
	{
		while (j < 100)
		{
			vector<int> vec2;

			for (int k = 0; k <= j; k++)
			{
				vec2.push_back(rand() % 1000);
				vec2.push_back(-1 * rand() % 1000);
			}

			MergeSort(vec2);

			// To see a printout of the testing process uncomment out the following 5 lines.

//			for (int i = 0; i < vec3.size(); i++)
//			{
//				cout << vec3[i] << ",  ";
//			}
//			cout << endl << "size : " << vec3.size() << endl;

			for (int i = 0; i < size(vec2); i++)
			{
				if ((i + 1) != size(vec2))
				{
					if (vec2[i] > vec2[i + 1])
					{
						cout << "The value: " << vec2[i] << " was not sorted correctly at index: " << i << endl;
						sorted = false;
					}
				}
			}

			vec2.clear();

			j++;
		}
		j = 0;
		k++;
		cout << "vector2 was sorted (MergeSort): " << boolalpha << sorted << endl;
		sorted = true;
	}

	cout << endl;
	sorted = true;
	j = 0;
	k = 0;

	// String Hash Testing
	// alphabet is an array of the alphabet
	// this has test generates a random string by taking
	// characters from alphabet at random indexes
	
	// This test runs 100 times
	// it adds 1000 elements to a hash table of size 157
	// it then prints out the current table with the collisions listed
	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	while (k < 100)
	{
		HashTable table1;
		while (j < 1000)
		{
			string word;

			for (int i = 0; i <= 6; i++)
			{
				word.push_back(alphabet[rand() % 26]);
			}

			table1.addToTable(word);
			j++;
		}

		// If you want to see the current table with the collisions listed
		// uncommnet out the following line
//		table1.printTable();

		j = 0;
		k++;
	}

	j = 0;
	k = 0;

	// BloomFilter Testing
	// This test uses the same word creation as the hash testing
	// this testing runs 100 times
	// it hashes with 7 hash functions to an array of 1000 bits
	// it prints "end run #" at the end of each 100 filters
	while (k < 100)
	{
		while (j < 10)
		{
			string word;

			for (int i = 0; i <= 6; i++)
			{
				word.push_back(alphabet[rand() % 26]);
			}

			j++;

			BloomFilter(word);
		}

		cout << "end run " << k << endl;
		j = 0;
		k++;
	}

	return 0;
}

