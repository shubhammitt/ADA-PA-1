#include<bits/stdc++.h>
#define max_char 257 // total number of ACSII characters
using namespace std;
int frequency[max_char]; // store frequency of each ascii character
ifstream input;
ofstream encoded , mapping; 
string prefix_code[max_char] = { }; // store mapping for each character

struct node{
	int fq;
	char c;
	struct node* left;
	struct node* right;

	node(char my_c, int my_fq){
		c = my_c;
		fq = my_fq;
		left = NULL;
		right = NULL;
	}

	node(struct node* l, struct node* r){
		fq = l->fq + r->fq;
		c = 0;
		left = l;
		right = r;
	}
};

struct cmp{
	bool operator()(node a, node b){
		return a.fq <= b.fq;
	}
};

priority_queue<node, vector<node>, cmp> q;

void make_mapping(struct node nd, string code){
	if(nd.c != 0){
		prefix_code[nd.c] = code;
 	}
 	else{
 		make_mapping(*(nd.left), code + "0");
		make_mapping(*(nd.right), code + "1");	
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

	for( int i = 0 ; i < max_char ; i++ )
	{
		if(frequency[i] != 0)
			q.push(node(i, frequency[i]));
	}

	while(q.size() > 1){
		struct node left = q.top();
		q.pop();
		struct node right = q.top();
		q.pop();
		struct node combined = node(&left, &right);
		q.push(combined);
	}

	struct node nd = q.top(); q.pop();
	make_mapping(nd, "");

	for( int i = 0 ; i < max_char ; i++ )
	{
		if( frequency[i] != 0 )
			mapping << (char)i << " " << prefix_code[i] << "\n";
	}

	for( int i = 0 ; i < s.size() ; i++ )
		encoded << prefix_code[s[i]];
}