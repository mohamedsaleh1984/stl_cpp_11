// STL_CPP_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;



int main()
{

	return 0;
}


/*
	all_of
	------
	Check if every element in the range satisfies the condition.
*/
void all_of()
{
	std::vector<int> v{ 5, 3, 7, 9, 4 };
	auto lambda = [](int i) {
		return i > 1;
	};
	bool allGreaterThanOne = std::all_of(v.begin(), v.end(), lambda);
	std::cout << "All vector elements are greater than 1 " << allGreaterThanOne << endl;
}