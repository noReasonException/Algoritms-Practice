#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm> 
using namespace std;

int refl(int index,int size){
	int half = size%2?((size-1)/2):(size/2);
	if(index<half) return size-1-index;
	else return half-(index-half)-(!(size%2));
}
int charToPos(char c){
	return c-'a';
}

void printVector(std::vector<char> v){
	for(char a:v){
		cout<<a;
	}
	cout<<"\n";
}

void solve(){
	int size;
	string s;
	int exist[26] = {0};
	int ind;
	
	cin>>size;
	cin>>s;

	vector<char>r;
	vector<char>result;

	//build 'exists' map, r string, O(n) 
	for(int i=0;i<s.size();i++){
		ind = charToPos(s[i]);
		if(!exist[ind]){
			r.push_back(s[i]);
		}
		exist[ind] = 1;
	}
	//nlogn
	std::sort(r.begin(),r.end());
	//O(n) worst case (every letter dinstinct)
	for(int i=0;i<r.size();i++){
		//get nth char
		//find refl
		//write to map
		exist[charToPos(r[i])] = r[refl(i,r.size())];
	}
	//O(n) always
	for(int i=0;i<s.size();i++){
		result.push_back(exist[charToPos(s[i])]);
	}

	printVector(result);

}

int main(){
	int size;
	cin>>size;
	while(size--) solve();
	cout<<"\n";
}