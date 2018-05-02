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
	int j = 0;
	bool sorted = true;

	// srand() help from university of alaska publication

	srand(time(NULL));

	// QuickSort Testing
	// This test creates 100 vectors of random ints
	// each vector is longer than the last starting at length 0
	// each integer is between 1 and 100
	// the success of the sort can be printed out by uncommenting 5 lines
	
	// If you really want to test the sorting ability set the bound on j to be 500

	while (j < 100)
	{
		vector<int> vec1;

		for (int k = 0; k <= j; k++)
		{
			vec1.push_back(rand() % 1000);
		}

		QuickSort(vec1);

		// To see a printout of the testing process uncomment out the following 5 lines.

		for (int i = 0; i < size(vec1); i++)
		{
			cout << vec1[i] << ",  ";
		}
		cout << endl << "size : " << vec1.size() << endl;

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

	cout << "vector1 was sorted : " << boolalpha << sorted << endl << endl;

	sorted = true;
	j = 0;

	// Another QuickSort test 

	while (j < 100)
	{
		vector<int> vec2;

		for (int k = 0; k <= j; k++)
		{
			vec2.push_back(rand() % 100);
		}

		QuickSort(vec2);

		// To see a printout of the testing process uncomment out the following 5 lines.

//		for (int i = 0; i < vec2.size(); i++)
//		{
//			cout << vec2[i] << ",  ";
//		}
//		cout << endl << "size : " << vec2.size() << endl;

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

	cout << "vector2 was sorted : " << boolalpha << sorted << endl << endl;

	sorted = true;
	j = 0;

	// MergeSort testing
	// The same testing process is followed as the QuickSort testing

	while (j < 100)
	{
		vector<int> vec3;

		for (int k = 0; k <= j; k++)
		{
			vec3.push_back(rand() % 1000);
		}

		MergeSort(vec3);

		// To see a printout of the testing process uncomment out the following 5 lines.

//		for (int i = 0; i < vec3.size(); i++)
//		{
//			cout << vec3[i] << ",  ";
//		}
//		cout << endl << "size : " << vec3.size() << endl;

		for (int i = 0; i < size(vec3); i++)
		{
			if ((i + 1) != size(vec3))
			{
				if (vec3[i] > vec3[i + 1])
				{
					cout << "The value: " << vec3[i] << " was not sorted correctly at index: " << i << endl;
					sorted = false;
				}
			}
		}

		vec3.clear();

		j++;
	}

	cout << "vector3 was sorted : " << boolalpha << sorted << endl << endl;

	sorted = true;
	j = 0;

	// More MergeSort Testing

	while (j < 100)
	{
		vector<int> vec4;

		for (int k = 0; k <= j; k++)
		{
			vec4.push_back(rand() % 100);
		}

		MergeSort(vec4);

		// To see a printout of the testing process uncomment out the following 5 lines.

//		for (int i = 0; i < size(vec4); i++)
//		{
//			cout << vec4[i] << ",  ";
//		}
//		cout << endl << "size : " << size(vec4) << endl;

		for (int i = 0; i < size(vec4); i++)
		{
			if ((i + 1) != size(vec4))
			{
				if (vec4[i] > vec4[i + 1])
				{
					cout << "The value: " << vec4[i] << " was not sorted correctly at index: " << i << endl;
					sorted = false;
				}
			}			
		}

		vec4.clear();

		j++;
	}

	cout << "vector4 was sorted : " << boolalpha << sorted << endl << endl;

	// String Hash Testing

	j = 0;

	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	while (j < 100)
	{
		HashTable table;
		string word;

		for (int i = 0; i <= 6; i++)
		{
			word.push_back(alphabet[rand() % 26]);
		}

		table.addToTable(word);
		cout << "\nword added : " << word << "\n";
		table.printTable();
		j++;
	}




    return 0;
}

