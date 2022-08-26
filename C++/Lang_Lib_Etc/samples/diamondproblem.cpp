#include <iostream>
using namespace std;

struct A
{
	void display()
	{
		cout << "I'm from A\n";
	}
};
struct B : virtual public A{};
struct C : virtual public A{};

struct D :public B, public C
{
	void hello()
	{
		display(); //remove 'virtual' during inheriting A in B and C to see the effect
	}
};

int main_diamondproblem()
{
	D obj;
	obj.hello();
	
	return 0;
}