#include <iostream>
using namespace std;

int main_static_assert()
{
	constexpr double somevalue{9.11};
	double anothervalue{21.33};
	constexpr double thevalue { 2.44 * somevalue};
	
	static_assert(somevalue<thevalue, "expected");
	//static_assert(anothervalue>thevalue, "not expected");//this gives compile-time error
	if(anothervalue > thevalue) //this will pass
		cout << "cool";
	
	return 0;
}