#include "pch.h"
#include <iostream>
using namespace std;

void any_of();
void all_of();
void none_of();
void for_each();
void find();
void find_if();


int main()
{
	any_of();
	all_of();	
	none_of();
	for_each();
	find();
	find_if();

	return 0;
}

/*
	find_if
	Find the first item that satisfies a condition.
*/
void find_if() {
	std::vector<int> v{ 5, 3, 7, 9, 4 };

	auto lambda = [](int i) { return i > 6; }; 
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), lambda); 
	int firstElementGreaterThanSix = *it; // 7
	cout << firstElementGreaterThanSix << endl;
}

/*
	find
	----
	Find an item in a given range.
*/
void find() {
	std::vector<int> v{ 5, 3, 7, 9, 4 };

	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
	cout << "location (index)::" << it-v.begin() << endl;
	cout << "Value ::" << *it << endl;
}

/*
	foreach
	-------
	Does something for each item in a range.
*/
void for_each() {
	std::vector<int> v{ 5, 3, 7, 2, 1 }; 
	auto lambda = [](int i) { std::cout << i << " "; };
	auto add_seven_print = [](int elem) { std::cout << elem + 7 << " "; };
	// Prints each element in the container.
	std::for_each(v.begin(), v.end(), lambda); 
	cout << endl;
	// Adding 7 and print each element in the container.
	std::for_each(v.begin(), v.end(), add_seven_print);
	cout << endl;
}

/*
	none_of
	-------
	Check if none of the elements in the range satisfies the condition.
*/
void none_of() {
	std::vector<int> v{ 5, 3, 7, 9, 4 }; 
	auto lambda = [](int i) { return i > 10; };
	bool noneGreaterThanTen = std::none_of(v.begin(), v.end(), lambda); // true
	std::cout << "All vector not greater than 10 :" << noneGreaterThanTen << endl;
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