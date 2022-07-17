#include <iostream>
#include <string>
#include "vcf.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Invalid usage" << endl;
		return 1;
	}
	string infile(argv[1], find(argv[1], argv[1] + strlen(argv[1]), '\0'));
	string outfile(argv[1], find(argv[1], argv[1] + strlen(argv[1]), '\0'));
	
	VCF* vcf = VCF::create(infile, outfile);
	cout << vcf->length() << endl;

	if (vcf == nullptr)
	{
		cout << "Invalid vcf file format" << endl;
		cout << "Program will now exit" << endl;
		return 1;
	}

	cout << vcf->length() << endl;
}