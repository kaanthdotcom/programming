#include <iostream>
#include <vector>


using namespace std;

vector<int> solution(vector<int> &A, int K);

int main()
{
	auto res = solution(vector<int>{},42);
	for(int i : res) cout << i <<",";
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)

	if(K == A.size() || 0==A.size()) return A;

	if(K>A.size()) K = K % A.size();
	
    vector<int> temp{A};
    int j=K;

    for(auto i : A)
    {
        temp[j++] = i;
        if(j>=A.size()) j=0;

    }
    return temp;
}