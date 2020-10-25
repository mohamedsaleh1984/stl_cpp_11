#include "pch.h"
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
void count();
void count_if();
void mismatch();
void equal();
void is_permutation();
void search();
void search_n();
void lexicographical_compare();
void copy();
void copy_n();
void copy_if();
void copy_backward();
void move();

//vector of Integers Iterator.
typedef vector<int>::iterator vec_int32_itr;
//vector of Integers
typedef vector<int> vec_int32;
//vector of Chars
typedef vector<int> vec_char;
//vector of Chars Iterator.
typedef vector<char>::iterator vec_char_itr;

int main(void)
{
	std::cout << std::boolalpha;

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
	count();
	count_if();
	mismatch();
	equal();
	is_permutation();
	search();
	search_n();
	lexicographical_compare();
	copy();
	copy_n();
	copy_if();
	copy_backward();
	move();

	return 0;
}
/*
	
*/
void move() {
	
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2(4);
	std::vector<int>::iterator it = std::move(v1.begin(), v1.end(), v2.begin());
	while (it != v2.end()) {
		cout << *it;
		it++;
	}

	// v1 is { 1 2 3 4 } (It just happens to be unchanged.)
	// v2 is { 1 2 3 4 }
	// 'it' points to the element after 4 in v2.

}
void print_fun_heading(string funName) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~ " << funName << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void print_fun_tailing() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


/*
copy_backward
-------------
Copy the elements from one range into another, starting from the back elements and going to the front.
*/
void copy_backward() {
	vec_int32 v1{ 1, 2, 3, 4 };
	//init a vector with 4 elements
	vec_int32 v2(2);
	vec_int32_itr it = std::copy_backward(v1.begin()+2 , v1.end(), v2.end());

	cout << "view copied items backward.. ";
	auto print = [](int elem) { std::cout << elem << " "; };
	// Prints each element in the container.
	std::for_each(v2.begin(), v2.end(), print);
	cout << endl;
}

/*
	copy_if
	-------
	Copy elements from one range into another if the condition we specify is met.
*/
void copy_if() {
	std::vector<int> v1{ 1, 2, 3, 4 };
	std::vector<int> v2(2); 
	auto lambdaIsEven = [](int i) {
		return i % 2 == 0; 
	};
	auto print = [](int i) {
		cout << i << " ";
	};

	std::vector<int>::iterator it = std::copy_if(v1.begin(), v1.end(), v2.begin(), lambdaIsEven);
	cout << "after copied even numbers" << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
}
/*
	copy_n
	------
	Copy the first n elements from one range into another.
*/
void copy_n() {
	vec_int32 myints { 10,20,30,40,50,60,70 };
	vec_int32 myvector;

	myvector.resize(3);   // allocate space for 3 elements
	
	std::copy_n(myints.begin(),3, myvector.begin());

	std::cout << "myvector contains:";

	auto print = [](int elem) {
		cout << elem << " ";
	};

	for_each(myvector.begin(), myvector.end(), print);

	//another example
	std::copy_n(myints.begin()+2, 3, myvector.begin());
	cout << endl;
	std::cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), print);
	std::cout << '\n';
/*	*/
}

/*
	copy
	----
	Copy the elements from one range into another.
*/
void copy() {
	vec_int32 v1{ 1, 2, 3, 4 };
	//init a vector with 4 elements
	vec_int32 v2(3);

	vec_int32_itr it = std::copy(v1.begin()+1, v1.end(), v2.begin());// v2 is { 1 2 3 4 }

	cout << "view copied items.. ";
	auto print = [](int elem) { std::cout << elem << " "; };
	// Prints each element in the container.
	std::for_each(v2.begin(), v2.end(), print);
	cout << endl;
}

/*
	lexicographical_compare
	------------------------
	Lexographically compare two items to find out which is ‘smaller’.
*/
void lexicographical_compare() {
	char foo[] = "Apple";
	char bar[] = "apartment";

	auto mycomp = [](char c1,char c2) {
		return std::tolower(c1) < std::tolower(c2);
	};

	

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
	std::cout << '\n';


}

/*
	search_n
	--------
	find number of consequtive occurances. 
*/
void search_n() {
	std::vector<char> v{ 'e', 's', 't', 'e', 'e', 'm' };

	std::vector<char>::iterator it = std::search_n(v.begin(), v.end(), 2, 'e');
	// Points to the 'e' after the 't'.
	if (it != v.end())
		std::cout << "two es found at position " << (it - v.begin()) << '\n';
	else
		std::cout << "match not found\n";
}

/*
	Search range for subsequence
	------
	Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2),
	and returns an iterator to its first element, or last1 if no occurrences are found.
*/
void search() {
	std::vector<int> haystack;

	// set some values:        haystack: 10 20 30 40 50 60 70 80 90
	for (int i = 1; i < 10; i++) haystack.push_back(i * 10);

	// using default comparison:
	int needle1[] = { 40,50,60,70 };
	std::vector<int>::iterator it;
	it = std::search(haystack.begin(), haystack.end(), needle1, needle1 + 4);

	if (it != haystack.end())
		std::cout << "needle1 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle1 not found\n";

	// using predicate comparison:
	int needle2[] = { 20,30,50 };

	auto mypredicate = [](int i, int j) {
		return (i == j);
	};

	it = std::search(haystack.begin(), haystack.end(), needle2, needle2 + 3, mypredicate);

	if (it != haystack.end())
		std::cout << "needle2 found at position " << (it - haystack.begin()) << '\n';
	else
		std::cout << "needle2 not found\n";
}

/*
	is_permutation
	--------------
	Check if a range is a permutation of another.
*/
void is_permutation() {
	vec_char v1{ 'g', 'o', 'd' };
	vec_char v2{ 'd', 'o', 'g' };

	bool isPermutation = std::is_permutation(v1.begin(), v1.end(), v2.begin());

	cout << "Are the vectors isPermutation of each others :: " << isPermutation << endl;
}


/*
	equal
	-----
	Check if the elements in two ranges are equal.
*/
void equal() {
	vec_int32 v1{ 5, 4, 6 };
	vec_int32 v2{ 5, 4, 6 };
	bool isEqual = std::equal(v1.begin(), v1.end(), v2.begin()); // true
	cout << "Are the vectors equal :: " << isEqual << endl;
}
/*
	mismatch
	--------
	Finds the first occurrence where two rangers differ
*/
void mismatch() {
	std::vector<int> v1{ 5, 3, 7, 9 };
	std::vector<int> v2{ 5, 3, 2, 9 };

	pair<vec_int32_itr, vec_int32_itr> p = std::mismatch(v1.begin(), v1.end(), v2.begin());

	int element1 = *p.first; // 7
	int element2 = *p.second; // 2

	cout << "The start elements where the two vectors are not matching :: " << element1 << ", " << element2 << endl;
}

/*
	count_if
	-------
	Count the number of occurrences satisfying the lambda function.
*/
void count_if() {
	std::vector<int> v{ 5, 3, 7, 2, 1 };
	auto lambda = [](int i) { return i > 2; };
	int count = count_if(v.begin(), v.end(), lambda);
	cout << "Number of elements greater than 2 :: " << count << endl;
}
/*
	count
	-----
	count the occurrences of specific element in a collection.
*/
void count() {
	std::vector<int> v{ 5, 3, 7, 9, 3, 4 };

	int countOfThree = std::count(v.begin(), v.end(), 3); // 2
	cout << "occurrences of 3 is :: " << countOfThree << endl;
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
	cout << "location (index):: " << it - v.begin() << endl;
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