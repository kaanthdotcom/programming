#include <iostream>
#include <bitset>

void approach_1(unsigned long val)
{
	std::bitset<10> b{val};
	std::string bs{b.to_string()};
	std::cout << "Binary representation of " << val << " is " << bs << std::endl;
	
	int dist{};
	for(int i=0; i<10;++i)
	{
		if(1 == i)
		{
			
		}
	}
}


//10001000001
void approach_2(unsigned long N)
{
	auto temp{N};
	int c{0}, p{1}, f{0}, z{0}, d{0};
	while(temp>0)
	{
		if(temp%2==1)
		{
			 if(f==0) f=1;
			 else f=0;
		}
		else
			++z;
		
		if(d<z)
		{
			d=z;
			z=0;
		}
		temp = temp / 2;
	}
	
	std::cout << std::endl << "dist: " << d << std::endl;
}


void approach_3(int N)
{
	int temp{N};
    int fo{0}, zc{0}, dist{0};

    while(temp>0)
    {
        if(temp%2 == 1 && fo==1)
		{
			fo=0;
			if(dist<zc) dist = zc;
			zc=0;
		}
		if(temp%2 == 1)
		{
			fo=1;
		}
		if(temp%2 == 0) ++zc;
		                
        temp = temp / 2;
    }
	std::cout << std::endl << "dist: " << dist << std::endl;
}
int main()
{
	std::cout << "Enter an integer value: ";
	unsigned long val;
	std::cin >> val;
	
	//approach_1(val);
	//approach_2(val);
	approach_3(val);
    
}