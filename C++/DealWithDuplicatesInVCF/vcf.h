#include "VCARD.h"
#include "vcfline.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class VCF
{
	vector<sree::vcfline> raw_vcf_data;
	vector<VCARD> vcards;
	string ver{};
	long len{-1};
	static VCF* _theobj;
	static bool bIsValid;
	string _infile;
	string _outfile;
	ifstream _ifs_in;
	ofstream _ofs_out;

	VCF(const string& infile, string outfile);
	bool validate();
	bool open();
	bool load();
	bool vcf_to_vcards();
	bool trim_vcards(vector<sree::vcfline>& vc);

	VCF& operator=(const VCF& rhs) = delete;
	VCF(const VCF& rhs) = delete;

public:
	static VCF* create(const string& infile, string outfile);
	string version(){return ver;}
	long length();
};