#include <iostream>
using namespace std;

int main_smartpointers()
{
	int x = 10;
	std::unique_ptr<int> p = std::make_unique<int>(x);

	return 0;
}