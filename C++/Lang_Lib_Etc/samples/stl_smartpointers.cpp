#include <iostream>

using namespace std;
class Box
{
public:
	void show()
	{
		cout << "Show()\n";
	}
};

int main_smartpointers()
{
	unique_ptr<Box> ub1(new Box);
	cout << ub1.get() << endl;

	unique_ptr<Box> ub2 = move(ub1);
	cout << ub1.get() << endl;
	cout << ub2.get() << endl;

	shared_ptr<Box> sp(new Box);
	shared_ptr<Box> sb = sp;
	cout << sp.use_count();

	return 0;
}

