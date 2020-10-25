#include "pch.h"
#include <iostream>
using namespace std;

void any_of();
void all_of();
void none_of();
void for_each();
void find();
void find_if();
void find_if_not();
void find_end();
void findfirst_of();
void adjacent_find();

int main()
{
	any_of();
	all_of();	
	none_of();
	for_each();
	find();
	find_if();
	find_if_not();
	find_end();
	findfirst_of();
	adjacent_find();

	return 0;
}


/*
	adjacent_find
	-------------
	Find the first occurrence of two consecutive elements that match in a range. (Ex. The “cc” in “accentt”.)
*/
void adjacent_find() {

	std::string s = "accentt";
	std::string::iterator it = std::adjacent_find(s.begin(), s.end()); // Points to the first 'c'
	if (it == s.end())
		cout << "Not found..";
	else
		cout << "location (index):: " << it - s.begin() << endl;
}

/*
	findfirst_of
	-----------
	find the first occurence of a sequence in that range.
*/
void findfirst_of() {
	std::string s = "moo_cookies";
	std::string t = "oo"; 
	std::string::iterator it = std::find_first_of(s.begin(), s.end(), t.begin(), t.end());
	if (it == s.end())
		cout << "Not found..";
	else
		cout << "location (index):: " << it - s.begin() << endl;
}
/*
	find_end
	--------
	find the last occurence of a sequence in that range
*/
void find_end() {
	std::string s = "moo_cookies";
	std::string t = "kies"; 
	std::string::iterator it = std::find_end(s.begin(), s.end(), t.begin(), t.end());
	if (it == s.end())
		cout << "Not found..";
	else
		cout << "location (index):: " << it - s.begin() << endl;
}

/*
	find_if_not
	Find the first item that does not satisfy a condition.
*/
void find_if_not()
{
	std::vector<int> v{ 5, 3, 7, 9, 4 };
	auto lambda = [](int i) {
		return i > 6; 
	}; 
	
	std::vector<int>::iterator it = std::find_if_not(v.begin(), v.end(), lambda);
	int firstElementLessThanSix = *it; // 5
	cout << "first element less than 6: " << firstElementLessThanSix << endl;
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
	cout << "first element greater than 6: " << firstElementGreaterThanSix << endl;
}

/*
	find
	----
	Find an item in a given range.
*/
void find() {
	std::vector<int> v{ 5, 3, 7, 9, 4 };

	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 3);
	cout << "location (index):: " << it-v.begin() << endl;
	cout << "Value :: " << *it << endl;
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
	std::cout << "All vector not greater than 10 : " << noneGreaterThanTen << endl;
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