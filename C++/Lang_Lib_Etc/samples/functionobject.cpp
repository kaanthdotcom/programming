#include <iostream>
using namespace std;

template<typename T>
class Less_than
{
private:
	const T val;
public:
	Less_than(const T& v):val(v){}
	bool operator()(const T& v)const {return v<val;}
};

void test()
{
		Less_than<int> a{20};
		Less_than<string> b{"something"};
		
		cout << a(10) << endl;
		cout << b("something") << endl;
}

int main_functionobject()
{
	test();
	
	return 0;
}