//source: https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170
//https://www.stroustrup.com/C++11FAQ.html

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

struct mystring
{
	mystring() :data{ }
	{
		std::cout << "def cons\n";
	};
	mystring(const mystring& rhs)
	{
		std::cout << "copy cons: " << rhs.data << std::endl;
		data = new char[strlen(rhs.data) + 1];
		strcpy(data, rhs.data);
	}
	mystring& operator=(const mystring& rhs)
	{
		std::cout << "copy assignment cons: " << rhs.data << std::endl;;
		if (this == &rhs)
			return *this;
		delete[] data;

		data = new char[strlen(rhs.data) + 1];
		strcpy(data, rhs.data);

		return *this;
	}
	mystring(mystring&& rhs):data{rhs.data}
	{
		std::cout << "move cons: " << rhs.data << std::endl;
		*this = std::move(rhs);
		rhs.data = nullptr;
	}
	mystring operator=(mystring&& rhs)
	{
		std::cout << "move assg: " << rhs.data << std::endl;
		if (this == &rhs)
			return *this;
		delete[] data;
		
		data = rhs.data;
		rhs.data = nullptr;

		return *this;
	}
	explicit mystring(const char* str)
	{
		std::cout << "one arg cons\n";
		data = nullptr;
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}
	~mystring()
	{
		std::cout << "def destr\n";
		delete[] data;
	}
private:
	char* data{nullptr};
};
//ostream& operator<<(const mystring& rhs, ostream& os)
//{
//
//}

template<typename sometype>
void moveswap(sometype a, sometype b)
{
	sometype tmp;
	tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

template<typename sometype>
void copyswap(sometype a, sometype b)
{
	sometype tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	mystring v{"This is first text message"};
	mystring v1{ "This is second text message" };
	
	cout << "starting copyswap\n";
	copyswap(v, v1);

	cout << "\nstarting moveswap\n";
	moveswap(v, v1);


	/*v.push_back(mystring("first"));
	v.push_back(mystring("second"));*/

	return 0;
}