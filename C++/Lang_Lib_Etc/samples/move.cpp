//source: https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170

#include <iostream>
#include <vector>

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
	mystring(mystring&& rhs)
	{
		std::cout << "move cons: " << rhs.data << std::endl;
		*this = std::move(rhs);
	}
	mystring operator=(mystring&& rhs)
	{
		std::cout << "move assigment cons: " << rhs.data << std::endl;
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

int main_move()
{
	std::vector<mystring> v;
	v.push_back(mystring("first"));
	v.push_back(mystring("second"));

	return 0;
}