#include<bits/stdc++.h>
using namespace std;
ifstream encoded , mapping;
ofstream decoded;
int main()
{
	decoded.open( "decoded.txt" );
	mapping.open( "mapping.txt" );
	encoded.open( "encoded.txt" );
	char ch ; string pre_code ;
	map < string , char > character_map;
	while( mapping >> ch >> pre_code )
	{
		character_map[pre_code] = ch;
	}
	string in;
	getline(encoded,in);
	string s;
	cout << in.size();
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
