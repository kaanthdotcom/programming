#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

struct phone_book
{
	string	contact_name;
	_int64	contact_num;
};


template<typename T>
_int64 getNumber(const string& s, const T& pb)
{
	if (s=="" ) throw exception("contact name cannot be empty");

	auto it = find_if(pb.begin(), pb.end(), [s](const phone_book& p) {return p.contact_name == s; });
	if (it != pb.end())
		return it->contact_num;
	
	return 0;
}
_int64 getNumber(const string& s, map<string, _int64>& m)
{
	return m[s];
}


template<typename T>
void print_contacts(const T& s)
{
	int num = 0;
	for_each(s.begin(), s.end(), [&num](const phone_book& b) {
		cout << b.contact_name << " : " << b.contact_num << endl;
		++num;
	});
	cout << "Total: " << num << endl;
}
void print_contacts(const map<string, _int64>& m)
{
	for (auto x : m)
	{
		cout << x.first << ":" << x.second << endl;
	}
}


int main_()
{
	//vector
	vector<phone_book> srikanth{ {"Sakhi",8500280854},{"Amma",9703455538},{"Naanna", 9393304491},{"Self", 9502203605} };
	srikanth.push_back({ "Akka",9948711886 });
	phone_book helpline{ "police",100 };
	srikanth.push_back(helpline);
	srikanth.pop_back();
	srikanth.push_back({ "Sravan",9959933315 });
	cout << "Srikanth's Phonebook : " << srikanth.size() << " contacts\n";
	print_contacts(srikanth);
	/*cout << "Enter the contact name:";
	string s;
	cin >> s;
	_int64 num = getNumber(s, srikanth);
	if (num > 0)
		cout << s << ": " << num << endl;
	else
		cout << s << " is not in the phonebook\n";*/
	
	//list
	list<phone_book> supriya{ {"Amul",8500280854},{"Atthaya",9703455538},{"Naanna", 9704181466},{"Self", 8500280854} };
	supriya.insert(supriya.begin(), { "maamayya",9393304491 });
	supriya.push_back(helpline);
	cout << "Supriya's Phonebook : " << supriya.size() << " contacts\n";
	print_contacts(supriya);
	supriya.erase(find_if(supriya.begin(), supriya.end(), [](const phone_book& b) {return b.contact_name=="police"; }));
	print_contacts(supriya);
	/*cout << "Enter the contact name:";
	string s;
	cin >> s;
	_int64 num = getNumber(s, supriya);
	if (num > 0)
		cout << s << ": " << num << endl;
	else
		cout << s << " is not in the phonebook\n";*/

	//map
	map<string,_int64> map_phonebook{ {"Sakhi",8500280854},{"Amma",9703455538},{"Naanna", 9393304491},{"Self", 9502203605} };
	cout << "Maps's Phonebook : " << map_phonebook.size() << " contacts\n";
	print_contacts(map_phonebook);
	cout << "Enter the contact name:";
	string s;
	cin >> s;
	_int64 num = getNumber(s, map_phonebook);
	if (num > 0)
		cout << s << ": " << num << endl;
	else
		cout << s << " is not in the phonebook\n";
	
	map<string, _int64> map_newbook{map_phonebook};
	//unique_copy(map_phonebook.begin(), map_phonebook.end(), map_newbook);
	cout << "Newbook's: " << map_newbook.size() << " contacts\n";
	print_contacts(map_newbook);
	return 0;
}