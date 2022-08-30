#include <iostream>
#include <string>
#include <ostream>

using namespace std;

class Point
{
	double x{}, y{};
public:
	Point(const double b, const double a) :x{ a }, y{ b }{}
	Point operator++(int a)//postfix
	{
		Point t{*this};
		++(*this);
		return (t);
	}
	Point& operator++()
	{
		Point &t = *this;
		++(t.x); ++(t.y);
		return (t);
	}

	Point operator+(const Point& P)
	{
		Point t{P};
		t.x += x;
		t.y += y;
		return t;
	}

	friend ostream& operator<<(ostream&, const Point&);
};
ostream& operator<<(ostream& os, const Point& v)
{
	os << v.x << "," << v.y;
	return os;
}

int main_operatoroverloading()
{
	Point p{ 1.1, 1.1 };
	Point p1{ p };
	cout << p << "\n" << p1 << endl;
	cout << p++ << endl;
	cout << ++p1 << endl;
	cout << "After incement\n";
	cout << p << "\n" << p1 << endl;
	Point p2 = p + p1;//operator+(p,p2);
	cout << p2 << endl;
	return 0;

}