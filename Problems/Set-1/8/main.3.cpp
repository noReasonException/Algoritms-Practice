#include<iostream>
#include <math.h>
#include <set>
using namespace std;

/**
 *
 *	Assumptions
 * 		1. It might be a tie between occurences of numbers, in that case we need every number	
 *		2. -10^2<=a<=10^2
 */ 

//Idea, lookuptable of size 2 * 10^2 
//shift everything with offset +-10^2
void solve(){
	int len,tmp,ind;
	int lookup_table[2000] = {0};
	int maxOcc = -1;
	cin>>len;
	while(len--){
		cin>>tmp;
		ind = tmp+1000;
		lookup_table[ind]+=1;
		if(lookup_table[ind]>maxOcc) maxOcc = lookup_table[ind];
	}
	cout<<"Elements with max occurences ...\n";
	for(int i=0;i<2000;i++){
		if(lookup_table[i]==maxOcc)cout<<i-1000<<"\n";
	}
	cout<<"\n";
	cout<<"Times x"<<maxOcc;
	cout<<"\n";
}

int main(){
	solve();
	
}