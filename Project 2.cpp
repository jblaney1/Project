// Project 2.cpp : Defines the entry point for the console application.
// Joshua Blaney
// Cosci 2030
// May 3, 2018


#include "Sort.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	int j = 0, k = 0, pass = 0, fail = 0;
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
	// At the end of the testing a statement of pass/fail is printed

	// If you really want to test the sorting ability set the bound on j to be 500
	while (k < 100)
	{
		while (j < 100)
		{
		vector<int> vec1;

		for (int m = 0; m <= j; m++)
		{
		vec1.push_back(rand() % 1000);
		vec1.push_back(-1 * rand() % 1000);
		}

		QuickSort(vec1);

		int len = size(vec1);
		// To see a printout of the testing process uncomment out the following 5 lines.

//			for (int i = 0; i < len; i++)
//			{
//				cout << vec1[i] << ",  ";
//			}
//			cout << endl << "size : " << len << endl;

		for (int i = 0; i < len; i++)
		{
			if ((i + 1) != len)
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

		if (sorted)
		{
			pass++;
		}
		k++;
		j = 0;
		sorted = true;
	}

	cout << "QuickSort() passed " << pass << "/" << k << " tests" << endl << endl;
	sorted = true;
	j = 0;
	k = 0;
	pass = 0;

	// MergeSort testing
	// The same testing process is followed as the QuickSort testing

	while (k < 10)
	{
		while (j < 100)
		{
			vector<int> vec2;

			for (int m = 0; m <= j; m++)
			{
				vec2.push_back(rand() % 1000);
				vec2.push_back(-1 * rand() % 1000);
			}

			MergeSort(vec2);
			int len = size(vec2);
			// To see a printout of the testing process uncomment out the following 5 lines.

//			for (int i = 0; i < len; i++)
//			{
//				cout << vec2[i] << ",  ";
//			}
//			cout << endl << "size : " << len << endl;

			for (int i = 0; i < len; i++)
			{
				if ((i + 1) != len)
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

		if (sorted)
		{
			pass++;
		}
		k++;
		j = 0;
		sorted = true;
	}

	cout << "MergeSort() passed " << pass << "/" << k << " tests" << endl << endl;
	sorted = true;

	j = 0;
	k = 0;
	pass = 0;

	// Binary Search Testing
	// This test runs 100 times
	// this test creates 100 vectors of growing length starting at 0
	// this test creates a value to test for and checks it against the values
	// being pushed back into the vector
	// if the two values match a boolean value is set to true
	// after the search is complete the result is stored in a boolean value
	// if the search was supposed to be successfull sf is incremented
	// if the search was successfull s is incremented
	// if the binary search finds all of the correct values it passes the test
	// passing the test is kept track of through a pass integer that increments
	// when s == sf
	// when the testing is finished a statement of the pass/fail is printed
	while (k < 50)
	{
		int f = 0, sf = 0;

		while (j < 100)
		{
			vector<int> vec3;
			int num1, num2;
			bool shouldFind = false;
			num1 = rand() % 100;

			for (int m = 0; m < 100; m++)
			{
				num2 = rand() % 100;

				if (num1 == num2)
				{
					shouldFind = true;
				}

				vec3.push_back(num2);
			}

			bool found = BinarySearch(vec3, num1);

			if (shouldFind)
			{
				sf++;
			}

			if (found)
			{
				f++;
			}

			vec3.clear();
			j++;
		}

		if (sf == f)
		{
			pass++;
		}
		j = 0;
		k++;
	}

	cout << "BinarySearch() passed " << pass << "/" << k << " tests" << boolalpha << endl << endl;
	pass = 0;
	k = 0;
	j = 0;

	// String Hash Testing
	// alphabet is an array of the alphabet
	// this test generates a random string by taking
	// characters from alphabet at random indexes

	// This test runs 100 times
	// it adds 157 elements to a hash table of size 157
	// it can then print out the current table with the collisions listed
	// at the end of the tesing a statement is printed with the number of
	// correctly hashed strings and the number of fails
	// it also states the number of tables and the number of collissions

	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	bool added = false;
	int collide = 0;
	int sf = 0;

	while (k < 100)
	{
		HashTable table1;

		while (j < 10)
		{
			string word1, word2;

			for (int i = 0; i <= 6; i++)
			{
				word1.push_back(alphabet[rand() % 26]);
			}

			if (rand() % 2 == 1)
			{
				for (int i = 0; i <= 6; i++)
				{
					word2.push_back(word1[i]);
				}
				sf++;
			}

			table1.addToTable(word1);

			added = table1.find(word2);

			if (added)
			{
				pass++;
			}
			else
			{
				fail++;
			}
			j++;
		}
		// To seee a printout of each table with collided words
		// uncomment out the following line
//		table1.printTable();
		j = 0;
		k++;
		collide = collide + table1.collisions;
	}
	
	cout << "Hash() found " << pass << " strings and should have found " << sf <<" strings "
		<< "\n# ints searched for but not found in the table: " << fail
		<< "\n# Tables: " << k << " tables \n# Collisions: " << collide << " collisions" << endl << endl;

	j = 0;
	k = 0;
	pass = 0;

	// BloomFilter Testing
	// This test uses the same word creation as the hash testing
	// this testing runs 50 times
	// it hashes with 7 hash functions to an array of 1000 bits
	// it only tells if the word may be or is definitely not in the list
	// there is no pass fail written for this function

	while (k < 50)
	{
		string word;

		for (int i = 0; i <= 6; i++)
		{
			word.push_back(alphabet[rand() % 26]);
		}
		if (k < 10)
		{
			cout << "Adding " << word << "\n";
			BloomFilter(word, true);
			k++;
		}
		else
		{
			bool addMe = rand() % 2;
			if (!addMe) {
				cout << "Checking " << word << endl;
			}
			else
			{
				cout << "Adding " << word << "\n";
			}
			BloomFilter(word, addMe);
			k++;
		}
	}

	return 0;
}