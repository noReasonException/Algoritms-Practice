#include<iostream>
#include <math.h>
#include <set>
#define ANY 0
using namespace std;

/**
 *
 *	Assumptions
 * 		1. It might be a tie between occurences of numbers, in that case we need every number	
 */ 


/**
 * Slow implementation
 * 	O(nlog(n)) as
 * 		1. External while n
 * 		2. set.erase, set.insert, set.find with logaritmic complexity when used with key (look cmp lambda)
 * 		3. .end() , .start() constant complexity
 */ 
void solve(){
	int len,tmp;
	set<pair<int,int>>::iterator found;
	auto cmp = [](pair<int,int> a,pair<int,int>b){return a.first>b.first;};
	set< pair<int,int>, decltype(cmp) > s(cmp);
	cin>>len;
	pair<int,int> curr(ANY,ANY);
	int maxOcc = -1;
	while(len--){
		cin>>tmp;
		found=s.find(pair<int,int>(tmp,ANY));

		if(found!=s.end()){ //there is occurence before

			curr = *found;
			curr.second+=1;
			if(maxOcc<curr.second) maxOcc = curr.second;
			s.erase(found);
			s.insert(curr);
			//remove
			//add by one
			//insert again
		}
		else{
			curr=pair<int,int>(tmp,1);
			if(maxOcc<curr.second) maxOcc = curr.second;
			s.insert(curr);
			//just insert
		}
	}
	cout<<"Elements with max occurences ...\n";
	for(auto &i:s){
		if(i.second==maxOcc) cout<<i.first;
	}
	cout<<"\n";
	cout<<"Times x"<<maxOcc;
	cout<<"\n";
}

int main(){
	solve();
	
}