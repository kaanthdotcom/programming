/*
find():
template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
	static_assert(Input_iterator<Iter>(),"find() requires an input iterator");
	static_assert(Equality_comparable<Value_type<Iter>,Val>(),"find()'s iterator and value arguments must match");
	while (b!=e) {
		if (*b==x) return b;
		++b;
	}
	return b;
}
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main_find() {
	list<int> values{ 20,44,12,456,23,655,6,902,30,20,87,4325,65, 68, 23 };
	values.insert(values.begin(), 10);

	cout << "List as it is:\n";
	copy(values.cbegin(), values.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	int search_elem{ 456 };
	list<int>::iterator it = find(values.begin(), values.end(), search_elem);
	if (it != values.end()) {
		int dst = distance(values.begin(), it) + 1;
		cout << search_elem << " is found at " << dst << " position\n";
	}
	cout << endl;

	//sort and print the list
	values.sort();
	for (auto x : values)
		cout << x << " ";
	cout << endl;

	//print all items between [30 and 902)
	list<int>::iterator it1, it2;
	it1 = find(values.begin(), values.end(), 30);
	if (it1 != values.cend())
		it2 = find(it1, values.end(), 902);
	if (it1 != values.end() && it2 != values.end())
		copy(it1, it2, ostream_iterator<int>(cout, " "));

	return 0;
}