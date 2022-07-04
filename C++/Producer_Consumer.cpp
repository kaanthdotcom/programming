#include <iostream>
#include <thread>
#include <mutex>

using namespace std;




int g_resource=0;
mutex inc;

void producer()
{
	for(int i=0; i<5; ++i)
	{
		inc.lock();
		++g_resource;
		cout << g_resource << endl;
		inc.unlock();
	}
}

void consumer()
{
	for(int i=0; i<5; ++i)
	{
		inc.lock();
		++g_resource;
		cout << g_resource << endl;
		inc.unlock();
	}
}

int main()
{
	thread t1{producer};
	thread t2{consumer};
	
	t1.join();
	t2.join();
	return 0;
}