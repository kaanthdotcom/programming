/*
type conversion
value truncation
*/


#include <iostream>

using namespace std;

class box
{
public:
	box(int x)
	{
		cout << "int x " << x << "\n";
	}
	box(int x, int y)
	{
		cout << "int x " << x <<", " << y << "\n";
	}
	box() { cout << "()\n"; }
};

void somefunc(box b, box x)
{
	cout << "somfunc(2)\n";
}
void somefunc(box b)
{
	cout << "somfunc(1)\n";
}

int main_explicit()
{
	box b;
	somefunc(b);
	//somefunc(10.5);//making box(int) constructor as 'explicit' will disallow this implicit type conversions
	//somefunc(2, 5);
	somefunc(box(2, 5));//->#20,#31
	//somefunc((21, 15), (211, 115));
	//somefunc({ 22, 16 }, { 212, 116 });
	//somefunc({ 28, 18 });
	somefunc(box(30.5));

	return 0;
}