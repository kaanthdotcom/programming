#include <iostream>

using namespace std;

int print(){return 0;}

template<typename x, typename... types>
int print(x v, types... args)
{
	cout << v << endl;
	print(args...);
	return sizeof...(args);
}

int main_variadic_template()
{
	print(12,"pop");

	return 0;
}