/*
template<typename _IIter, typename _Predicate>
_IIter
find_if(_IIter, _IIter, _Predicate);

what is a Predicate?
1. Any function that returns a bool or similar type
2. Any functor that has overloaded operator() returning bool
3. Any lambda expression that returns bool 
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

#define PRINTALL for(auto a: phone_book) cout << a.first << " - " << a.second << endl;

using namespace std;

bool pred1(const pair<long,string>& p)
{
	cout << p.second << endl;
	return false;
}

struct pred2
{
	bool operator()(const pair<long,string>& s){
		cout << s.second << endl;
		return false;
	}
};

int main_find_if()
{
	map<long, string> phone_book {{9140, "Hyderabad"}, {9180, "Bangalore"}};
 	phone_book[9144] = "Chennai";
	phone_book.insert({9122,"Mumbai"});
	
	PRINTALL;
	cout << endl;
	
	auto it = phone_book.find(9144);
	if(it != phone_book.end())
		it->second = "Madras";
	
	PRINTALL;
	cout << endl;
	
	find_if(phone_book.begin(), phone_book.end(), pred1);
	cout << endl;
	
	find_if(phone_book.begin(), phone_book.end(), pred2());
	cout << endl;
	
	find_if(phone_book.begin(), phone_book.end(),[](const pair<long,string> &p)->bool
	{
		cout << p.second << endl;
		return false;
	});
	cout << endl;
	
	/* if(it != phone_book.end())
		it->second = "Chennai";
	PRINTALL;
	
	auto it2 = find_if(phone_book.begin(), phone_book.end(),[](const pair<long,string> &p)->bool
	{
		return (p.second.length() > 6);
	});
	if(it2 != phone_book.end())
		cout << it2->first << "," << it2->second; */


	return 0;
}