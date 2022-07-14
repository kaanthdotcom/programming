//std::move does not actually move anything; it just casts reference to values (rvalue references to rvalue). It just tells the compiler that the object is eligible to be moved from. Below is an implementation of move (not exactly how it was in std, but similar)

#include <iostream>

using namespace std;

//C++11
template<typename T>
typename remove_reference<T>::type&&
move(T&& param)
{
	using ReturnType = typename remove_reference<T>::type&&;
	return static_cast<ReturnType>(param);
}	

//C++14
template<typename T>
decltype(auto) move(T&& param)
{
	using ReturnType = typename remove_reference<T>::type&&;
	return static_cast<ReturnType>(param);
}

int main()
{
	
}