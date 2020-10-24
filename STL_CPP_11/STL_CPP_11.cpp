#include "pch.h"
#include <iostream>
using namespace std;
void any_of();
void all_of();

int main()
{
	any_of();
	all_of();	



	return 0;
}

/*
	any_of
	------
	Check if any element in the range satisfies the condition.
*/
void any_of()
{
	std::vector<int> v{ 5, 3, 7, 9, 4, 0 };
	auto lambda = [](int elem) {
		return elem == 0;
	};

	bool anyIsZero = std::any_of(v.begin(), v.end(), lambda);

	cout << "Any of vector\'s elements is 0 :" << anyIsZero << endl;
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
	std::cout << "All vector elements are greater than 1 :" << allGreaterThanOne << endl;
}