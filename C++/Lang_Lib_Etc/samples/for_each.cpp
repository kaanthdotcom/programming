/*
namespace std {
	template <typename Iterator, typename Operation>
	Operation for_each (Iterator act, Iterator end, Operation op)
	{
		while (act != end) { // as long as not reached the end
			op(*act); // - call op() for actual element
			++act; // - move iterator to the next element
		}
		return op;
	}
}
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

bool printLen(string& name)
{
	cout << name << ": " << name.length() << endl;
	return false;
}

template<typename T>
struct Print
{
	void operator()(const T& v)
	{
		cout << v << endl;
	}		 
};

int main_for_each()
{
	vector<string> names{"Praveen", "Rajesh", "Varun", "Murali"};
	for_each(names.begin(), names.end(), printLen);//normal function
	cout << endl;
	
	
	for_each(names.cbegin(), names.cend(), Print<string>());//function object */
	
	for_each(names.cbegin(), names.cend(), [](const string& n){
		cout << n << ",";
	});	
	
	cout << endl;
	
	vector<string> lastnames{"Ambuja", "Pipalla", "Komati", "Tanneeru"};
	for_each(names.begin(), names.end(), [=](string& n){
		static int i;
		n += " " + lastnames[i++];
	});
	
	cout << endl;
	copy(names.cbegin(), names.cend(), ostream_iterator<string>(cout, ","));

	return 0;
}