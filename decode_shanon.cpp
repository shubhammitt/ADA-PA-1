#include<bits/stdc++.h>
using namespace std;
ifstream encoded , mapping;
ofstream decoded;
int main()
{
	decoded.open( "decoded.txt" );
	mapping.open( "mapping.txt" );
	encoded.open( "encoded.txt" );
	string l;
	map < string , string > character_map; // store mappings of ASCII characters
	while( getline(mapping , l) )
	{
		character_map[l.substr(2,l.size())] = l[0];
	}
	string in;
	getline(encoded,in);
	string s = "";
	for( int i = 0 ; i < in.size() ; i++ )
	{
		s = s + in[i];
		auto it = character_map.find(s);
		if( it != character_map.end() )
		{
			decoded<<it->second;
			s = "";
		}
	}
}
