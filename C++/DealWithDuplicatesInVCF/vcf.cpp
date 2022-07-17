#include "vcf.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

VCF* VCF::_theobj = nullptr;
bool VCF::bIsValid = true;

VCF* VCF::create(const string& filename, string outfilename)
{
	if (_theobj == nullptr)
	{
		_theobj = new VCF(filename, outfilename);
		if (bIsValid == false)
		{
			delete _theobj;
			_theobj = nullptr;
		}
	}

	return _theobj;
}

VCF::VCF(const string& filename, string outfilename):_infile{ filename }, _outfile{ outfilename }
{
	cout <<"input file is " << _infile << endl;
	cout << "output file is " << _outfile << endl;	
	
	if (validate() == false)
	{
		bIsValid = false;
	}
}

//load vcf file. return FALSE if not found.
bool VCF::open()
{
	_ifs_in.open(_infile);
	if (_ifs_in.fail())
	{
		cout << "failed to open " << _infile << endl;
		_ifs_in.close();
		return false;
	}

	cout << "found " << _infile << " and is now opened for reading" << endl;
	return true;
}

bool VCF::validate()
{
	if (open() == false)
		return false;
	
	if (load() == false)
		return false;

	vcf_to_vcards();
	
	len = raw_vcf_data.size();
	return true;
}

bool VCF::load()
{
	istream_iterator<sree::vcfline> iis{ _ifs_in };
	istream_iterator<sree::vcfline> eos{};

	copy_if(iis, eos, back_inserter(raw_vcf_data), [](sree::vcfline temp)
		{
			return(
				temp.beginswith("N:") || 
				temp.beginswith("FN:") || 
				temp.beginswith("TEL;") || 
				temp.beginswith("item1.TEL;") || 
				temp.beginswith("item1.TEL;") || 
				temp.beginswith("EMAIL;")
				);
		});
	return true;
}

bool VCF::vcf_to_vcards()
{
	
	return true;
}

/*
* 
*/
bool VCF::trim_vcards(vector<sree::vcfline>& vc)
{

	return true;
}


long VCF::length()
{
	if (false == bIsValid)
	{
		//calling public methods via an invalid object will yield unexpected behavior. However, a message is still useful.
		cerr << _infile << " is not a valid VCF file" << endl;
		return -1;
	}
	return len;
}