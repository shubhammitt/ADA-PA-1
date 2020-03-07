#include<bits/stdc++.h>
#define max_char 257 // total number of ACSII characters
using namespace std;
int frequency[max_char]; // store frequency of each ascii character
ifstream input;
ofstream encoded , mapping;
vector < pair < int , int > > fre_char; // stores freuency, ASCII character 
vector < int > prefix_sum; // for frequency
string prefix_code[max_char] = { }; // store mapping for each character

int find_partition( int l , int r )
{
	int opt = l;
	if( l == r )
		return opt;
	int opt_set_dif = fre_char[opt].first - ( prefix_sum[r] - prefix_sum[opt] );
	for( int i = l + 1 ; i < r ; i++ )
	{
		int set_diff = ( prefix_sum[i] - prefix_sum[l-1] ) - ( prefix_sum[r] - prefix_sum[i] );
		if( abs(set_diff) <= abs(opt_set_dif) )
		{
			opt_set_dif = set_diff;
			opt = i;
		}
	}
	return opt;
}

void make_mapping( int l , int r )
{
	if( l < r )
	{
		int m = find_partition(l , r);
		for( int i = l ; i <= m ; i++)
			prefix_code[fre_char[i].second] += "0";
		for( int i = m + 1 ; i <= r ; i++)
			prefix_code[fre_char[i].second] += "1";
		make_mapping( l , m );
		make_mapping( m + 1 , r );
	}
}
int main()
{
	input.open( "input.txt" );
	mapping.open( "mapping.txt" );
	encoded.open( "encoded.txt" );

	string s;
	getline(input,s);
	for( int i = 0 ; i < s.size() ; i++ )
		frequency[s[i]]++;

	fre_char.push_back({0,0}); // to make 1 index
	for( int i = 0 ; i < max_char ; i++ )
	{
		if(frequency[i] != 0)
			fre_char.push_back({frequency[i],i});
	}

	sort( fre_char.begin() + 1 , fre_char.end() );
	reverse( fre_char.begin() + 1 , fre_char.end() );

	prefix_sum.push_back(0);
	int n = fre_char.size() - 1;
	for( int i = 1 ; i <= n ; i++ )
		prefix_sum.push_back( prefix_sum.back() + fre_char[i].first );

	make_mapping( 1 , n );
	for( int i = 0 ; i < max_char ; i++ )
	{
		if( frequency[i] != 0 )
			mapping << (char)i << " " << prefix_code[i] << "\n";
	}

	for( int i = 0 ; i < s.size() ; i++ )
		encoded << prefix_code[s[i]];
}