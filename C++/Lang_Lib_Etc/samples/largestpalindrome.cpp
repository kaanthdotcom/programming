/*
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1/
Given a string S, find the longest palindromic substring in S.
Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
Incase of conflict, return the substring which occurs first ( with the least starting index).

my approach:
1. first and last are two indexes
2. if first == last, the whole set in between will be reverse to see if that makes a palindrome
3. if it is, then the length will be taken as the minimum distance for the next first-last movement
4. if it is not, then first will advance by 1 and last will stop when first==last
*/

#include <iostream>
#include <string>

using namespace std;

int largest_palindrome(const string& str)
{
	int len{};
	int first{}, last{2};

	while (last != str.size())
	{
		if (str[first] == str[first+1]) len = 1;
		
		if ((last - first > len) && (str[first] == str[last]))
		{
			int tempfirst{ first}, templast{ last};
			while (str[++tempfirst] == str[--templast])
			{
				if (tempfirst == templast)
				{
					len = last - first;
					break;
				}
			}
		}
	}
	return len;
}

int main_largestpalindrome()
{
	string str{"forgeeksskeegfor"};
	cout << largest_palindrome(str);
    
	return 0;
}
