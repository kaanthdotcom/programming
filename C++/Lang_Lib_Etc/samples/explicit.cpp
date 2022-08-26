#include <iostream>

using namespace std;

class box
{
public:
	box(int x) {}
	box() {}
};
void somefunc(box b){}

int main_explicit()
{
	box b;
	somefunc(b);
	somefunc(10);//making box(int) constructor as 'explicit' will disallow this implicit type conversions
	somefunc(box(30));

	return 0;
}