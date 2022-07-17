#include <string>
#include <iostream>
#include <cstdarg>
#include <vector>
#include <algorithm>

using namespace std;

//to facilitate reading as a "line" instead of a "word" from istream types.
namespace sree
{
	class vcfline {
		string data;
		vector<VCARD> vcards;
	public:
		friend istream& operator>>(istream& is, vcfline& l)
		{
			static int i{};
			getline(is, l.data);
			while (l.data != "END:VCARD")
			{
				if (l.data.rfind("FN:") == 0)
				{
					l.vcards[i].FN= l.data;
				}
				
				getline(is, l.data);
			}
			return is;
		}
		operator string() const { return data; }
		bool beginswith(string p){ return data.rfind(p, 0) == 0 ? true : false; }
	};
}