#include <iostream>

class Something
{
private:
	int topSecretV=42;
};

class SomethingReplica
{
public:
	int topSecretV;
};

int main_reinterpret_cast()
{
	Something a;
	SomethingReplica *b = reinterpret_cast<SomethingReplica*>(&a);
	std::cout << b->topSecretV << std::endl;
	
	return 0;
}