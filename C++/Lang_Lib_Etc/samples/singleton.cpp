#include <iostream>
using namespace std;
class SingleIns
{
	SingleIns() {}
	SingleIns(const SingleIns&) = delete;
	void operator=(const SingleIns&) = delete;
public:
	static SingleIns& getInstance()
	{
		static SingleIns theOne;
		return theOne;
	}
	int count{};
};

void changeS(SingleIns& s)
{
	s.count = 90;
}

int main_singleton()
{
	SingleIns &obj = SingleIns::getInstance();
	cout << obj.count << endl;
	changeS(obj);
	cout << obj.count << endl;
	
	return 0;
}
