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
};

struct cmp{
	bool operator()(struct node* a, struct node* b){
		return a->fq >= b->fq;
	}
};

struct node* getNode(int ch, int freq, struct node* l, struct node* r){
	struct node* nd = new node();
	nd->c = ch;
	nd->fq = freq;
	nd->left = l;
	nd->right = r;
}

priority_queue<struct node*, vector<struct node*>, cmp> q;

void make_mapping(struct node* nd, string code){
	if(nd->c != '\0'){
		prefix_code[nd->c] = code;
 	}
 	else{
 		make_mapping(nd->left, code + "0");
		make_mapping(nd->right, code + "1");	
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
			q.push(getNode(i, frequency[i], nullptr, nullptr));
	}

	while(q.size() > 1){
		struct node* left = q.top();
		q.pop();
		struct node* right = q.top();
		q.pop();
		struct node* combined = getNode('\0', left->fq + right->fq, left, right);
		q.push(combined);
	}

	struct node* nd = q.top(); q.pop();
	make_mapping(nd, "");

	for( int i = 0 ; i < max_char ; i++ )
	{
		if( frequency[i] != 0 )
			mapping << (char)i << " " << prefix_code[i] << "\n";
	}

	for( int i = 0 ; i < s.size() ; i++ )
		encoded << prefix_code[s[i]];
}
