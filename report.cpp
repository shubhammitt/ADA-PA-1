#include<bits/stdc++.h>
#define max_char 257 // total number of ACSII characters
using namespace std;
int frequency[max_char];
string prefix_code[max_char] = { };
ifstream input, mapping;
void count_frequency()
{
	input.open("input.txt");
	string s;
	getline(input,s);
	for( int i = 0 ; i < s.size() ; i++ )
		frequency[s[i]]++;
}
void store_mapping()
{

	mapping.open("mapping.txt");
	string l;
	while( getline(mapping , l) )
	{
		prefix_code[l[0]] = l.substr(2, l.size());
	}
	mapping.close();
}
int analyse()
{
	store_mapping();
	int access_time = 0;
	for( int i = 0 ; i < max_char ; i++ )
	{
		access_time += frequency[i] * prefix_code[i].size();
		prefix_code[i] = ""; //resetting
	}
	return access_time;
}
int main () 
{
	count_frequency();
	system("make huffman");
	int huffman_access_time = analyse();

	system("make Shanon");
	int Shanon_access_time = analyse();

	cout << "\033[0;32m" << "Huffman access time = " << huffman_access_time << "\n";
	cout << "Shanon access time  = " << Shanon_access_time << "\n";
	cout << "Difference = " << Shanon_access_time - huffman_access_time <<"\033[0m\n";
	system("make clean");
	return 0; 
}