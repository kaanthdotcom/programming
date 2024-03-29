#include <iostream>

using namespace std;

class Complex
{
	int real;
	int img;
public:
	Complex();
	Complex(int, int);
	void Accept();
	void Display();
	Complex operator+(Complex&);
	Complex operator-(Complex&);
	Complex operator++();
	Complex operator++(int);
	bool operator==(Complex&);
};

//Default Constructor  Will initialize real and img to values 0
Complex::Complex() :real{ 0 }, img{ 0 }
{

}

//Parameterized Constructor  Will initialize real and img to values passed inside constructor
Complex::Complex(int r, int i) :real{ r }, img{ i }
{

}

//Accept function  Will accept the Complex number from user
void Complex::Accept()
{
	cout << "Enter real number: ";
	cin >> real;
	cout << "Enter imaginary number: ";
	cin >> img;
}

//Display function  Will display the Complex number into a+bi format
void Complex::Display()
{
	cout << real << "+" << img << "i" << endl;
}

//Operator+ will perform addition of two Complex objects.
Complex Complex::operator+(Complex& rhs)
{
	Complex res(this->real + rhs.real, this->img + rhs.img);
	return res;
}

//Operator- will perform subtraction of two Complex objects.
Complex Complex::operator-(Complex& rhs)
{
	Complex res(this->real - rhs.real, this->img - rhs.img);
	return res;
}

//++pre  will add 1 to the real and img parts of Complex number
Complex Complex::operator++()
{
	this->real += 1;
	this->img += 1;
	return *this;
}

//++post  will add 1 to the real and img parts of Complex number
Complex Complex::operator++(int d)
{
	Complex old = *this;
	++(this->real);
	++(this->img);
	return old;
}

//== operator will compare two complex objects are same. i.e. their corresponding real and imaginary parts are same.
bool Complex::operator==(Complex& rhs)
{
	if ((this->real == rhs.real) && (this->img == rhs.img))
		return true;
	return false;
}

int main_complex()
{
	Complex a{8,5};
	Complex b{ a };
	b++;
	
	a.Display();
	b.Display();
	(a + b).Display();

	return 0;
}