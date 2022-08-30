#include <iostream>

using namespace std;

class Base
{
	void private_show(){cout << "Base::private_show()\n";}
public:
	void public_show(){cout << "Base::public_show()\n";}
};

class Derived : public Base{};

int main_dynamic_cast()
{
	Base *pb = new Base;
	//shared_ptr<Base> pb = make_shared<Base>();
	//Derived *pd  = dynamic_cast<Derived*>(pb);//error: the base class must have at least one virtual method, uses RTTI, happens at run-tume
	Derived *pd1 = (Derived*)pb;//this raw-cast can happen even if pb and pd1 are unrelated
	Derived *pd2 = static_cast<Derived*>(pb);//OK: happens at compile-time
	
	cout << typeid(Derived).name() << endl;
	cout << typeid(Base).name() << endl;
	
	return 0;
}