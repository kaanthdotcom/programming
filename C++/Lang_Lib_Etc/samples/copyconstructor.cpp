#include <iostream>
#include <string>

class mystring
{
	char* data{nullptr};
public:
	mystring():data(new char('\0'))
	{

	}
	mystring(const char* str)
	{
		if (str == nullptr)
			return;
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}

	mystring(const mystring& rhs)
	{
		data = new char[strlen(rhs.data) + 1];
		strcpy(data, rhs.data);
	}
	
	mystring& operator=(const mystring& rhs)
	{
		if (this == &rhs)
			return *this;

		delete[] data;
		data = new char[strlen(rhs.data) + 1];
		strcpy(data, rhs.data);

		return *this;
	}

	~mystring()
	{
		delete[] data;
	}
};

int main_copyconstructor()
{
	mystring name("hello");
	mystring aname(name);

	mystring bname("hey");
	bname = aname;

	bname = bname;

	return 0;
}