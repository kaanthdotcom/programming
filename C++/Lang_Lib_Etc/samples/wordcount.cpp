/*Write a program to read a text file.Store each word in a map.
The key value of the map is the count of the number of times the word appears in the text.
Define a word exclusion set containing words such as a, an, or , the, and, and but.
Before entering a word in the map, make sure it is not present in the word exclusion set.
Display the list of words and their associated count when the reading of the text is complete.
As an extension, before displaying the text, allow the user to query the text for the presence of a word.*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

int _main_()
{
	cout << "Enter filename: ";
	string str_filename;
	getline(cin, str_filename);

	//read file
	ifstream infile(str_filename);
	if (!infile)
	{
		cerr << "cannot open " << str_filename << endl;
		return 0;
	}
	
	//exclude and write to a map
	map<string, int> words;
	const set<string> exclusionset{ "a", "an", "or" , "the", "and", "but" };
	string word;
	for (; infile >> word;)
	{
		auto it = find(exclusionset.begin(), exclusionset.end(), word);
		if (it == exclusionset.end())
		{
			for (auto x : word)
				if (x == 'a') words[word] = 1;
			continue;
			words[word]++;
		}
	}
	for (auto i : words)
		cout << i.first << ":" << i.second << endl;

	//allow user to query
	cout << "Enter a word:";
	string inword;
	cin >> inword;
	auto itm = words.find(inword);
	if (itm != words.end()) cout << itm->first << ":" << itm->second << endl ;
	else cout << inword << " does not exist\n";
	
	infile.close();

	return 0;

}