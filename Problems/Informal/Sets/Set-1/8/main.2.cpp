#include<iostream>
#include <math.h>
#include <set>
#define ANY 0
using namespace std;

/**
 *
 *	Assumptions
 * 		1. It might be a tie between occurences of numbers, in that case we need every number	
 *		2. a<=10^2
 */ 


/**
 * 	a<=10^2, therefore we use a lookup table, let lookup_table
 * 	the n'th element a stores its occurences on lookup_table[a]
 * 
 * 
 * Fast implementation
 *	O(n) as follows
 * 	external while : n
 * 		internal lookups : array lookup with index : constant
 * 
 */ 
void solve(){
	int len,tmp;
	int lookup_table[1000] = {0};
	int maxOcc = -1;
	cin>>len;
	while(len--){
		cin>>tmp;
		lookup_table[tmp]+=1;
		if(lookup_table[tmp]>maxOcc) maxOcc = lookup_table[tmp];
	}
	cout<<"Elements with max occurences ...\n";
	for(int i=0;i<1000;i++){
		if(lookup_table[i]==maxOcc)cout<<i<<"\n";
	}
	cout<<"\n";
	cout<<"Times x"<<maxOcc;
	cout<<"\n";
}

int main(){
	solve();
	
}