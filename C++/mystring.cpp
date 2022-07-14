#include <iostream>
#include <cstring>

using namespace std;

class mystring
{
	char *data;
public:
	mystring();
	mystring(const mystring& rhs);
	mystring(mystring&& rhs);
	mystring& operator=(const mystring& rhs);
	mystring(char* val);
	~mystring();
};

mystring::mystring():data{nullptr}
{
	data = new char[1];
	data[0] = '\0';
}

mystring::mystring(char* val)
{
	if(val != nullptr)
	{
		data = new char[strlen(val) +1];
		strcpy(data,val);
		data[strlen(val)] = '\0';
	}
}

mystring::mystring(const mystring& rhs)
{
	if(strlen(rhs) > 0)
	{
		data = new char[strlen(rhs) +1];
		strcpy(data, rhs.data);
		data[strlen(rhs)] = '\0';
	}
}

mystring& mystring::operator=(const mystring& rhs):mystring(rhs)
{
	return *this;
}

mystring::mystring(mystring&& rhs)
{
	data = rhs.data;
	rhs.data = nullptr;
}

~mystring::mystring()
{
	delete data;
}

int main()
{
	mystring s1("Hello");
	mystring s2(s1);
	mystring *s3;
	mystring s4(s3);
}

