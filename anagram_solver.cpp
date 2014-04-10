#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;
/* Group together anagrams*/
int anagram_solver(string str)
{
	unordered_multimap<string,string> mmap;
	string mystr;
	int count = 0;

	for( int i = 0; i < str.length();i++)
	{
		if( str.c_str()[i] != ' ')
		{
			if(count == 0)
				mystr = str.c_str()[i];
			else
				mystr += str.c_str()[i];
			count++;
		}
		else
		{
			if(count == 0)
				continue;
			string copy_str = mystr;
			std::sort(copy_str.begin(),copy_str.end());
			mmap.insert(make_pair<string,string>(copy_str,mystr));
			count = 0;
			
		}
	
	}
	if( mystr.length() != 0)
	{
			string copy_str = mystr;
			std::sort(copy_str.begin(),copy_str.end());
			mmap.insert(make_pair<string,string>(copy_str,mystr));
	}


	
	
		for( auto mmap_it = mmap.begin(); mmap_it != mmap.end(); mmap_it++)
		{
			cout<<(*mmap_it).second<<" ";
		}
		cout<<endl;
	

	return 0;
}

int main(int argc,char* argv[])
{
	if( argc != 2)
	{
		cout<<"File name required as argument"<<endl;
		return -1;
	}

	fstream file;
	file.open(argv[1],ios::in);
	char line[500];

	while(!file.eof())
	{
		file.getline(line,500);
		if( strlen(line) == 0)
			continue;
		anagram_solver(string(line));
	}

	return 0;
	
}