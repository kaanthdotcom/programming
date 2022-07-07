//Guess the output

#include <iostream>
using namespace std;
int main(){
	int i=19;
	for(;i>0;--i){
		if((i & (i-1)) == 0) break;
	}
	cout << i;
	return 0;
}
