#include <iostream>
using namespace std;

constexpr double my_sqrt(const double val){return val*val;}

int main_constexpr()
{
	const double d1 =19.33;
	constexpr double sq = my_sqrt(d1);
	
	double v = 12.333;
	//constexpr double err = my_sqrt(v); // ERROR, "v" is not const
	
	return 0;
}