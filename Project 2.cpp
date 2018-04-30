// Project 2.cpp : Defines the entry point for the console application.
//


#include "Sort.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <string>


using namespace std;

int main()
{
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	vector<int> vec4;



	for (int i = 0; i < 100; i++)
	{
		vec1.push_back(rand() % 100);
		vec2.push_back(rand() % 1000);
	}

	vec3 = vec1;
	vec4 = vec2;

	QuickSort(vec1);
	QuickSort(vec2);
	MergeSort(vec3);
	MergeSort(vec4);
	
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << ",  ";
	}
	cout << endl << "size : " << vec1.size() << endl;
	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3[i] << ",  ";
	}
	cout << endl << "size : " << vec3.size() << endl;
	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << ",  ";
	}
	cout << endl <<  "size : " << vec2.size() << endl;
	for (int i = 0; i < vec4.size(); i++)
	{
		cout << vec4[i] << ",  ";
	}
	cout << endl << "size : " << vec4.size() << endl;

	cout << "vec1 0?	" << BinarySearch(vec1, 0) << endl;
	cout << "vec1 1?	" << BinarySearch(vec1, 1) << endl;
	cout << "vec1 2?	" << BinarySearch(vec1, 2) << endl;
	cout << "vec1 3?	" << BinarySearch(vec1, 3) << endl;
	cout << "vec1 4?	" << BinarySearch(vec1, 4) << endl;
	cout << "vec1 5?	" << BinarySearch(vec1, 5) << endl;
	cout << "vec1 6?	" << BinarySearch(vec1, 6) << endl;
	cout << "vec1 7?	" << BinarySearch(vec1, 7) << endl;
	cout << "vec1 8?	" << BinarySearch(vec1, 8) << endl;
	cout << "vec1 9?	" << BinarySearch(vec1, 9) << endl;
	cout << "vec2 0?	" << BinarySearch(vec2, 0) << endl;
	cout << "vec2 1?	" << BinarySearch(vec2, 1) << endl;
	cout << "vec2 2?	" << BinarySearch(vec2, 2) << endl;
	cout << "vec2 3?	" << BinarySearch(vec2, 3) << endl;
	cout << "vec2 4?	" << BinarySearch(vec2, 4) << endl;
	cout << "vec2 5?	" << BinarySearch(vec2, 5) << endl;
	cout << "vec2 6?	" << BinarySearch(vec2, 6) << endl;
	cout << "vec2 7?	" << BinarySearch(vec2, 7) << endl;
	cout << "vec2 8?	" << BinarySearch(vec2, 8) << endl;
	cout << "vec2 9?	" << BinarySearch(vec2, 9) << endl;

    return 0;
}

